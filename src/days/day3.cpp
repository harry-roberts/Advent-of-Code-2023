#include "day3.h"

namespace d3
{

Day3::Day3(const std::string& filename, bool print)
{
    readInputToStringVec(filename, print);
}

// parse input into:
//      map of coordinates to part numbers (coordinate can be first digit)
//      map of coordinates to symbols (anything not a digit, not '.')
void Day3::parseInput()
{
    for (size_t y = 0; y < m_inputLines.size(); y++)
    {
        std::string_view line = m_inputLines[y];
        bool isReadingNumber = false;
        int number = 0;
        size_t coordx = 0;
        size_t coordy = 0;
        for (size_t x = 0; x < line.size(); x++)
        {
            char c = line[x];
            if (isdigit(c))
            {
                if (isReadingNumber) // already reading a number from before
                {
                    number *= 10;
                    number += c - '0';
                }
                else // first digit of a new number
                {
                    number = c - '0';
                    isReadingNumber = true;
                    coordx = x; // use the first digit as the saved coordinate
                    coordy = y;
                }
                if (x == (line.size()-1)) // last char in line
                {
                    Coordinate partCoord{coordx, coordy};
                    m_partNumbers[partCoord] = number;
                    isReadingNumber = false;
                }
                continue;
            }
            else if (isReadingNumber) // not a digit but the previous was - number stops
            {
                Coordinate partCoord{coordx, coordy};
                m_partNumbers[partCoord] = number;
                isReadingNumber = false;
            }
        }
    }
}

Day3::Part1Type Day3::solvePartOne()
{
    parseInput();
    int validPartNumberSum = 0;
    // for each part number, check to see if the coordinates around it exist in the symbol map
    for (auto& [coord, number] : m_partNumbers)
    {
        // find number of digits in the number
        int num = number;
        int numDigits = 1;
        while (num /= 10)
            numDigits++;
        // check around the number +-1 in x and y
        for (int x = coord.first-1; x <= coord.first+numDigits; x++)
        {
            for (int y = coord.second-1; y <= coord.second+1; y++)
            {
                if (x < 0 || y < 0 || (size_t)x >= m_inputLines[0].size() || 
                    (size_t)y >= m_inputLines.size())
                    continue;
                Coordinate current{x, y};
                if (m_inputLines[y][x] != '.' && !isdigit(m_inputLines[y][x]))
                {
                    validPartNumberSum += number;
                    // also checking for part 2 here since we are already iterating it
                    if (m_inputLines[y][x] == '*')
                        m_gearsToNumbers[current].push_back(number);
                }
            }
        }
    }
    return validPartNumberSum;
}

Day3::Part2Type Day3::solvePartTwo()
{
    int gearRatioSum = 0;
    // in part 1 we also added any part number touching a gear into a map of all gears
    // can now just filter this map for gears with 2 part numbers
    for (const auto& [gearCoord, partNumberVec] : m_gearsToNumbers)
    {
        if (partNumberVec.size() == 2)
        {
            gearRatioSum += partNumberVec[0] * partNumberVec[1];
        }
    }
    return gearRatioSum;
}

} //namespace d3
