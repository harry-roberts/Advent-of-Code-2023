#ifndef AOC_DAY4
#define AOC_DAY4

#include "day_base.h"

class Day4 : public DayBase
{
public:
    Day4(const std::string&, bool print = true);

    void solveDay(bool print = true);
    
private:
    int parseLine(std::string_view line);

    int solvePartOne();
    int solvePartTwo();

    std::vector<int> m_lineMatches;
};

#endif
