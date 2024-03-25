#ifndef AOC_DAY2
#define AOC_DAY2

#include "day_base.h"

#include <map>

struct Handful
{
    int red = 0;
    int green = 0;
    int blue = 0;
};

class Day2 : public DayBaseImpl<int, int>
{
public:
    Day2(const std::string& filename, bool print = true);
    
private:
    void parseInput();

    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;
    
    using Game = std::vector<Handful>;
    std::vector<Game> m_games;
};

#endif
