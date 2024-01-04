#ifndef AOC_DAY8
#define AOC_DAY8

#include "day_base.h"

#include <unordered_map>

class Day8 : public DayBase
{
public:
    Day8(std::string filename, bool print = true);

    void solveDay(bool print = true);
    
private:
    uint64_t solvePartOne();
    uint64_t solvePartTwo();

    void parseInput();

    // maps a node to a pair of left/right nodes
    std::unordered_map<std::string, std::pair<std::string, std::string>> m_nodeMap;
};

#endif
