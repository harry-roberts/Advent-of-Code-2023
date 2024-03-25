#include "day1.h"

Day1::Day1(const std::string& filename, bool print)
{
    readInputToStringVec(filename, print);
}

Day1::Part1Type Day1::solvePartOne()
{
    return solve();
}

Day1::Part2Type Day1::solvePartTwo()
{
    return solve(true);
}

Day1::Part1Type Day1::solve(bool includeWords)
{
    int total = 0;

    for (const auto& str : m_inputLines)
    {
        int len = str.length();
        std::string numStr;
        std::vector<std::string> possibleDigits;
        std::string_view sv = str;

        // find the first number
        bool foundFirst = false;
        for (int i = 0; i < len; i++)
        {
            if (isdigit(str[i]))
            {
                numStr += str[i];
                break;
            }

            if (!includeWords)
                continue;

            for (int d = 1; d <= 9; d++)
            {
                if (sv.substr(i).starts_with(digitWords.at(d-1)))
                {
                    numStr += std::to_string(d);
                    foundFirst = true;
                    break;
                }
            }
            if (foundFirst)
                break;
        }

        // find the second number
        bool foundSecond = false;
        for (int i = len-1; i >=0; i--)
        {
            if (isdigit(str[i]))
            {
                numStr += str[i];
                break;
            }

            if (!includeWords)
                continue;

            for (int d = 1; d <= 9; d++)
            {
                if (sv.substr(i).starts_with(digitWords.at(d-1)))
                {
                    numStr += std::to_string(d);
                    foundSecond = true;
                    break;
                }
            }
            if (foundSecond)
                break;
        }

        int numInt = stoi(numStr);
        total += numInt;
    }

    return total;
}
