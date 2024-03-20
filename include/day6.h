#ifndef AOC_DAY6
#define AOC_DAY6

#include "day_base.h"

#include <map>

class Day6 : public DayBase
{
public:
    Day6(const std::string&, bool print = true);

    void solveDay(bool print = true);
    
private:
    uint64_t solvePartOne();
    uint64_t solvePartTwo();

    void parseInput();
    uint64_t solveNumWaysToWin(uint64_t T, uint64_t target);

    std::vector<uint64_t> m_inputTimes;
    std::vector<uint64_t> m_inputDistances;

    // time and distance for a race
    std::vector<std::pair<uint64_t, uint64_t>> m_races;
};

#endif
