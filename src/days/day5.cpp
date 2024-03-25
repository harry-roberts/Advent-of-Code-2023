#include "day5.h"

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

#include <cassert>
#include <limits>

Day5::Day5(const std::string& filename, bool print)
{
    readInputToStringVec(filename, print);
}

void Day5::parseInput()
{
    std::vector<Range>* currentRanges = nullptr; // points to the map vector we are currently populating
    for (size_t i = 0; i < m_inputLines.size(); i++)
    {
        // line is either empty, the seeds list, numbers for a map, or the title of a map
        std::string_view line{m_inputLines.at(i)};
        if (line.empty()) continue;

        if (isdigit(line.at(0)))
        {
            // parse the numbers
            assert(currentRanges != nullptr); // should have seen a title by now
            boost::char_separator<char> sep(" ");
            boost::tokenizer<boost::char_separator<char>> nums(line, sep);
            std::vector<NumType> lineNums;
            for (const auto& n : nums)
                lineNums.push_back(boost::lexical_cast<NumType>(n));
            assert(lineNums.size() == 3);
            Range r{lineNums.at(1), lineNums.at(0), lineNums.at(2)};
            currentRanges->push_back(r);
        }

        if (line.starts_with("seeds:"))
        {
            size_t seedsStart = line.find_first_of(':')+1;
            std::string_view seedsStr = line.substr(seedsStart);
            boost::char_separator<char> sep(" ");
            boost::tokenizer<boost::char_separator<char>> seeds(seedsStr, sep);

            for (const auto& s : seeds)
                m_seedNums.push_back(boost::lexical_cast<NumType>(s));
        }

        auto sourceDash = line.find_first_of('-');
        if (sourceDash != std::string_view::npos)
        {
            // map title line
            auto source = line.substr(0, sourceDash);
            auto destDash = line.find_last_of('-');
            auto destSpace = line.find_first_of(' ');
            auto dest = line.substr(destDash+1, destSpace-destDash-1);

            // init the map for this source and dest
            currentRanges = &(m_inputs[{{source.begin(), source.end()}, {dest.begin(), dest.end()}}]);
        }
    }
}

std::vector<Range> Day5::getMappedRanges(std::vector<Range>& input, std::vector<Range>& search)
{
    std::vector<Range> rtn; // we only really care about the dest in these
    sort(search.begin(), search.end()); // make sure the search vector is ordered

    for (const auto& inputRange : input)
    {
        auto currentInputStart = inputRange.destStart; // this will increase as we map the range
        auto inputEnd = inputRange.destStart + inputRange.length;

        for (const auto& searchRange : search)
        {
            // check each available mapping for the input to go to
            auto searchStart = searchRange.sourceStart;
            auto searchEnd = searchRange.sourceStart+searchRange.length;
            
            // if this mapped range doesn't cross the input then move to the next
            if (searchEnd < currentInputStart || searchStart > inputEnd)
                continue;

            // check to see if the start of the input begins before the start of the mapped range
            // if it does then it isn't mapped - we are checking the mappings in order
            if (currentInputStart < searchStart)
            {
                // the distance between the input start and search start isn't mapped
                Range r{currentInputStart, currentInputStart, searchStart-currentInputStart};
                rtn.push_back(r);
                currentInputStart += r.length; // move the current point forward
            }
            // only do < searchStart since it is ordered and there could be more later on after this range

            // we know the ranges cross somewhere - this amount needs to be mapped
            // the start is at either the start of the input or search, whichever is bigger
            // the end is at the end of the input or search, whichever is smaller
            auto start = std::max(currentInputStart, searchStart);
            auto end = std::min(inputEnd, searchEnd);
            auto length = end-start;
            if (length > 0)
            {
                Range r{start, start+searchRange.destStart-searchStart, length};
                rtn.push_back(r);
                currentInputStart += r.length; // move the current point forward
            }
            
        }
        // if there is still length left then it was outside the rhs of last search map, this amount maps to itself
        if (currentInputStart != inputEnd)
            rtn.push_back(Range{currentInputStart, currentInputStart, inputEnd-(currentInputStart)});
    }

    return rtn;
}

int Day5::solve(std::vector<Range>& inputVec)
{
    std::string currentSource = "seed";
    while (currentSource != "location")
    {
        // find the corresponsing key in the map that uses the current source
        for (const auto& [sourceDestPair, mapVec] : m_inputs)
        {
            if (sourceDestPair.first == currentSource)
            {
                inputVec = getMappedRanges(inputVec, m_inputs[{sourceDestPair.first, sourceDestPair.second}]);
                currentSource = sourceDestPair.second;
                break;
            }
        }
    }

    // find the lowest destination start in the range vector
    NumType lowestLocation = std::numeric_limits<NumType>::max();
    for (const auto& r : inputVec)
        lowestLocation = std::min(lowestLocation, r.destStart);

    return lowestLocation;
}

Day5::Part1Type Day5::solvePartOne()
{
    parseInput();
    std::vector<Range> seedRanges;
    for (size_t i = 0; i < m_seedNums.size(); i++)
        seedRanges.push_back({m_seedNums.at(i), m_seedNums.at(i), 1});

    return solve(seedRanges);
}

Day5::Part2Type Day5::solvePartTwo()
{
    std::vector<Range> seedRanges;
    for (size_t i = 0; i < m_seedNums.size(); i=i+2)
        seedRanges.push_back({m_seedNums.at(i), m_seedNums.at(i), m_seedNums.at(i+1)});

    return solve(seedRanges);
}
