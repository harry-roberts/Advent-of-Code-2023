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
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// map an input direction to an output direction(s) (in the case of splitting)
using TilePathMap = std::map<Direction, std::pair<Direction, std::optional<Direction>>>;
using tpm_il = std::initializer_list<TilePathMap::value_type>;
// e.g. 
// map of right -> down    map of down -> right      map of down -> left+right
//     >\                          v                            v
//      v                          \>                          <->

struct Tile
{
    // each tile uses a map based on the character
    std::shared_ptr<TilePathMap> pathMap;
    // store a set of inputs that have been seen at a tile, as once a beam enters a tile 
    // in the same way as has already been seen, nothing different will happen
    std::bitset<4> seenInputs; 
};

// coordinate on the layout
using Position = std::pair<size_t, size_t>; 
// where a beam currently is, and the direction it is heading
using Beam = std::pair<Position, Direction>; 

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
    std::vector<std::vector<Tile>> m_tiles;
    size_t m_maxX;
    size_t m_maxY;

    // define maps for each possible character, to assign tiles to
    std::shared_ptr<TilePathMap> m_ForwardSlashMirrorTileMap;
    std::shared_ptr<TilePathMap> m_BackwardSlashMirrorTileMap;
    std::shared_ptr<TilePathMap> m_HyphenSplitterTileMap;
    std::shared_ptr<TilePathMap> m_PipeSplitterTileMap;
    std::shared_ptr<TilePathMap> m_DotTileMap;

};

} // namespace d16

#endif