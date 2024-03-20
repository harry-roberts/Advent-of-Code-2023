#ifndef AOC_DAY1
#define AOC_DAY1

#include "day_base.h"

class Day1 : public DayBase
{
public:
    Day1(const std::string& filename, bool print = true);

    void solveDay(bool print = true);
    
private:
    int solve(bool includeWords = false);

    int solvePartOne();
    int solvePartTwo();

    const std::vector<std::string> digitWords{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

};

#endif