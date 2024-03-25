#ifndef AOC_DAY6
#define AOC_DAY6

#include "day_base.h"

#include <map>

class Day6 : public DayBaseImpl<>
{
public:
    Day6(const std::string&, bool print = true);
    
private:
    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    void parseInput();
    uint64_t solveNumWaysToWin(uint64_t T, uint64_t target);

    std::vector<uint64_t> m_inputTimes;
    std::vector<uint64_t> m_inputDistances;

    // time and distance for a race
    std::vector<std::pair<uint64_t, uint64_t>> m_races;
};

#endif
