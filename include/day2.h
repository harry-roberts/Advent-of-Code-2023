#ifndef AOC_DAY2
#define AOC_DAY2

#include "day_base.h"

#include <map>

class Day2 : public DayBase
{
public:
    Day2(std::string filename);

    void solveDay();
    
private:
    void parseInput();

    int solvePartOne();
    int solvePartTwo();

    using Handful = std::map<std::string, int>;
    using Game = std::vector<Handful>;
    std::vector<Game> m_games;

    const std::map<std::string, int> m_maxColours{
        {"red", 12},
        {"green", 13},
        {"blue", 14}
    };

};

#endif
