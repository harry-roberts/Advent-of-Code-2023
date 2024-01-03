#include "day8.h"

#include <numeric>

Day8::Day8(std::string filename)
{
    readInput(filename);
}

void Day8::solveDay()
{
    parseInput();
    std::cout << "Day 8 Part 1: " << solvePartOne() << std::endl;
    std::cout << "Day 8 Part 2: " << solvePartTwo() << std::endl;
}

void Day8::parseInput()
{
    for (size_t i = 2; i < m_inputLines.size(); i++)
    {
        std::string_view sv{m_inputLines.at(i)};
        std::string node{sv.substr(0, 3)};
        std::string leftNode{sv.substr(7, 3)};
        std::string rightNode{sv.substr(12, 3)};

        m_nodeMap[node] = {leftNode, rightNode};
    }
}

uint64_t Day8::solvePartOne()
{
    uint64_t steps = 0;
    std::string currentNode = "AAA";
    while (currentNode != "ZZZ")
    {
        for (const auto direction : m_inputLines.at(0))
        {
            auto possibleNodes = m_nodeMap[currentNode];
            if (direction == 'L') currentNode = possibleNodes.first;
            else currentNode = possibleNodes.second;
            steps++;
            if (currentNode == "ZZZ") break;
        }
    }
    return steps;
}

uint64_t Day8::solvePartTwo()
{
    std::vector<std::string> allNodes; // any node ending in 'A'
    std::vector<uint64_t> stepsRequired; // steps needed to be on a node ending in 'Z'
    // find all the nodes that end in A and add to vec
    for (const auto& [node, directionPair] : m_nodeMap)
        if (node.at(2) == 'A') allNodes.push_back(node);

    // same as step 1 for each required node but only checking for last char
    for (auto& node : allNodes)
    {
        int steps = 0;
        while (node.at(2) != 'Z')
        {
            for (const auto direction : m_inputLines.at(0))
            {
                auto possibleNodes = m_nodeMap[node];
                if (direction == 'L') node = possibleNodes.first;
                else node = possibleNodes.second;
                steps++;
                if (node.at(2) == 'Z') break;
            }
        }
        stepsRequired.push_back(steps);
    }

    // we know how many steps it takes for each of the starting nodes to finish
    // they will all finish at the same time at their lowest common multiple
    uint64_t lcm = 1;
    for (size_t i = 0; i < stepsRequired.size(); i++)
        lcm = std::lcm(lcm, stepsRequired.at(i));

    return lcm;
}
