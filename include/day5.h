#ifndef AOC_DAY5
#define AOC_DAY5

#include "day_base.h"

#include <map>

using NumType = uint64_t;

// the data from the input lines
struct Range
{
    NumType sourceStart;
    NumType destStart;
    NumType length;

    bool operator<(const Range& rhs)
    {
        return sourceStart < rhs.sourceStart;
    }
};

// source/dest name pair to a vector of Ranges, e.g. ("seed", "soil") -> [r1, r2, r3...]
using Inputs = std::map<std::pair<std::string, std::string>, std::vector<Range>>;

class Day5 : public DayBase
{
public:
    Day5(std::string filename);

    void solveDay();
    
private:
    int solvePartOne();
    int solvePartTwo();
    void parseInput();

    int solve(std::vector<Range>& inputVec);

    // given a vector of ranges, see what ranges they map to in the search vector of ranges
    std::vector<Range> getMappedRanges(std::vector<Range>& input, std::vector<Range>& search);

    std::vector<NumType> m_seedNums;
    Inputs m_inputs;
};

#endif
