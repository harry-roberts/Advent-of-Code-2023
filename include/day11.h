#ifndef AOC_DAY11
#define AOC_DAY11

#include "day_base.h"

namespace d11
{

// x,y location of galaxy
using GalaxyPos = std::pair<size_t, size_t>;
// number of empty cols, rows before a galaxy's pos
using EmptyBefore = std::pair<size_t, size_t>;
// this is all the needed information about a galaxy
using GalaxyInfo = std::pair<GalaxyPos, EmptyBefore>;

class Day11 : public DayBaseImpl<>
{
public:
    Day11(const std::string&, bool print = true);

private:
    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    // parse the input into the info of all galaxies and the empty rows
    void readGalaxyInfo();
    // calculate the sum of min distances given an expansion factor
    uint64_t calculateSumMinDistances(uint64_t expansionFactor);

    std::vector<GalaxyInfo> m_galaxies;
};

} //namespace d11

#endif
