#include "day4.h"

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>

#include <unordered_set>

Day4::Day4(std::string filename, bool print)
{
    readInput(filename, print);
}

int Day4::parseLine(std::string_view line)
{
    size_t winningStart = line.find_first_of(':')+1;
    size_t split = line.find_first_of('|');
    std::string_view winningStr = line.substr(winningStart, split-winningStart);
    std::string_view numbersStr = line.substr(split+1);

    boost::char_separator<char> sep(" ");
    boost::tokenizer<boost::char_separator<char>> winningNumbers(winningStr, sep);
    boost::tokenizer<boost::char_separator<char>> numbers(numbersStr, sep);

    std::unordered_set<int> winningSet;
    for (const auto& w : winningNumbers)
        winningSet.insert(std::atoi(w.c_str()));

    int matches = 0;
    for (const auto& n : numbers)
    {
        if (winningSet.contains(std::atoi(n.c_str())))
           matches++;
    }

    return matches;
}

void Day4::solveDay(bool print)
{
    if (print)
    {
        std::cout << "Day 4 Part 1: " << solvePartOne() << std::endl;
        std::cout << "Day 4 Part 2: " << solvePartTwo() << std::endl;
    }
    else
    {
        solvePartOne();
        solvePartTwo();
    }
}

int Day4::solvePartOne()
{
    int totalScore = 0;
    m_lineMatches.reserve(m_inputLines.size());
    for (const auto& line : m_inputLines)
    {
        // score by doubling each time can just be bit shifted, but go back one at the end as 0 = 0 points
        int score = parseLine(line);
        totalScore += (( 1 << score) >> 1);
        m_lineMatches.push_back(score); // used in part 2
    }
    return totalScore;
}

int Day4::solvePartTwo()
{
    int totalNumberOfCards = m_lineMatches.size(); // starting with as many cards as we have
    std::vector<int> numberOfCopies(m_lineMatches.size(), 0); // number of additional copies of each card
    for (size_t i = 0; i < m_lineMatches.size(); i++)
    {
        // for each score S, the next S cards get an additional copy
        int score = m_lineMatches[i];
        int currentCopiesOfThisCard = numberOfCopies[i];
        size_t nextCard = i+1;

        // total number of cards increases by however many additional copies of this card we have
        totalNumberOfCards += currentCopiesOfThisCard;
        int totalCopiesToGive = ++currentCopiesOfThisCard;

        for (size_t n = nextCard; (n < m_lineMatches.size() && n < (nextCard+score)); n++)
            numberOfCopies[n] += totalCopiesToGive;
    }

    return totalNumberOfCards;
}
