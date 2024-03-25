#include "day6.h"

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

Day6::Day6(const std::string& filename, bool print)
{
    readInputToStringVec(filename, print);
}

void Day6::parseInput()
{
    for (const auto& line : m_inputLines)
    {
        std::string_view sv{line};
        size_t start = sv.find_first_of(':')+1;
        std::string_view str = sv.substr(start);

        boost::char_separator<char> sep(" ");
        boost::tokenizer<boost::char_separator<char>> nums(str, sep);
        if (sv.starts_with("Time"))
        {
            for (const auto& n : nums)
                m_inputTimes.push_back(boost::lexical_cast<uint64_t>(n));
        }
        if (sv.starts_with("Distance"))
        {
            for (const auto& n : nums)
                m_inputDistances.push_back(boost::lexical_cast<uint64_t>(n));
        }
    }

    assert(m_inputTimes.size() == m_inputDistances.size());

    for (size_t i = 0; i < m_inputTimes.size(); i++)
        m_races.push_back({m_inputTimes.at(i), m_inputDistances.at(i)});
}

uint64_t Day6::solveNumWaysToWin(uint64_t T, uint64_t target)
{
    // to get the distances for a max time "T", the possible distances are: 
    //          0*(T-0), 1*(T-1), 2*(T-2)...T(T-T)
    // the distance "D" for a given time "x" then has the equation D = Tx - x^2
    // a given distance will intersect this curve at 2 points:
    /*
              |                                          
              |                 ---------                
              |             ---/         \---              
              |          --/                 \-            
       target-|--------X------------------------X--------
              |      -/                          -\        
         Dist |     /                               \      
              |   -                                  -  
              |  /                                    \   
              | /                                      \  
              |/                                        \ 
            0 ---------------------------------------------
              0                 Time                     T
    */

    // therefore need to solve: target = Tx - x^2
    //                          x^2 - Tx + target = 0
    // round the first solution up*, this is the first winning time
    // round the second solution down*, this is the last wining time
    // x = -b +- sqrt(b^2 - 4ac) / 2a
    // a=1, b=-T, c=target

    double x1 = (T + sqrt((T*T) - (4*target))) / 2;
    double x2 = (T - sqrt((T*T) - (4*target))) / 2;

    double first = std::min(x1, x2);
    double second = std::max(x1, x2);
    // *for first, actually round down the add 1
    // *for second, actually round up then subtract 1
    // this covers case of solution being an exact number - we need to beat the score rather than just match it
    uint64_t firstWin = std::floor(first) + 1;
    uint64_t lastWin = std::ceil(second) - 1;

    return (lastWin - firstWin + 1); // +1 for inclusive bounds
}

Day6::Part1Type Day6::solvePartOne()
{
    parseInput();
    uint64_t multiplyWays = 1;
    for (const auto& [time, dist] : m_races)
        multiplyWays *= solveNumWaysToWin(time, dist);

    return multiplyWays;
}

uint64_t concat(uint64_t a, uint64_t b)
{
    std::string s1 = std::to_string(a);
    std::string s2 = std::to_string(b);
    std::string s = s1 + s2;
    return stoull(s);
}

Day6::Part2Type Day6::solvePartTwo()
{
    // concat all the numbers, then just 1 result
    uint64_t concatTime = 0;
    uint64_t concatDist = 0;
    for (const auto& [time, dist] : m_races)
    {
        concatTime = concat(concatTime, time);
        concatDist = concat(concatDist, dist);
    }
    return solveNumWaysToWin(concatTime, concatDist);
}
