#ifndef AOC_DAY8
#define AOC_DAY8

#include "day_base.h"

#include <unordered_map>
#include <memory>

namespace d8
{

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

class Day8 : public DayBaseImpl<>
{
public:
    Day8(const std::string&, bool print = true);
    
private:
    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    void parseInput();

    // maps a node name to its node ptr
    std::unordered_map<std::string, std::shared_ptr<Node>> m_nodeMap;
};

} //namespace d8

#endif
