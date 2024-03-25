#ifndef AOC_DAY3
#define AOC_DAY3

#include "day_base.h"

#include <map>

using Coordinate = std::pair<int, int>;

class Day3 : public DayBaseImpl<>
{
public:
    Day3(const std::string&, bool print = true);
    
private:
    void parseInput();

    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    std::map<Coordinate, int> m_partNumbers;
    std::map<Coordinate, std::vector<int>> m_gearsToNumbers;
};

#endif