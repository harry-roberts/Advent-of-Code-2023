#include "AdventOfCode.h"

#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"
#include "day7.h"
#include "day8.h"
#include "day9.h"
#include "day10.h"

#include <chrono>
#include <cassert>

AdventOfCode::AdventOfCode()
{
    m_allDays.push_back(new Day1("inputs/input_day1.txt"));
    m_allDays.push_back(new Day2("inputs/input_day2.txt"));
    m_allDays.push_back(new Day3("inputs/input_day3.txt"));
    m_allDays.push_back(new Day4("inputs/input_day4.txt"));
    m_allDays.push_back(new Day5("inputs/input_day5.txt"));
    m_allDays.push_back(new Day6("inputs/input_day6.txt"));
    m_allDays.push_back(new Day7("inputs/input_day7.txt"));
    m_allDays.push_back(new Day8("inputs/input_day8.txt"));
    m_allDays.push_back(new Day9("inputs/input_day9.txt"));
    m_allDays.push_back(new Day10("inputs/input_day10.txt"));
}

void AdventOfCode::solveDay(size_t day)
{
    assert(day <= m_allDays.size() && day > 0);
    std::cout << "-------------------------" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    m_allDays.at(day-1)->solveDay();
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " microseconds" << std::endl;
}

void AdventOfCode::solveAllDays()
{
    for (size_t i = 1; i <= m_allDays.size(); i++)
    {
        solveDay(i);
    }
}
