#include "day10.h"

#include <cassert>
#include <cmath>

Day10::Day10(std::string filename, bool print)
{
    readInput(filename, print);
}

void Day10::solveDay(bool print)
{
    // pre allocate the same size as the input for the copy and set all to '.'
    std::string s(m_inputLines.at(0).size(), '.');
    m_inputCopy = std::vector<std::string>(m_inputLines.size(), s);
    if (print)
    {
        std::cout << "Day 10 Part 1: " << solvePartOne() << std::endl;
        std::cout << "Day 10 Part 2: " << solvePartTwo() << std::endl;
    }
    else
    {
        solvePartOne();
        solvePartTwo();
    }
}

bool Day10::canGoAbove(const size_t sX, const size_t sY)
{
    if (sY == 0) return false;
    char c = m_inputLines[sY-1][sX];
    Tile above{m_tileMap.at(c)};
    if (above.first == Direction::DOWN || above.second == Direction::DOWN)
        return true;
    return false;
}
bool Day10::canGoBelow(const size_t sX, const size_t sY)
{
    if (sY == m_inputLines.size()-1) return false;
    char c = m_inputLines[sY+1][sX];
    Tile below{m_tileMap.at(c)};
    if (below.first == Direction::UP || below.second == Direction::UP)
        return true;
    return false;
}
bool Day10::canGoLeft(const size_t sX, const size_t sY)
{
    if (sX == 0) return false;
    char c = m_inputLines[sY][sX-1];
    Tile left{m_tileMap.at(c)};
    if (left.first == Direction::RIGHT || left.second == Direction::RIGHT)
        return true;
    return false;
}
bool Day10::canGoRight(const size_t sX, const size_t sY)
{
    if (sX == m_inputLines.at(0).size()-1) return false;
    char c = m_inputLines[sY][sX+1];
    Tile right{m_tileMap.at(c)};
    if (right.first == Direction::LEFT || right.second == Direction::LEFT)
        return true;
    return false;
}

char Day10::findEffectiveS(const size_t sX, const size_t sY)
{
    std::vector<Direction> dirs;
    // the map favours up->down->left->right so check in this order
    if (canGoAbove(sX, sY)) dirs.push_back(Direction::UP);
    if (canGoBelow(sX, sY)) dirs.push_back(Direction::DOWN);
    if (canGoLeft(sX, sY)) dirs.push_back(Direction::LEFT);
    if (canGoRight(sX, sY)) dirs.push_back(Direction::RIGHT);
    assert(dirs.size() == 2);
    for (const auto& [c, t] : m_tileMap)
        if (t == Tile{dirs.at(0), dirs.at(1)}) return c;
    return '.';
}

Direction Day10::exitDirection(const Coord& tilePos, const Direction cameFrom)
{
    Tile t = m_tileMap.at(m_inputLines[tilePos.second][tilePos.first]);
    if (t.first != cameFrom) return t.first;
    if (t.second != cameFrom) return t.second;
    return Direction::NONE;
}

void Day10::move(Traversal& pos)
{
    Direction exit = exitDirection(pos.first, pos.second);
    assert(exit != Direction::NONE);
    m_inputCopy.at(pos.first.second).at(pos.first.first) = 
        m_inputLines.at(pos.first.second).at(pos.first.first); // for part 2
    if (exit == Direction::RIGHT) // move x++
    {
        pos.first.first++;
        pos.second = Direction::LEFT;
    }
    else if (exit == Direction::LEFT) // move x--
    {
        pos.first.first--;
        pos.second = Direction::RIGHT;
    }
    else if (exit == Direction::DOWN) // move y++
    {
        pos.first.second++;
        pos.second = Direction::UP;
    }
    else if (exit == Direction::UP) // move y--
    {
        pos.first.second--;
        pos.second = Direction::DOWN;
    }
}

int Day10::solvePartOne()
{
    // find the location of the S character
    size_t sX = 0;
    size_t sY = 0;
    for (size_t i = 0; i < m_inputLines.size(); i++)
    {
        sX = m_inputLines.at(i).find_first_of('S');
        if (sX != std::string::npos)
        {
            sY = i;
            break;
        }
    }
    char effectiveS = findEffectiveS(sX, sY);
    // swap the S on the map to be what it actually represents
    m_inputLines.at(sY).at(sX) = effectiveS;
    // create the initial traversal with one of the two directions S can take
    Traversal pos{{sX, sY}, m_tileMap.at(effectiveS).first};
    move(pos); // take first step away from S

    int steps = 1; // we have taken 1 step, now iterate until we get back to
                   // the initial position of S
    while (pos.first != Coord{sX, sY})
    {
        move(pos);
        steps++;
    }

    double furthestPoint = steps / 2.0; // in case of odd number
    return std::ceil(furthestPoint);
}

int Day10::solvePartTwo()
{
    // We marked only the loop on the map in part 1. Scan across each line, we are
    // inside the loop when we cross either a vertical piece, or a chosen pair of corners
    // with matching up/down elements, e.g. F/7, or L/J. This is since the non matching
    // one would create a vertical going upwards, making us enter as if it has just been a 
    // vertical, but the matching one then goes back on itself again, as if we had never
    // entered. Can ignore sideways dashes as we are scanning in that direction

    int areaCount = 0;
    for (const auto& line : m_inputCopy)
    {
        bool insideLoop = false;
        for (const auto c : line)
        {
            // flip inside/outside if we see one of these
            if (c == '|' || c == 'F' || c == '7')
                insideLoop = !insideLoop;
            else if (c == '.' && insideLoop)
                areaCount++;
        }
    }

    return areaCount;
}
