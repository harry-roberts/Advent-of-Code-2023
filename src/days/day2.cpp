#include "day2.h"

#include <boost/algorithm/string.hpp>
#include <algorithm>

Day2::Day2(std::string filename)
{
    readInput(filename);
}

void Day2::parseInput()
{
    for (const auto& line : m_inputLines)
    {
        std::vector<std::string> gameHandfuls;
        boost::split(gameHandfuls, line.substr(line.find(':')+1), boost::is_any_of(";"));

        Game game;

        for (const auto& handfulStr : gameHandfuls)
        {
            std::vector<std::string> handfulColours;
            boost::split(handfulColours, handfulStr, boost::is_any_of(","));

            Handful handful;
            for (auto& colourInfo : handfulColours)
            {
                boost::algorithm::trim(colourInfo);
                auto spacePos = colourInfo.find(' ');
                handful[colourInfo.substr(spacePos+1)] += std::stoi(colourInfo.substr(0, spacePos));
            }
            game.push_back(handful);
        }
        m_games.push_back(game);
    }
}

void Day2::solveDay()
{
    parseInput();
    std::cout << "Day 2 Part 1: " << solvePartOne() << std::endl;
    std::cout << "Day 2 Part 2: " << solvePartTwo() << std::endl;
}

int Day2::solvePartOne()
{
    int totalSum = 0;

    for (size_t i = 0; i < m_games.size(); i++)
    {
        bool isGameValid = true;
        for (auto& handful : m_games.at(i))
        {
            if (handful["red"] > m_maxColours.at("red") ||
                handful["green"] > m_maxColours.at("green") ||
                handful["blue"] > m_maxColours.at("blue"))
            {
                isGameValid = false;
                break;
            }
        }
        if (isGameValid)
            totalSum += (i+1);
    }

    return totalSum;
}

int Day2::solvePartTwo()
{
    int totalPower = 0;
    for (auto& game : m_games)
    {
        int maxRed = 0;
        int maxGreen = 0;
        int maxBlue = 0;

        for (auto& handful : game)
        {
            if (handful["red"] > maxRed)
                maxRed = handful["red"];
            if (handful["green"] > maxGreen)
                maxGreen = handful["green"];
            if (handful["blue"] > maxBlue)
                maxBlue = handful["blue"];
        }

        totalPower += (maxRed * maxGreen * maxBlue);
    }

    return totalPower;
}
