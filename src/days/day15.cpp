#include "day15.h"

#include <unordered_map>
#include <list>

namespace d15
{

Day15::Day15(const std::string& filename, bool print)
{
    readInputToStringVec(filename, print);
}

void Day15::parseInput()
{
    std::string_view sv{m_inputLines[0]};

    size_t pos = 0;
    size_t comma = sv.find_first_of(",");
    while (true) // keep adding the next substring until there are no more commas
    {
        m_seqSteps.push_back(sv.substr(pos, comma-pos));
        pos = comma+1;
        comma = sv.substr(pos).find_first_of(",");
        if (comma == std::string_view::npos)
        {
            m_seqSteps.push_back(sv.substr(pos));
            break;
        }
        comma += pos;
    }
}

uint8_t Day15::hashString(std::string_view s)
{
    uint16_t currentValue = 0;

    for (const auto c : s)
    {
        currentValue += static_cast<uint16_t>(c);
        currentValue *= 17;
        currentValue %= 256;
    }

    return static_cast<uint8_t>(currentValue);
}

Day15::Part1Type Day15::solvePartOne()
{
    parseInput();
    uint64_t ans = 0;

    for (const auto& step : m_seqSteps)
        ans += hashString(step);
    return ans;
}

Day15::Part2Type Day15::solvePartTwo()
{
    // pair of label/focal length
    using lensInfo = std::pair<std::string_view, uint8_t>;
    // map of box number to list of lensInfos
    std::unordered_map<uint8_t, std::list<lensInfo>> lensBoxMap;

    for (const auto& step : m_seqSteps)
    {
        if (step.back() == '-')
        {
            // find the box number from the label
            // if the box contains this label, remove it
            auto label = step.substr(0, step.size()-1); // not including last char
            auto boxNumber = hashString(label);
            
            if (lensBoxMap.contains(boxNumber))
            {
                for (auto it = lensBoxMap[boxNumber].begin(); 
                     it != lensBoxMap[boxNumber].end(); it++)
                {
                    if (it->first == label)
                    {
                        lensBoxMap[boxNumber].erase(it);
                        break;
                    }
                }
            }
        }
        else
        {
            // find the box number from the label
            // check if the label is already in the box
            //      if it is, replace lens with this focal length
            //      if it isnt, add this lens to the end of list
            auto label = step.substr(0, step.size()-2); // not including last 2 chars
            auto focalLength = (step.back() - '0'); // last char is single digit between 1-9
            auto boxNumber = hashString(label);
            bool found = false;

            if (lensBoxMap.contains(boxNumber))
            {
                for (auto it = lensBoxMap[boxNumber].begin(); 
                     it != lensBoxMap[boxNumber].end(); it++)
                {
                    if (it->first == label)
                    {
                        it->second = focalLength;
                        found = true;
                        break;
                    }
                }
            }
            if (!found)
                lensBoxMap[boxNumber].push_back(lensInfo{label, focalLength});
        }
    }

    uint64_t totalPower = 0;

    for (const auto& [boxNumber, listLensInfo] : lensBoxMap)
    {
        size_t count = 1;
        for (const auto& li : listLensInfo)
        {
            auto lensPower = (boxNumber + 1) * count * li.second;
            totalPower += lensPower;
            count++;
        }
    }

    return totalPower;
}

} //namespace d15
