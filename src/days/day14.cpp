#include "day14.h"

Day14::Day14(const std::string& filename, bool print)
{
    readInputToStringVec(filename, print);
}

constexpr size_t partTwoCycles = 1000000000;

void Day14::setup()
{
    size_t r = 0;
    for (size_t col = 0; col < m_inputLines[0].size(); col++)
        for (size_t row = 0; row < m_inputLines.size(); row++)
            if (m_inputLines[row][col] == 'O')
                r++;

    m_roundRockCount = r;
    m_rowSize = m_inputLines[0].size();
}

uint64_t Day14::calculateNorthLoad()
{
    uint64_t ans = 0;

    for (size_t col = 0; col < m_inputLines[0].size(); col++)
        for (size_t row = 0; row < m_inputLines.size(); row++)
            if (m_inputLines[row][col] == 'O')
                ans += m_inputLines.size() - row;

    return ans;
}

uint32_t Day14::tiltInputNorth(uint32_t cycle)
{
    Snapshot northSnapshot(m_roundRockCount, 0);

    for (size_t col = 0; col < m_inputLines[0].size(); col++)
    {
        for (size_t row = 0; row < m_inputLines.size(); row++)
        {
            if (m_inputLines[row][col] == 'O')
            {
                size_t currentPos = row;
                size_t bestPos = currentPos;
                while (currentPos != 0 && // start
                       m_inputLines[currentPos][col] != '#' && // can't go past hash
                       m_inputLines[currentPos-1][col] != 'O') // can't go past another O
                {
                    // check if the space above is free
                    // if it is, mark it as the best, then repeat
                    if (m_inputLines[currentPos-1][col] == '.')
                        bestPos = currentPos - 1;
                    currentPos--;
                }
                m_inputLines[row][col] = '.';
                m_inputLines[bestPos][col] = 'O';
                northSnapshot.push_back((m_rowSize*bestPos) + col);
            }
        }
    }
    if (m_northSnapshots.contains(northSnapshot))
        return m_northSnapshots[northSnapshot];
    m_northSnapshots[northSnapshot] = cycle;
    return 0;
}

uint32_t Day14::tiltInputSouth(uint32_t cycle)
{
    Snapshot southSnapshot(m_roundRockCount, 0);

    for (size_t col = 0; col < m_inputLines[0].size(); col++)
    {
        for (size_t row = m_inputLines.size(); row > 0; row--)
        {
            if (m_inputLines[row-1][col] == 'O')
            {
                size_t currentPos = row-1;
                size_t bestPos = currentPos;
                while (currentPos != m_inputLines.size()-1 && // start
                       m_inputLines[currentPos][col] != '#' && // can't go past hash
                       m_inputLines[currentPos+1][col] != 'O') // can't go past another O
                {
                    // check if the space below is free
                    // if it is, mark it as the best, then repeat
                    if (m_inputLines[currentPos+1][col] == '.')
                        bestPos = currentPos + 1;
                    currentPos++;
                }
                m_inputLines[row-1][col] = '.';
                m_inputLines[bestPos][col] = 'O';
                southSnapshot.push_back((m_rowSize*bestPos) + col);
            }
        }
    }
    if (m_southSnapshots.contains(southSnapshot))
        return m_southSnapshots[southSnapshot];
    m_southSnapshots[southSnapshot] = cycle;
    return 0;
}

uint32_t Day14::tiltInputWest(uint32_t cycle)
{
    Snapshot westSnapshot(m_roundRockCount, 0);

    for (size_t row = 0; row < m_inputLines.size(); row++)
    {
        for (size_t col = 0; col < m_inputLines[0].size(); col++)
        {
            if (m_inputLines[row][col] == 'O')
            {
                size_t currentPos = col;
                size_t bestPos = currentPos;
                while (currentPos != 0 && // start
                       m_inputLines[row][currentPos] != '#' && // can't go past hash
                       m_inputLines[row][currentPos-1] != 'O') // can't go past another O
                {
                    // check if the space west is free
                    // if it is, mark it as the best, then repeat
                    if (m_inputLines[row][currentPos-1] == '.')
                        bestPos = currentPos - 1;
                    currentPos--;
                }
                m_inputLines[row][col] = '.';
                m_inputLines[row][bestPos] = 'O';
                westSnapshot.push_back((m_rowSize*row) + bestPos);
            }
        }
    }
    if (m_westSnapshots.contains(westSnapshot))
        return m_westSnapshots[westSnapshot];
    m_westSnapshots[westSnapshot] = cycle;
    return 0;
}

uint32_t Day14::tiltInputEast(uint32_t cycle)
{
    Snapshot eastSnapshot(m_roundRockCount, 0);

    for (size_t row = 0; row < m_inputLines.size(); row++)
    {
        for (size_t col = m_inputLines[0].size(); col > 0; col--)
        {
            if (m_inputLines[row][col-1] == 'O')
            {
                size_t currentPos = col-1;
                size_t bestPos = currentPos;
                while (currentPos != m_inputLines[0].size()-1 && // start
                       m_inputLines[row][currentPos] != '#' && // can't go past hash
                       m_inputLines[row][currentPos+1] != 'O') // can't go past another O
                {
                    // check if the space east is free
                    // if it is, mark it as the best, then repeat
                    if (m_inputLines[row][currentPos+1] == '.')
                        bestPos = currentPos + 1;
                    currentPos++;
                }
                m_inputLines[row][col-1] = '.';
                m_inputLines[row][bestPos] = 'O';
                eastSnapshot.push_back((m_rowSize*bestPos) + col-1);
            }
        }
    }
    if (m_eastSnapshots.contains(eastSnapshot))
        return m_eastSnapshots[eastSnapshot];
    m_eastSnapshots[eastSnapshot] = cycle;
    return 0;
}

size_t Day14::getNewCycle(size_t previous, size_t current)
{
    // given a previous cycle that had the same round rock positions as we currently 
    // have, calculate the new cycle number that can be skipped ahead to
    size_t diff = current - previous;
    size_t remaining = partTwoCycles - current;
    size_t remainder = remaining % diff;
    return partTwoCycles - remainder;
}

Day14::Part1Type Day14::solvePartOne()
{
    setup();
    tiltInputNorth(1);
    return calculateNorthLoad();
}

Day14::Part2Type Day14::solvePartTwo()
{
    // finish the first cycle started in part 1
    tiltInputWest(1);
    tiltInputSouth(1);
    tiltInputEast(1);

    uint32_t previous = 0;
    bool hasSkipped = false; // once we have skipped ahead, just continue every tilt
    for (size_t cycle = 2; cycle <= partTwoCycles; cycle++)
    {
        previous = tiltInputNorth(cycle);
        if (previous && !hasSkipped)
        {
            cycle = getNewCycle(previous, cycle);
            hasSkipped = true;
        }
        previous = tiltInputWest(cycle);
        if (previous && !hasSkipped)
        {
            cycle = getNewCycle(previous, cycle);
            hasSkipped = true;
        }
        previous = tiltInputSouth(cycle);
        if (previous && !hasSkipped)
        {
            cycle = getNewCycle(previous, cycle);
            hasSkipped = true;
        }
        previous = tiltInputEast(cycle);
        if (previous && !hasSkipped)
        {
            cycle = getNewCycle(previous, cycle);
            hasSkipped = true;
        }
    }
    
    return calculateNorthLoad();
}
