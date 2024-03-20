#include "day7.h"

#include <boost/algorithm/string.hpp>

Day7::Day7(const std::string& filename, bool print)
{
    readInput(filename, print);
}

void Day7::solveDay(bool print)
{
    if (print)
    {
        std::cout << "Day 7 Part 1: " << solvePartOne() << std::endl;
        std::cout << "Day 7 Part 2: " << solvePartTwo() << std::endl;
    }
    else
    {
        solvePartOne();
        solvePartTwo();
    }
}

Hand::Hand(const std::string& handStr, int bid, bool isWild)
{
    // a joker can improve a hand. it will always become the same as the most occuring
    // card. Count them then remove the jacks and add to the other card's count
    assert(handStr.length() == HAND_SIZE);
    m_bid = bid;

    for (size_t i = 0; i < HAND_SIZE; i++)
        m_cards[i] = handStr[i];
        
    setRanking(isWild);
}

void Hand::setRanking(bool isWild)
{
    m_isWild = isWild;
    int seenCards[CARD_TYPES] = {}; // array of number of cards of each type. index is rank
    
    // keep track of the most and second most occurring card count
    int mostOccurringCount = 0;
    int secondMostOccurringCount = 0;

    for (size_t i = 0; i < HAND_SIZE; i++)
    {
        if (m_isWild && m_cards[i] == 'J') m_numJokers++; // only add jacks if not wild
        else seenCards[cardToRank(m_cards[i])]++;

        // we just need to know what the most and second most occurring count was
        // to be able to determine the hand, keep track and update those here
        int val = seenCards[cardToRank(m_cards[i])];
        if (val > mostOccurringCount)
            mostOccurringCount = val;
        else if (val > secondMostOccurringCount)
            secondMostOccurringCount = val;
    }

    // number of jacks will be zero if wild, now add that number seen to 
    // the most occurring count
    if (m_isWild)
        mostOccurringCount += m_numJokers;

    // find the ranking based on the maximum number of the same cards
    if (mostOccurringCount == 1) m_rank = HandRanking::HighCard;
    else if (mostOccurringCount == 2)
    {
        if (secondMostOccurringCount == 2) m_rank = HandRanking::TwoPair;
        else m_rank = HandRanking::OnePair;
    }
    else if (mostOccurringCount == 3)
    {
        if (secondMostOccurringCount == 2) m_rank = HandRanking::FullHouse;
        else m_rank = HandRanking::ThreeOfAKind;
    }
    else if (mostOccurringCount == 4) m_rank = HandRanking::FourOfAKind;
    else if (mostOccurringCount == 5) m_rank = HandRanking::FiveOfAKind;
}

bool Hand::operator<(const Hand& rhs)
{
    // first check the ranks
    if (m_rank < rhs.m_rank) return true;
    if (m_rank > rhs.m_rank) return false;

    // ranks are the same, check individual cards
    for (size_t i = 0; i < HAND_SIZE; i++)
    {
        // if it is a wildcard hand then set the value of a joker to -1
        int lhsVal = m_isWild && m_cards[i]=='J' ? -1 : cardToRank(m_cards[i]);
        int rhsVal = rhs.m_isWild && rhs.m_cards[i]=='J' ? -1 : cardToRank(rhs.m_cards[i]);
        if(lhsVal < rhsVal) return true;
        if(lhsVal > rhsVal) return false;
    }
    return false;
}

const int Hand::getBid() const
{
    return m_bid;
}

const std::string Hand::getHandStr() const
{
    return std::string(m_cards, HAND_SIZE);
}

int Hand::cardToRank(char c)
{
    // map a card to its rank
    if (c == '2') return 0;
    if (c == '3') return 1;
    if (c == '4') return 2;
    if (c == '5') return 3;
    if (c == '6') return 4;
    if (c == '7') return 5;
    if (c == '8') return 6;
    if (c == '9') return 7;
    if (c == 'T') return 8;
    if (c == 'J') return 9;
    if (c == 'Q') return 10;
    if (c == 'K') return 11;
    return 12; // ace
}

int Day7::solvePartOne()
{
    m_allHands.reserve(m_inputLines.size());
    // read every line into a hand, then add to a vector and sort at the end
    for (const auto& line : m_inputLines)
    {
        std::vector<std::string> handStrs;
        boost::split(handStrs, line, boost::is_any_of(" "));
        Hand h(handStrs[0], stoi(handStrs[1]));
        m_allHands.push_back(h);
    }
    sort(m_allHands.begin(), m_allHands.end());

    uint64_t totalSum = 0;
    for (size_t i = 0; i < m_allHands.size(); i++)
        totalSum += (i+1)*(m_allHands[i].getBid());

    return totalSum;
}

int Day7::solvePartTwo()
{
    // re-evaluate each ranking based on it being wild
    for (auto& h : m_allHands)
        h.setRanking(true);

    sort(m_allHands.begin(), m_allHands.end());

    uint64_t totalSum = 0;
    for (size_t i = 0; i < m_allHands.size(); i++)
        totalSum += (i+1)*(m_allHands[i].getBid());

    return totalSum;
}