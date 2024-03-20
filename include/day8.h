#ifndef AOC_DAY8
#define AOC_DAY8

#include "day_base.h"

#include <unordered_map>
#include <memory>

struct Node
{
    std::string name;
    mutable std::shared_ptr<Node> left = nullptr;
    mutable std::shared_ptr<Node> right = nullptr;

    Node(std::string_view name_) : name(name_) {}

    bool operator==(const Node& b) const 
    { 
        return name == b.name; 
    }

    bool operator!=(const Node& b)
    {
        return !operator==(b);
    }
};

class Day8 : public DayBase
{
public:
    Day8(const std::string&, bool print = true);

    void solveDay(bool print = true);
    
private:
    uint64_t solvePartOne();
    uint64_t solvePartTwo();

    void parseInput();

    // maps a node name to its node ptr
    std::unordered_map<std::string, std::shared_ptr<Node>> m_nodeMap;
};

#endif
