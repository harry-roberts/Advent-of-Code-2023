#ifndef AOC_DAY4
#define AOC_DAY4

#include "day_base.h"

namespace d4
{

class Day4 : public DayBaseImpl<>
{
public:
    Day4(const std::string&, bool print = true);
    
private:
    int parseLine(std::string_view line);

    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    std::vector<int> m_lineMatches;
};

} //namespace d4

#endif
