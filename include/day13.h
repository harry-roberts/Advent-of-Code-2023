#ifndef AOC_DAY13
#define AOC_DAY13

#include "day_base.h"

namespace d13
{

class Day13 : public DayBaseImpl<>
{
public:
    Day13(const std::string& filename, bool print = true);
    
private:
    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    size_t findColsLeftVerticalLine(std::vector<std::string> pattern, 
                                    bool allowSmudge = false);
    size_t findRowsAboveHozitontalLine(std::vector<std::string> pattern,
                                       bool allowSmudge = false);

    void parseInput();
    using Pattern = std::vector<std::string>;
    std::vector<Pattern> m_patterns;
};

} //namespace d13

#endif