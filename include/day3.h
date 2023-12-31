#ifndef AOC_DAY3
#define AOC_DAY3

#include "day_base.h"

#include <map>

using Coordinate = std::pair<int, int>;

class Day3 : public DayBase
{
public:
    Day3(std::string filename);

    void solveDay();
    
private:
    void parseInput();

    int solvePartOne();
    int64_t solvePartTwo();

    std::map<Coordinate, int> m_partNumbers;
    std::map<Coordinate, char> m_symbols;

    std::map<Coordinate, std::vector<int>> m_gearsToNumbers;

};

#endif