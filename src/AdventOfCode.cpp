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
#include "day14.h"
#include "day15.h"
#include "day16.h"

#include <chrono>

AdventOfCode::AdventOfCode()
{
    m_allDays.push_back(std::make_unique<d1::Day1>("inputs/input_day1.txt"));
    m_allDays.push_back(std::make_unique<d2::Day2>("inputs/input_day2.txt"));
    m_allDays.push_back(std::make_unique<d3::Day3>("inputs/input_day3.txt"));
    m_allDays.push_back(std::make_unique<d4::Day4>("inputs/input_day4.txt"));
    m_allDays.push_back(std::make_unique<d5::Day5>("inputs/input_day5.txt"));
    m_allDays.push_back(std::make_unique<d6::Day6>("inputs/input_day6.txt"));
    m_allDays.push_back(std::make_unique<d7::Day7>("inputs/input_day7.txt"));
    m_allDays.push_back(std::make_unique<d8::Day8>("inputs/input_day8.txt"));
    m_allDays.push_back(std::make_unique<d9::Day9>("inputs/input_day9.txt"));
    m_allDays.push_back(std::make_unique<d10::Day10>("inputs/input_day10.txt"));
    m_allDays.push_back(std::make_unique<d11::Day11>("inputs/input_day11.txt"));
    m_allDays.push_back(std::make_unique<d12::Day12>("inputs/input_day12.txt", 8)); // 8 threads
    m_allDays.push_back(std::make_unique<d13::Day13>("inputs/input_day13.txt"));
    m_allDays.push_back(std::make_unique<d14::Day14>("inputs/input_day14.txt"));
    m_allDays.push_back(std::make_unique<d15::Day15>("inputs/input_day15.txt"));
    m_allDays.push_back(std::make_unique<d16::Day16>("inputs/input_day16.txt"));
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
