#ifndef AOC_DAY9
#define AOC_DAY9

#include "day_base.h"

class Day9 : public DayBase
{
public:
    Day9(std::string filename, bool print = true);

    void solveDay(bool print = true);
    
private:
    std::vector<int> parseLine(std::string_view line);
    int solvePartOne();
    int solvePartTwo();

    std::vector<std::vector<int>> m_firstNumsVec;
};

#endif
