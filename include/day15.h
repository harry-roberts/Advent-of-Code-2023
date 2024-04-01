#ifndef AOC_DAY15
#define AOC_DAY15

#include "day_base.h"

namespace d15
{

class Day15 : public DayBaseImpl<>
{
public:
    Day15(const std::string& filename, bool print = true);
    
private:
    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    void parseInput();
    uint8_t hashString(std::string_view s);

    std::vector<std::string_view> m_seqSteps;
};

} //namespace d15

#endif