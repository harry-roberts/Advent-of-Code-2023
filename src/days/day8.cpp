#include "day8.h"

#include <numeric>

namespace d8
{

Day8::Day8(const std::string& filename, bool print)
{
    readInputToStringVec(filename, print);
}

void Day8::parseInput()
{
    m_nodeMap.reserve(m_inputLines.size()-2);

    // create empty nodes for each one that appears in the list
    for (size_t i = 2; i < m_inputLines.size(); i++)
    {
        std::string_view sv{m_inputLines[i]};
        std::string nodeName{sv.substr(0, 3)};
        m_nodeMap[nodeName] = std::make_shared<Node>(nodeName);
    }

    // point the left/right pointers to the corresponding nodes
    for (size_t i = 2; i < m_inputLines.size(); i++)
    {
        std::string_view sv{m_inputLines[i]};
        std::string nodeName{sv.substr(0, 3)};
        std::string nodeLeftName{sv.substr(7, 3)};
        std::string nodeRightName{sv.substr(12, 3)};

        // find the nodes in the set and set the left and right
        auto node = m_nodeMap[nodeName];
        auto nodeLeft = m_nodeMap[nodeLeftName];
        auto nodeRight = m_nodeMap[nodeRightName];
        node->left = nodeLeft;
        node->right = nodeRight;
    }
}

Day8::Part1Type Day8::solvePartOne()
{
    parseInput();
    uint64_t steps = 0;

    auto currentNode = m_nodeMap["AAA"];
    while (currentNode->name != "ZZZ")
    {
        for (const auto direction : m_inputLines[0])
        {
            if (direction == 'L') currentNode = currentNode->left;
            else currentNode = currentNode->right;
            steps++;
            if (currentNode->name == "ZZZ") break;
        }
    }

    return steps;
}

Day8::Part2Type Day8::solvePartTwo()
{
    std::vector<std::shared_ptr<Node>> allNodes; // any node ending in 'A'
    std::vector<uint64_t> stepsRequired; // steps needed to be on a node ending in 'Z'
    // find all the nodes that end in A and add to vec
    for (const auto& [name, node] : m_nodeMap)
        if (name[2] == 'A') allNodes.push_back(node);

    // same as step 1 for each required node but only checking for last char
    for (auto& node : allNodes)
    {
        int steps = 0;
        while (node->name[2] != 'Z')
        {
            for (const auto direction : m_inputLines[0])
            {
                if (direction == 'L') node = node->left;
                else node = node->right;
                steps++;
                if (node->name[2] == 'Z') break;
            }
        }
        stepsRequired.push_back(steps);
    }

    // we know how many steps it takes for each of the starting nodes to finish
    // they will all finish at the same time at their lowest common multiple
    uint64_t lcm = 1;
    for (size_t i = 0; i < stepsRequired.size(); i++)
        lcm = std::lcm(lcm, stepsRequired[i]);

    return lcm;
}

} //namespace d8
