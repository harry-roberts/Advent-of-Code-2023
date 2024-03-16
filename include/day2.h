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

class Day2 : public DayBase
{
public:
    Day2(std::string filename, bool print = true);

    void solveDay(bool print = true);
    
private:
    void parseInput();

    int solvePartOne();
    int solvePartTwo();

    using Game = std::vector<Handful>;
    std::vector<Game> m_games;
};

#endif
