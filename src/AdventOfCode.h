#ifndef AOC_ADVENTOFCODE
#define AOC_ADVENTOFCODE

#include "day_base.h"

#include <vector>
#include <memory>

class AdventOfCode
{
public:
    AdventOfCode();

    void solveDay(size_t day);
    void solveAllDays();
private:
    std::vector<std::unique_ptr<DayBase>> m_allDays;
};

#endif
