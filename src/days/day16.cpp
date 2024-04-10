#include "day16.h"

namespace d16
{

Day16::Day16(const std::string& filename, bool print)
{
    readInputToStringVec(filename, print);
}

Direction Tile::getDirFromMap(Direction input)
{
    switch (input)
    {
        case Direction::UP:
            return static_cast<Direction>( (pathMap >> UpMapShift) & mask);
        case Direction::DOWN:
            return static_cast<Direction>( (pathMap >> DownMapShift) & mask);
        case Direction::LEFT:
            return static_cast<Direction>( (pathMap >> LeftMapShift) & mask);
        case Direction::RIGHT:
        default:
            return static_cast<Direction>( (pathMap >> RightMapShift) & mask);
    }
}

void Tile::setPathMap(char c)
{
    if (c == '.') pathMap = DotMap;
    else if (c == '/') pathMap = ForwardSlashMap;
    else if (c == '\\') pathMap = BackSlashMap;
    else if (c == '-') pathMap = HyphenMap;
    else if (c == '|') pathMap = PipeMap; 
}

bool Tile::hasSeenInput(Direction input)
{
    return static_cast<bool>(seenInputs & static_cast<int>(input));
}
bool Tile::seenInputsEmpty()
{
    return seenInputs == 0;
}
void Tile::addInput(Direction input)
{
    seenInputs |= static_cast<int>(input);
}
void Tile::resetSeenInputs()
{
    seenInputs = 0;
}

void Day16::readInputToTiles()
{
    m_tiles.reserve(m_inputLines.size());
    for (size_t y = 0; y < m_inputLines.size(); y++)
    {
        m_tiles.push_back(std::vector<Tile>(m_inputLines[y].size()));
        for (size_t x = 0; x < m_inputLines[y].size(); x++)
        {
            auto c = m_inputLines[y][x];
            m_tiles[y][x].setPathMap(c);
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
            tile.resetSeenInputs();
}

int Day16::getEnergisedTiles(Beam& inputBeam)
{
    int energised = 0;
    
    while(true)
    {
        // current position of this beam
        auto& pos = inputBeam.first;
        // current direction the beam is going
        auto& beamDir = inputBeam.second;
        // the tile the beam is now interacting with
        auto& tile = m_tiles[pos.second][pos.first];

        if (tile.hasSeenInput(beamDir))
            break;

        // this tile hasn't seen this input before, add it to the seen inputs
        // add to energised count only if it is this tile's first
        if (tile.seenInputsEmpty())
            energised++;
        
        tile.addInput(beamDir);

        // the output direction(s) that the beam should follow
        auto tileMapBeamDir = tile.getDirFromMap(beamDir);

        auto dir1 = tileMapBeamDir;
        auto dir2 = Direction::VOID;
        if (tileMapBeamDir == Direction::LEFTRIGHT) 
        {
            dir1 = Direction::LEFT;
            dir2 = Direction::RIGHT;
        }
        else if (tileMapBeamDir == Direction::UPDOWN) 
        {
            dir1 = Direction::UP;
            dir2 = Direction::DOWN;
        }

        // if there is a second direction, generate new beam in that direction
        if (dir2 != Direction::VOID && 
            !directionHeadsOutsideLayout(dir2, pos))
        {
            // recursively call this function again with the split beam
            Beam newBeam{{pos.first, pos.second}, dir2};
            energised += getEnergisedTiles(newBeam);
        }

        // if the tile is telling us to leave the layout, break out this loop
        if (directionHeadsOutsideLayout(dir1, pos))
            break;
        // otherwise we can update the beam's position and direction as per the tile's definition
        beamDir = dir1;

        switch (beamDir)
        {
            case Direction::DOWN:
                pos.second++;
                break;
            case Direction::UP:
                pos.second--;
                break;
            case Direction::RIGHT:
                pos.first++;
                break;
            case Direction::LEFT:
                pos.first--;
                break;
            default:
                break;
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
