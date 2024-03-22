#ifndef AOC_DAY12
#define AOC_DAY12

#include "day_base.h"

#include <memory>

struct DfaNode;
using DfaNodePtr = std::shared_ptr<DfaNode>;

struct DfaNode
{
    DfaNodePtr inputDot = nullptr; // move to this node if the input is a dot
    DfaNodePtr inputHash = nullptr; // move to this node is the input is a hash
    uint64_t headsHere = 0; // number of current chain heads at this node
    uint64_t incoming = 0; // incremented by any input that adds heads here
};

class DfaChain
{
public:
    DfaChain(const std::vector<size_t>& groups);

    uint64_t solve(std::string_view records);

private:
    std::vector<DfaNodePtr> m_dfaChain;
};


class Day12 : public DayBase
{
public:
    Day12(const std::string& filename, bool print = true);

    void solveDay(bool print = true);
    void parseInput();
    
private:
    uint64_t solvePartOne();
    uint64_t solvePartTwo();

    // turn each input line into a pair of records and groups
    std::vector<std::pair<std::string_view, std::vector<size_t>>> m_parsedInput;
};

#endif
