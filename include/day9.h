#ifndef AOC_DAY9
#define AOC_DAY9

#include "day_base.h"

class Day9 : public DayBaseImpl<>
{
public:
    Day9(const std::string&, bool print = true);
    
private:
    std::vector<int> parseLine(std::string_view line);
    
    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    std::vector<std::vector<int>> m_firstNumsVec;
};

#endif
