#ifndef AOC_DAY_BASE
#define AOC_DAY_BASE

#include <string>
#include <vector>
#include <iostream>

class DayBase
{
public:

    virtual void solveDay() = 0;
    virtual ~DayBase() = default;

protected:
    virtual void readInput(std::string filename);

    std::vector<std::string> m_inputLines;
};

#endif
