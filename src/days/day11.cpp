#include "day11.h"

#include <set>
#include <cassert>

namespace d11
{

Day11::Day11(const std::string& filename, bool print)
{
    readInputToStringVec(filename, print);
}

void Day11::readGalaxyInfo()
{
    // iterate the image and find all galaxies
    // as we go, mark rows/cols with a galaxy by removing from set
    std::set<size_t> emptyCols;
    for (size_t x = 0; x < m_inputLines[0].size(); x++) 
        emptyCols.insert(emptyCols.end(), x);

    std::set<size_t> emptyRows;
    for (size_t y = 0; y < m_inputLines.size(); y++) 
        emptyRows.insert(emptyRows.end(), y);

    for (size_t y = 0; y < m_inputLines.size(); y++)
    {
        for (size_t x = 0; x < m_inputLines[y].size(); x++)
        {
            auto c = m_inputLines[y][x];
            if (c == '#')
            {
                emptyCols.erase(x);
                emptyRows.erase(y);
                m_galaxies.push_back({{x, y}, {0,0}}); // 0s for EmptyBefore for now
            }
        }
    }

    // count how many empty rows or cols there are before a given X or Y position, and update the
    // galaxy info with this
    for (auto& [galaxy, emptyBefore] : m_galaxies)
    {
        size_t emptyColsBefore = std::distance(emptyCols.begin(), 
                                               emptyCols.lower_bound(galaxy.first));
        size_t emptyRowsBefore = std::distance(emptyRows.begin(), 
                                               emptyRows.lower_bound(galaxy.second));

        emptyBefore.first = emptyColsBefore;
        emptyBefore.second = emptyRowsBefore;
    }
}

uint64_t Day11::calculateSumMinDistances(uint64_t expansionFactor)
{
    // the distance between 2 galaxies is just (the difference in x) + (the difference in y)
    // the galaxy positiosn can be adjusted for the expansion by doing 
    //      newPosX = originalPosX + (number of empty cols * (expansionFactor - 1))
    //      newPosY = originalPosY + (number of empty rows * (expansionFactor - 1))
    // to get every pair we can iterate upwards and calculate distances to every galaxy after
    // the current looking at.

    assert(expansionFactor > 1);
    uint64_t sumMinDistances = 0;

    for (size_t i = 0; i < m_galaxies.size()-1; i++) // one before end to look at the one at the end
    {
        for (size_t j = i+1; j < m_galaxies.size(); j++) // galaxy ahead of this
        {
            uint64_t x1 = m_galaxies[i].first.first + // first galaxy x pos
                            (m_galaxies[i].second.first * (expansionFactor-1)); // num of extra x
            uint64_t y1 = m_galaxies[i].first.second + // first galaxy y pos
                            (m_galaxies[i].second.second * (expansionFactor-1)); // num of extra y

            uint64_t x2 = m_galaxies[j].first.first + // second galaxy x pos
                            (m_galaxies[j].second.first * (expansionFactor-1)); // num of extra x
            uint64_t y2 = m_galaxies[j].first.second + // second galaxy y pos
                            (m_galaxies[j].second.second * (expansionFactor-1)); // num of extra y

            long long xDiff = llabs(x2 - x1);
            long long yDiff = llabs(y2 - y1);
            sumMinDistances += (xDiff+yDiff);
        }
    }

    return sumMinDistances;
}

Day11::Part1Type Day11::solvePartOne()
{
    readGalaxyInfo();
    // empty rows/cols are twice as big
    return calculateSumMinDistances(2);
}

Day11::Part2Type Day11::solvePartTwo()
{
    // empty rows/cols are 1000000x as big
    return calculateSumMinDistances(1000000);
}

} //namespace d11
