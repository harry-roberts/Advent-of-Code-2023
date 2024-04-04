#ifndef AOC_DAY12
#define AOC_DAY12

#include "day_base.h"

#include <memory>
#include <mutex>
#include <bitset>

namespace d12
{

struct DfaNode
{
    std::bitset<3> movements; // bitset of whether a movement is possible
    uint64_t headsHere = 0; // number of current chain heads at this node
    uint64_t incoming = 0; // incremented by any input that adds heads here
};

// enum for index into the movement bitset
enum class Movements : uint8_t
{
    DotAdvance,  // a dot as an input should advance the node
    HashAdvance, // a hash as an input should advance the node
    DotLoops     // a dot links a node to itself
};

class DfaChain
{
public:
    DfaChain(const std::vector<size_t>& groups);

    uint64_t solve(std::string_view records);

private:
    std::vector<DfaNode> m_dfaChain;
};


class Day12 : public DayBaseImpl<>
{
public:
    Day12(const std::string& filename, int numThreads, bool print = true);
    
private:
    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    void parseInput();
    void runPartTwo(); // for a thread to pick up

    int m_numThreads;

    // turn each input line into a pair of records and groups
    std::vector<std::pair<std::string_view, std::vector<size_t>>> m_parsedInput;

    // a mutex and the 2 vars it should protect
    std::mutex m_inputMutex;
    size_t m_nextInput = 0;
    uint64_t m_answer = 0;
};

} //namespace d12

#endif
