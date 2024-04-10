#ifndef AOC_DAY16
#define AOC_DAY16

#include "day_base.h"

#include <map>
#include <optional>
#include <memory>
#include <bitset>

namespace d16
{

// directions as in where a beam is heading
enum class Direction
{
    VOID = 0,
    UP = 1,
    DOWN = 2,
    LEFT = 4,
    RIGHT = 8,
    UPDOWN = (int)UP + (int)DOWN,   // split into 2, going up and down
    LEFTRIGHT = (int)LEFT + (int)RIGHT // split into 2, going left and right
};

/*
  map an input direction -> output direction(s)
  6 possible outputs, up/down/left/right/up+down/left+right
  use 16 bit int, blocks of 4 bits are for each possible input
   up   down  left  right
  0000  0000  0000  0000
  result of the 4 bits is the index of the output
  
  e.g. a back slash '\' has these maps:
  up->left  down->right  left->up   right->down
    <\            v          ^          >\                  
     ^            \>         \<          v 
  each block in the mapping then becomes:
    up      down     left     right
  0100(4)  1000(8)  0001(1)  0010(2)
  4=left   8=right   1=up    2=down
  total uint16_t is then 0100100000010010
  mappings can be retrieved with a bit shift+mask, then casted to a direction

  Any tile in the layout is then represented by one of these uint16_ts, as well
  as another int (bitset) for describing which inputs have been seen
*/

class Tile
{
public:
    Direction getDirFromMap(Direction input);
    void setPathMap(char c);
    bool hasSeenInput(Direction input);
    bool seenInputsEmpty();
    void addInput(Direction input);
    void resetSeenInputs();

private:
    // the two ints being used as bitsets as described above
    uint16_t pathMap = 0;
    uint8_t seenInputs = 0;

    // static members
    // these shifts are the bit offsets from the lsb
    static constexpr int UpMapShift = 12;
    static constexpr int DownMapShift = 8;
    static constexpr int LeftMapShift = 4;
    static constexpr int RightMapShift = 0;
    static constexpr int mask = 0xF; // four ones

    // these maps are the full ints that have all the mappings within
    static constexpr uint16_t ForwardSlashMap =  // '/'
        ((static_cast<int>(Direction::RIGHT)) << UpMapShift) |
        ((static_cast<int>(Direction::LEFT))  << DownMapShift) |
        ((static_cast<int>(Direction::DOWN))  << LeftMapShift) |
        ((static_cast<int>(Direction::UP))    << RightMapShift);
    static constexpr uint16_t BackSlashMap =  // '\'
        ((static_cast<int>(Direction::LEFT))  << UpMapShift) |
        ((static_cast<int>(Direction::RIGHT)) << DownMapShift) |
        ((static_cast<int>(Direction::UP))    << LeftMapShift) |
        ((static_cast<int>(Direction::DOWN))  << RightMapShift);
    static constexpr uint16_t HyphenMap =  // '-'
        ((static_cast<int>(Direction::LEFTRIGHT)) << UpMapShift) |
        ((static_cast<int>(Direction::LEFTRIGHT)) << DownMapShift) |
        ((static_cast<int>(Direction::LEFT))      << LeftMapShift) |
        ((static_cast<int>(Direction::RIGHT))     << RightMapShift);
    static constexpr uint16_t PipeMap =  // '|'
        ((static_cast<int>(Direction::UP))     << UpMapShift) |
        ((static_cast<int>(Direction::DOWN))   << DownMapShift) |
        ((static_cast<int>(Direction::UPDOWN)) << LeftMapShift) |
        ((static_cast<int>(Direction::UPDOWN)) << RightMapShift);
    static constexpr uint16_t DotMap =  // '.'
        ((static_cast<int>(Direction::UP))    << UpMapShift) |
        ((static_cast<int>(Direction::DOWN))  << DownMapShift) |
        ((static_cast<int>(Direction::LEFT))  << LeftMapShift) |
        ((static_cast<int>(Direction::RIGHT)) << RightMapShift);
};

// coordinate on the layout
using Position = std::pair<size_t, size_t>; 
// where a beam currently is, and the direction it is heading
using Beam = std::pair<Position, Direction>; 

using Tiles = std::vector<std::vector<Tile>>;

class Day16 : public DayBaseImpl<>
{
public:
    Day16(const std::string& filename, bool print = true);
    
private:
    Part1Type solvePartOne() override;
    Part2Type solvePartTwo() override;

    // populate m_tiles with tiles based on the input
    void readInputToTiles(); 
    // function to check if a given direction would make the beam leave the layout
    bool directionHeadsOutsideLayout(const Direction dir, const Position& pos);
    // for an input beam, count how many tiles it would energise
    int getEnergisedTiles(Beam& inputBeam);
    // reset the seen inputs for every tile to nothing, to be able to calculate another beam
    void resetSeenDirections();

    // same size as input layout, with a tile for each space
    Tiles m_tiles;
    size_t m_maxX;
    size_t m_maxY;
};

} // namespace d16

#endif