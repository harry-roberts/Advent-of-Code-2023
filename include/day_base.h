#ifndef AOC_DAY_BASE
#define AOC_DAY_BASE

#include <string>
#include <vector>
#include <iostream>

class DayBase
{
public:

    virtual void solveDay(bool print = true) = 0;
    virtual ~DayBase() = default;

protected:
    virtual void readInput(std::string filename, bool print = true);

    std::vector<std::string> m_inputLines;
};

#endif
