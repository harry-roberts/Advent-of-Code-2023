#include "day9.h"

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

#include <numeric>

Day9::Day9(const std::string& filename, bool print)
{
    readInput(filename, print);
}

void Day9::solveDay(bool print)
{
    if (print)
    {
        std::cout << "Day 9 Part 1: " << solvePartOne() << std::endl;
        std::cout << "Day 9 Part 2: " << solvePartTwo() << std::endl;
    }
    else
    {
        solvePartOne();
        solvePartTwo();
    }
}

std::vector<int> Day9::parseLine(std::string_view line)
{
    std::vector<int> rtn;
    rtn.reserve(21); // every input line has 21 digits
    boost::char_separator<char> sep(" ");
    boost::tokenizer<boost::char_separator<char>> nums(line, sep);

    for (const auto& n : nums)
        rtn.push_back(std::atoi(n.c_str()));

    return rtn;
}

// given a line, calculate the line of differences
std::vector<int> calculateNextLine(std::vector<int>& line)
{
    // it will have 1 less number than the line we are looking at
    std::vector<int> nextLine(line.size()-1);

    for (size_t i = 0; i < line.size()-1; i++)
        nextLine[i] = line[(i+1)] - line[i]; 

    return nextLine;
}

bool isLineAllSameNumber(std::vector<int>& line)
{
    // don't need to get the all zero line, the line before will have all the same values
    int firstNum = line[0];
    for (size_t i = 1; i < line.size(); i++)
        if (line[i] != firstNum) return false;

    return true;
}

int Day9::solvePartOne()
{
    int totalSumOfLastNums = 0;
    m_firstNumsVec.reserve(m_inputLines.size());
    for (auto& line : m_inputLines)
    {
        std::vector<int> lineVec = parseLine(line);
        // final numbers in each line - used in calculating new last number
        std::vector<int> lastNums;
        std::vector<int> firstNums;
        // worst case these vectors will have as many elements as the line
        lastNums.reserve(lineVec.size());
        firstNums.reserve(lineVec.size());
        lastNums.push_back(lineVec.back());
        firstNums.push_back(lineVec.front()); // for part 2

        bool allSame = false;
        while (!allSame)
        {
            lineVec = calculateNextLine(lineVec);
            lastNums.push_back(lineVec.back());
            firstNums.push_back(lineVec.front()); // for part 2
            if (isLineAllSameNumber(lineVec))
                allSame = true;
        }
        // sum the lastNums vec to get the final (first line) last number
        totalSumOfLastNums += std::reduce(lastNums.begin(), lastNums.end());
        m_firstNumsVec.push_back(firstNums);
    }
    return totalSumOfLastNums;
}

int Day9::solvePartTwo()
{
    int totalSumOfFirstNums = 0;
    for (const auto& firstNums : m_firstNumsVec)
    {
        // keep a running sum and subtract each new first number
        int currentNum = 0;
        for (auto it = firstNums.rbegin(); it != firstNums.rend(); ++it)
            currentNum = *it - currentNum;

        totalSumOfFirstNums += currentNum;
    }
    return totalSumOfFirstNums;
}
