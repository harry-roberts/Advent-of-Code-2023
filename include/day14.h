#ifndef AOC_DAY14
#define AOC_DAY14

#include "day_base.h"

#include <unordered_map>
#include <boost/container_hash/hash.hpp>

namespace d14
{

class Day14 : public DayBaseImpl<>
{
public:
    Day14(const std::string& filename, bool print = true);
    
private:
    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    void setup();
    uint64_t calculateNorthLoad();
    
    uint32_t tiltInputNorth(uint32_t cycle);
    uint32_t tiltInputSouth(uint32_t cycle);
    uint32_t tiltInputEast(uint32_t cycle);
    uint32_t tiltInputWest(uint32_t cycle);

    size_t getNewCycle(size_t previous, size_t current);

    // a vector of ints describing the positions with round rocks
    // a positions is a single int, rowsize*rownum + colnum
    using Snapshot = std::vector<uint16_t>;
    // map a position snapshot to a cycle number
    using SnapshotMap = std::unordered_map<Snapshot, 
                                           uint32_t, 
                                           boost::hash<std::vector<uint16_t>>>;

    // have a map after each possible action
    SnapshotMap m_northSnapshots;
    SnapshotMap m_westSnapshots;
    SnapshotMap m_southSnapshots;
    SnapshotMap m_eastSnapshots;

    size_t m_roundRockCount = 0;
    size_t m_rowSize = 0;
};

} //namespace d14

#endif