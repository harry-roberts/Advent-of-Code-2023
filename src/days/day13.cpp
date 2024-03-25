#include "day13.h"

Day13::Day13(const std::string& filename, bool print)
{
    readInputToStringVec(filename, print);
}

size_t Day13::findColsLeftVerticalLine(std::vector<std::string> pattern, bool allowSmudge)
{
    for (size_t col = 1; col <= pattern[0].size()-1; col++)
    {
        size_t posLeft = col; // check col moving left
        size_t posRight = col+1; // check col moving right
        size_t differences = 0; // count any mismatched character

        while (posLeft != 0 && posRight != pattern[0].size()+1)
        {
            for (const auto& row : pattern)
            {
                if (row[posLeft-1] != row[posRight-1])
                    differences++;
            }
            posLeft--;
            posRight++;
            if (differences > 0 && !allowSmudge) break;
        }
        // there is only 1 reflection, if we have it then can return now
        if (differences == 0 && !allowSmudge)
            return col; // zero differences, not looking for a smudge, this is the line
        if (differences == 1 && allowSmudge)
            return col; // only one difference, that can be the smudge and we accept this line
    }
    return 0;
}

size_t Day13::findRowsAboveHozitontalLine(std::vector<std::string> pattern, bool allowSmudge)
{
    for (size_t row = 1; row <= pattern.size()-1; row++)
    {
        size_t posUp = row; // check row moving upwards
        size_t posDown = row+1; // check row moving downwards
        size_t differences = 0; // count any mismatched character

        while (posUp != 0 && posDown != pattern.size()+1)
        {
            for (size_t i = 0; i < pattern[posUp-1].size(); i++)
            {
                if (pattern[posUp-1][i] != pattern[posDown-1][i])
                    differences++;
            }
            posUp--;
            posDown++;
            if (differences > 0 && !allowSmudge) break;
        }
        // there is only 1 reflection, if we have it then can return now
        if (differences == 0 && !allowSmudge)
            return row; // zero differences, not looking for a smudge, this is the line
        if (differences == 1 && allowSmudge)
            return row; // only one difference, that can be the smudge and we accept this line
    }
    return 0;
}

void Day13::parseInput()
{
    size_t inputPos = 0;
    while (inputPos < m_inputLines.size())
    {
        std::vector<std::string> pattern;
        while (m_inputLines[inputPos] != "" && inputPos != m_inputLines.size())
            pattern.push_back(m_inputLines[inputPos++]);

        inputPos++;
        m_patterns.push_back(pattern);
    }
}

Day13::Part1Type Day13::solvePartOne()
{
    parseInput();
    uint64_t ans = 0;
    
    for (const auto& p : m_patterns)
    {
        ans += findColsLeftVerticalLine(p);
        ans += (100 * findRowsAboveHozitontalLine(p));
    }
    
    return ans;
}

Day13::Part2Type Day13::solvePartTwo()
{
    uint64_t ans = 0;
    
    for (const auto& p : m_patterns)
    {
        ans += findColsLeftVerticalLine(p, true);
        ans += (100 * findRowsAboveHozitontalLine(p, true));
    }
    
    return ans;
}
