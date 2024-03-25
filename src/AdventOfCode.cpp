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
#include "day11.h"
#include "day12.h"
#include "day13.h"

#include <chrono>

AdventOfCode::AdventOfCode()
{
    m_allDays.push_back(std::make_unique<Day1>("inputs/input_day1.txt"));
    m_allDays.push_back(std::make_unique<Day2>("inputs/input_day2.txt"));
    m_allDays.push_back(std::make_unique<Day3>("inputs/input_day3.txt"));
    m_allDays.push_back(std::make_unique<Day4>("inputs/input_day4.txt"));
    m_allDays.push_back(std::make_unique<Day5>("inputs/input_day5.txt"));
    m_allDays.push_back(std::make_unique<Day6>("inputs/input_day6.txt"));
    m_allDays.push_back(std::make_unique<Day7>("inputs/input_day7.txt"));
    m_allDays.push_back(std::make_unique<Day8>("inputs/input_day8.txt"));
    m_allDays.push_back(std::make_unique<Day9>("inputs/input_day9.txt"));
    m_allDays.push_back(std::make_unique<Day10>("inputs/input_day10.txt"));
    m_allDays.push_back(std::make_unique<Day11>("inputs/input_day11.txt"));
    m_allDays.push_back(std::make_unique<Day12>("inputs/input_day12.txt"));
    m_allDays.push_back(std::make_unique<Day13>("inputs/input_day13.txt"));
}

void AdventOfCode::solveDay(size_t day)
{
    assert(day <= m_allDays.size() && day > 0);
    std::cout << "-------------------------" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    m_allDays[day-1]->solveDay();
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Day " << day << " solution:" << "\n";
    m_allDays[day-1]->print();
    std::cout << "Time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() 
              << " microseconds\n";
}

void AdventOfCode::solveAllDays()
{
    for (size_t i = 1; i <= m_allDays.size(); i++)
    {
        solveDay(i);
    }
}
