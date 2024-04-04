#include "day12.h"

#include <boost/tokenizer.hpp>

#include <numeric>
#include <thread>

namespace d12
{

Day12::Day12(const std::string& filename, int numThreads, bool print) :
    m_numThreads(numThreads)
{
    readInputToStringVec(filename, print);
}

// define a DFA that validates an input against the defined groups
//
// each node has 3 possible movements it can make based on an input:
//    - a dot can link back to itself
//    - a dot can advance to the next node
//    - a hash can advance to the next node
// if an input doesn't have one of these movements to do, then the head ends
//
// for e.g. groups of 1,2 the chain looks like:
//
//    ). = dot linking to itself
//    |./# = advancement to next node for that input
//    [node] = a node that any number of heads can be sitting at
//
//   start  [node] ).   dot links to itself at start
//             |#       then a hash moves forward
//          [node]      no definition for hash at this node
//             |.       because after 1 hash given, a dot is required
//          [node] ).   now a dot can link to itself
//             |#       but when given a hash, move to next node
//          [node]      no dot defined here, it needs its second hash
//             |#       second hash advances to next node
//          [node] ).   now completed last group, dot links to itself
//                      no hash defined as we have finished the given groups
//
// each node has a counter of how many heads are currently there
// start with 1 head at the start node
// move as required for each character in the record
// for a '?', split the head into 2 and follow as if both '.' and '#' had arrived
// this creates more heads as the record inputs are given to the chain
// heads are removed when they have no input action at their node
// after all record inputs have been given, check how many heads are at the end node
// this is the number of ways that the record could have ended up being a valid pattern

DfaChain::DfaChain(const std::vector<size_t>& groups)
{
    // init chain with one node for each hash, plus one node after each hash
    // the node after is either a required dot to advance, or a dot linking to itself at the end
    // the start node will either be hash into first group hash, or dot to itself
    // the end node will be the final hash, with dot into itself
    size_t numNodes = std::reduce(groups.begin(), groups.end()) + groups.size();
    m_dfaChain.reserve(numNodes);
    for (size_t i = 0; i < numNodes; i++)
        m_dfaChain.push_back(DfaNode{});
    
    // move through the chain
    size_t chainPos = 0;
    for (const auto groupSize : groups)
    {
        // for first in group a dot goes to itself, there can be any number of dots before any group
        m_dfaChain[chainPos].movements[(uint8_t)Movements::DotLoops] = true;
        // each group is then a subchain of hashes, with a dot at the end (unless the final hash)
        for (size_t i = 0; i < groupSize; i++)
        {
            m_dfaChain[chainPos].movements[(uint8_t)Movements::HashAdvance] = true;
            chainPos++;
        }
        if (chainPos != numNodes-1) // if not the final node
        {
            // require a dot moving forward
            // not needed at end as the final node links to itself for optional dots
            m_dfaChain[chainPos].movements[(uint8_t)Movements::DotAdvance] = true;
            chainPos++;
        }
    }
    // link the final node to itself by dot, there can be any number of dots after the final group
    m_dfaChain[chainPos].movements[(uint8_t)Movements::DotLoops] = true;
}

uint64_t DfaChain::solve(std::string_view records)
{
    m_dfaChain[0].headsHere = 1; // starting point

    size_t maxNodePos = 0;

    for (const auto c : records)
    {
        // apply the character as an input to every head at each node in the chain
        // a head can *at best* move forward one node each input
        // so only check up to our max possible current node pos to save some iterations
        for (size_t i = 0; i <= maxNodePos; i++)
        {
            if (m_dfaChain[i].headsHere > 0)
            {
                // a question mark should trigger both options
                if (c == '.' || c == '?')
                {
                    if (m_dfaChain[i].movements[(uint8_t)Movements::DotAdvance])
                        m_dfaChain[i+1].incoming += m_dfaChain[i].headsHere;
                    else if (m_dfaChain[i].movements[(uint8_t)Movements::DotLoops])
                        m_dfaChain[i].incoming += m_dfaChain[i].headsHere;
                }
                if (c == '#' || c == '?')
                {
                    if (m_dfaChain[i].movements[(uint8_t)Movements::HashAdvance])
                        m_dfaChain[i+1].incoming += m_dfaChain[i].headsHere;
                }
            }
        }
        // all heads now advanced, now set heads to the incoming value, reset incoming to 0
        // can also use maxNodePos here, checking 1 ahead, but limited to chain size
        for (size_t i = 0; i <= std::min(maxNodePos+1, m_dfaChain.size()-1); i++)
        {
            m_dfaChain[i].headsHere = m_dfaChain[i].incoming;
            m_dfaChain[i].incoming = 0;
        }
        if (maxNodePos < m_dfaChain.size()-1) 
            maxNodePos++; // if not already at final pos, increment max node pos
    }

    return m_dfaChain.back().headsHere; // all heads at the end node
}

void Day12::parseInput()
{
    for (const auto& line : m_inputLines)
    {
        std::string_view sv{line};
        size_t space = sv.find_first_of(' ');
        std::string_view recordStr = sv.substr(0, space);
        std::string_view groupsStr = sv.substr(space+1);

        boost::char_separator<char> sep(",");
        boost::tokenizer<boost::char_separator<char>> groups(groupsStr, sep);

        std::vector<size_t> groupsVec;
        for (const auto& g : groups)
        {
            groupsVec.push_back(std::atoi(g.c_str()));
        }

        m_parsedInput.push_back(std::make_pair<std::string_view, std::vector<size_t>>(
            std::move(recordStr), std::move(groupsVec)));
    }
}

// a thread can run this function and pick up new inputs to solve
void Day12::runPartTwo()
{
    std::pair<std::string_view, std::vector<size_t>> input;
    uint64_t ans = 0;

    while (true)
    {
        // lock the mutex and get the next input
        // but first add previously calculated ans to save an extra mutex acquisition
        {
            const std::lock_guard<std::mutex> lock(m_inputMutex);
            m_answer += ans;
            if (m_nextInput == m_parsedInput.size()) break;
            input = m_parsedInput[m_nextInput];
            m_nextInput++;
        }
        // we have a copy of the input, free the mutex and solve it

        std::string newRecords{input.first};
        newRecords.reserve((input.first.size()*5) + 4);
        for (size_t i = 0; i < 4; i++)
        {
            newRecords += "?";
            newRecords += input.first;
        }

        size_t sz = input.second.size();
        input.second.reserve(sz*5);

        for (size_t i = 0; i < 4; i++) // add the group to itself 4 more times
            std::copy_n(input.second.begin(), sz, std::back_inserter(input.second));

        DfaChain dfa(input.second);
        ans = dfa.solve(newRecords);
        // ans will be added when we next get the lock
    }
}

Day12::Part1Type Day12::solvePartOne()
{
    parseInput();
    uint64_t ans = 0;

    for (const auto& input : m_parsedInput)
    {
        DfaChain dfa(input.second);
        ans += dfa.solve(input.first);
    }

    return ans;
}

Day12::Part2Type Day12::solvePartTwo()
{
    m_answer = 0;

    { // thread scope
        std::vector<std::jthread> threads;
        threads.reserve(m_numThreads);

        // start up threads, each running runPartTwo
        for (int i = 0; i < m_numThreads; ++i) 
            threads.push_back(std::jthread(&Day12::runPartTwo, this));
    }

    return m_answer;
}

} //namespace d12
