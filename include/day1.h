#ifndef AOC_DAY1
#define AOC_DAY1

#include "day_base.h"

namespace d1
{

class Day1 : public DayBaseImpl<>
{
public:
    Day1(const std::string& filename, bool print = true);
    
private:
    Part1Type solve(bool includeWords = false);

    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    const std::vector<std::string> digitWords{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

};

} //namespace d1

#endif