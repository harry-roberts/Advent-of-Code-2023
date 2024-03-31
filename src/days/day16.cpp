#include "day16.h"

#include <queue>

namespace d16
{

Day16::Day16(const std::string& filename, bool print)
{
    readInputToStringVec(filename, print);
}

void Day16::readInputToTiles()
{
    m_ForwardSlashMirrorTileMap = std::make_shared<TilePathMap>(tpm_il{ // '/'
        {Direction::RIGHT, {Direction::UP, {}}},
        {Direction::DOWN, {Direction::LEFT, {}}},
        {Direction::LEFT, {Direction::DOWN, {}}},
        {Direction::UP, {Direction::RIGHT, {}}}});
    m_BackwardSlashMirrorTileMap = std::make_shared<TilePathMap>(tpm_il{ // '\'
        {Direction::RIGHT, {Direction::DOWN, {}}},
        {Direction::DOWN, {Direction::RIGHT, {}}},
        {Direction::LEFT, {Direction::UP, {}}},
        {Direction::UP, {Direction::LEFT, {}}}});
    m_HyphenSplitterTileMap = std::make_shared<TilePathMap>(tpm_il{ // '-'
        {Direction::RIGHT, {Direction::RIGHT, {}}},
        {Direction::DOWN, {Direction::RIGHT, {Direction::LEFT}}},
        {Direction::LEFT, {Direction::LEFT, {}}},
        {Direction::UP, {Direction::RIGHT, {Direction::LEFT}}}});
    m_PipeSplitterTileMap = std::make_shared<TilePathMap>(tpm_il{ // '|'
        {Direction::RIGHT, {Direction::UP, {Direction::DOWN}}},
        {Direction::DOWN, {Direction::DOWN, {}}},
        {Direction::LEFT, {Direction::UP, {Direction::DOWN}}},
        {Direction::UP, {Direction::UP, {}}}});
    m_DotTileMap = std::make_shared<TilePathMap>(tpm_il{ // '.'
        {Direction::RIGHT, {Direction::RIGHT, {}}},
        {Direction::DOWN, {Direction::DOWN, {}}},
        {Direction::LEFT, {Direction::LEFT, {}}},
        {Direction::UP, {Direction::UP, {}}}});

    m_tiles.reserve(m_inputLines.size());
    for (size_t y = 0; y < m_inputLines.size(); y++)
    {
        m_tiles.push_back(std::vector<Tile>(m_inputLines[y].size()));
        for (size_t x = 0; x < m_inputLines[y].size(); x++)
        {
            auto c = m_inputLines[y][x];
            if (c == '/') m_tiles[y][x].pathMap = m_ForwardSlashMirrorTileMap;
            else if (c == '\\') m_tiles[y][x].pathMap = m_BackwardSlashMirrorTileMap;
            else if (c == '-') m_tiles[y][x].pathMap = m_HyphenSplitterTileMap;
            else if (c == '|') m_tiles[y][x].pathMap = m_PipeSplitterTileMap;
            else if (c == '.') m_tiles[y][x].pathMap = m_DotTileMap;
        }
    }

    m_maxX = m_tiles[0].size() - 1;
    m_maxY = m_tiles.size() - 1;
}

bool Day16::directionHeadsOutsideLayout(const Direction dir, const Position& pos)
{
    return ((pos.first == 0 && dir == Direction::LEFT) ||
            (pos.first == m_maxX && dir == Direction::RIGHT) || 
            (pos.second == 0 && dir == Direction::UP) ||
            (pos.second == m_maxY && dir == Direction::DOWN));
}

void Day16::resetSeenDirections()
{
    for (auto& row : m_tiles)
        for (auto& tile : row)
            tile.seenInputs.reset();
}

int Day16::getEnergisedTiles(Beam& inputBeam)
{
    // as new beams are generated add them to a queue to be calculated afterwards
    // a beam will be fully counted before moving onto a new one
    std::queue<Beam> beams;
    beams.push(inputBeam);
    int energised = 0;
    
    while (!beams.empty())
    {
        auto beam = beams.front();
        beams.pop();
        while(true)
        {
            // current position of this beam
            auto& pos = beam.first;
            // current direction the beam is going
            auto& beamDir = beam.second;
            // the tile the beam is now interacting with
            auto& tile = m_tiles[pos.second][pos.first];
            // the output direction(s) that the beam should follow
            auto& tileMapBeamDir = (*(tile.pathMap.get()))[beamDir];

            if (tile.seenInputs[(int)beamDir])
                break;

            // this tile hasn't seen this input before, add it to the seen inputs
            // add to energised count only if it is this tile's first
            if (tile.seenInputs.none())
                energised++;
            tile.seenInputs[(int)beamDir].flip();

            // if there is a second direction, generate new beam in that direction
            if (tileMapBeamDir.second != std::nullopt && 
                !directionHeadsOutsideLayout(tileMapBeamDir.second.value(), pos))
            {
                beams.push(Beam{{pos.first, pos.second}, tileMapBeamDir.second.value()});
            }

            // if the tile is telling us to leave the layout, break out this loop
            if (directionHeadsOutsideLayout(tileMapBeamDir.first, pos))
                break;
            // otherwise we can update the beam's position and direction as per the tile's definition
            beamDir = tileMapBeamDir.first;
            if (beamDir == Direction::DOWN) pos.second++;
            else if (beamDir == Direction::UP) pos.second--;
            else if (beamDir == Direction::RIGHT) pos.first++;
            else if (beamDir == Direction::LEFT) pos.first--;
        }
    }

    return energised;
}

Day16::Part1Type Day16::solvePartOne()
{
    readInputToTiles();
    Beam startBeam{{0,0}, Direction::RIGHT};
    return getEnergisedTiles(startBeam);
}

Day16::Part2Type Day16::solvePartTwo()
{
    int maxEnergised = 0;

    // start at left column moving right
    for (size_t i = 0; i <= m_maxY; i++)
    {
        Beam startBeam{{0,i}, Direction::RIGHT};
        resetSeenDirections();
        maxEnergised = std::max(maxEnergised, getEnergisedTiles(startBeam));
    }

    // start at right column moving left
    for (size_t i = 0; i <= m_maxY; i++)
    {
        Beam startBeam{{m_maxX,i}, Direction::LEFT};
        resetSeenDirections();
        maxEnergised = std::max(maxEnergised, getEnergisedTiles(startBeam));
    }

    // start at top row moving down
    for (size_t i = 0; i <= m_maxX; i++)
    {
        Beam startBeam{{i,0}, Direction::DOWN};
        resetSeenDirections();
        maxEnergised = std::max(maxEnergised, getEnergisedTiles(startBeam));
    }

    // start at bottom row moving up
    for (size_t i = 0; i <= m_maxX; i++)
    {
        Beam startBeam{{i,m_maxY}, Direction::UP};
        resetSeenDirections();
        maxEnergised = std::max(maxEnergised, getEnergisedTiles(startBeam));
    }

    return maxEnergised;
}

} // namespace d16
