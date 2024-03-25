#ifndef AOC_DAY10
#define AOC_DAY10

#include "day_base.h"

#include <unordered_map>

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

// a tile allows two directions
using Tile = std::pair<Direction, Direction>;
// position on the map
using Coord = std::pair<size_t, size_t>;
// a position paired with where it came from to get there
using Traversal = std::pair<Coord, Direction>;

class Day10 : public DayBaseImpl<>
{
public:
    Day10(const std::string&, bool print = true);

private:
    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    char findEffectiveS(const size_t sX, const size_t sY);
    bool canGoAbove(const size_t sX, const size_t sY);
    bool canGoBelow(const size_t sX, const size_t sY);
    bool canGoLeft(const size_t sX, const size_t sY);
    bool canGoRight(const size_t sX, const size_t sY);

    // return the direction the tile exits given where we entered from
    Direction exitDirection(const Coord& tilePos, const Direction cameFrom);
    // move the position in the required direciton, updating it
    void move(Traversal& pos);

    // favour up->down->left->right
    const std::unordered_map<char, Tile> m_tileMap{
        {'|', Tile{Direction::UP, Direction::DOWN}},
        {'-', Tile{Direction::LEFT, Direction::RIGHT}},
        {'L', Tile{Direction::UP, Direction::RIGHT}},
        {'J', Tile{Direction::UP, Direction::LEFT}},
        {'7', Tile{Direction::DOWN, Direction::LEFT}},
        {'F', Tile{Direction::DOWN, Direction::RIGHT}},
        {'.', Tile{Direction::NONE, Direction::NONE}}
    };

    // make a copy of the input but only add the chars that make up the loop
    std::vector<std::string> m_inputCopy;
};

#endif
