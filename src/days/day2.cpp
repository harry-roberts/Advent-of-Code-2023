#include "day2.h"

#include <boost/algorithm/string.hpp>
#include <algorithm>

Day2::Day2(const std::string& filename, bool print)
{
    readInputToStringVec(filename, print);
}

void Day2::parseInput()
{
    for (const auto& line : m_inputLines)
    {
        std::vector<std::string> gameHandfuls;
        // split into handfuls e.g. " 15 blue, 12 red, 2 green"
        boost::split(gameHandfuls, line.substr(line.find(':')+1), boost::is_any_of(";"));

        Game game;

        for (const auto& handfulStr : gameHandfuls)
        {
            std::vector<std::string> handfulColours;
            // split to just the colour info e.g. " 15 blue"
            boost::split(handfulColours, handfulStr, boost::is_any_of(","));

            Handful handful;
            for (auto& colourInfo : handfulColours)
            {
                boost::algorithm::trim(colourInfo);
                auto spacePos = colourInfo.find(' ');
                std::string colour = colourInfo.substr(spacePos+1);
                if (colour == "red") handful.red = std::stoi(colourInfo.substr(0, spacePos));
                if (colour == "green") handful.green = std::stoi(colourInfo.substr(0, spacePos));
                if (colour == "blue") handful.blue = std::stoi(colourInfo.substr(0, spacePos));
            }
            game.push_back(handful);
        }
        m_games.push_back(game);
    }
}

Day2::Part1Type Day2::solvePartOne()
{
    parseInput();
    int totalSum = 0;

    for (size_t i = 0; i < m_games.size(); i++)
    {
        bool isGameValid = true;
        for (auto& handful : m_games[i])
        {
            if (handful.red > 12 || handful.green > 13 || handful.blue > 14)
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

Day2::Part2Type Day2::solvePartTwo()
{
    int totalPower = 0;
    for (auto& game : m_games)
    {
        int maxRed = 0;
        int maxGreen = 0;
        int maxBlue = 0;

        for (auto& handful : game)
        {
            if (handful.red > maxRed)
                maxRed = handful.red;
            if (handful.green > maxGreen)
                maxGreen = handful.green;
            if (handful.blue > maxBlue)
                maxBlue = handful.blue;
        }

        totalPower += (maxRed * maxGreen * maxBlue);
    }

    return totalPower;
}
