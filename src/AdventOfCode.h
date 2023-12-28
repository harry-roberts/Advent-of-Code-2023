#ifndef AOC_ADVENTOFCODE
#define AOC_ADVENTOFCODE

#include "day_base.h"

#include <vector>

class AdventOfCode
{
public:
    AdventOfCode();

    void solveDay(size_t day);
    void solveAllDays();
private:
    std::vector<DayBase*> m_allDays;
};

#endif
