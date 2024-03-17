#ifndef AOC_DAY7
#define AOC_DAY7

#include "day_base.h"

#include <unordered_map>
#include <cassert>

#define HAND_SIZE 5
#define CARD_TYPES 13

enum class HandRanking
{
    HighCard,
    OnePair,
    TwoPair,
    ThreeOfAKind,
    FullHouse,
    FourOfAKind,
    FiveOfAKind
};

class Hand
{
public:
    Hand(const std::string& handStr, int bid, bool isWild = false);

    bool operator<(const Hand& rhs);
    const int getBid() const;
    const std::string getHandStr() const;
    void setRanking(bool isWild);

private:
    int cardToRank(char c);
   
    char m_cards[HAND_SIZE];
    int m_bid;
    HandRanking m_rank;
    bool m_isWild;
    int m_numJokers = 0;
};

class Day7 : public DayBase
{
public:
    Day7(std::string filename, bool print = true);

    void solveDay(bool print = true);
    
private:
    int solvePartOne();
    int solvePartTwo();

    std::vector<Hand> m_allHands;
};

#endif
