#include "day7.h"

#include <boost/algorithm/string.hpp>

Day7::Day7(std::string filename)
{
    readInput(filename);
}

void Day7::solveDay()
{
    std::cout << "Day 7 Part 1: " << solvePartOne() << std::endl;
    std::cout << "Day 7 Part 2: " << solvePartTwo() << std::endl;
}

// maps a card to a relative ranking, bigger number beats smaller number
const std::unordered_map<char, int> Hand::CardRankingMap{
        {'2', 0}, {'3', 1}, {'4', 2}, {'5', 3}, {'6', 4}, {'7', 5}, {'8', 6}, 
        {'9', 7}, {'T', 8}, {'J', 9}, {'Q', 10},{'K', 11}, {'A', 12}};

int Day7::solvePartOne()
{
    // read every line into a hand, then add to a vector and sort at the end
    for (const auto& line : m_inputLines)
    {
        std::vector<std::string> handStrs;
        boost::split(handStrs, line, boost::is_any_of(" "));
        Hand h(handStrs.at(0), stoi(handStrs.at(1)));
        m_allHands.push_back(h);
    }
    sort(m_allHands.begin(), m_allHands.end());

    uint64_t totalSum = 0;
    for (size_t i = 0; i < m_allHands.size(); i++)
        totalSum += (i+1)*(m_allHands.at(i).bid);

    return totalSum;
}

int Day7::solvePartTwo()
{
    std::vector<Hand> wildHands;
    for (const auto& h : m_allHands)
    {
        Hand wildHand(std::string(h.cards, HAND_SIZE), h.bid, true);
        wildHands.push_back(wildHand);
    }
    sort(wildHands.begin(), wildHands.end());

    uint64_t totalSum = 0;
    for (size_t i = 0; i < wildHands.size(); i++)
        totalSum += (i+1)*(wildHands.at(i).bid);

    return totalSum;
}