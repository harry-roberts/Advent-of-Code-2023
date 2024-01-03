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

struct Hand
{
    char cards[HAND_SIZE];
    HandRanking rank;
    int bid;
    bool isWild;
    int numJokers = 0;
    static const std::unordered_map<char, int> CardRankingMap;

    Hand(std::string handStr, int bid_, bool isWild_ = false)
    {
        // a joker can improve a hand. it will always become the same as the most occuring
        // card. Count them then remove the jacks and add to the other card's count
        assert(handStr.length() == HAND_SIZE);
        bid = bid_;
        isWild = isWild_;
        int seenCards[CARD_TYPES] = {}; // array of number of cards of each type. index is rank
        for (size_t i = 0; i < HAND_SIZE; i++)
        {
            cards[i] = handStr[i];
            seenCards[CardRankingMap.at(handStr[i])]++;
            if (isWild && handStr[i] == 'J') numJokers++;
        }

        if (isWild)
        {
            // set the number of jacks to zero as they won't contribute to the hand 
            // themselves. Knowing the number of jokers we had means we can add that 
            // number to the most occuring card
            seenCards[CardRankingMap.at('J')] = 0;
        }

        // sort the array in descending order
        // this makes seenCards[0] the biggest number of identical cards
        std::sort(seenCards, seenCards+CARD_TYPES, std::greater<int>());

        if (isWild)
        {
            // we removed all the jacks. Now add them as the most occuring card
            seenCards[0] += numJokers;
        }

        // find the ranking based on the maximum number of the same cards
        if (seenCards[0] == 1) rank = HandRanking::HighCard;
        else if (seenCards[0] == 2)
        {
            if (seenCards[1] == 2) rank = HandRanking::TwoPair;
            else rank = HandRanking::OnePair;
        }
        else if (seenCards[0] == 3)
        {
            if (seenCards[1] == 2) rank = HandRanking::FullHouse;
            else rank = HandRanking::ThreeOfAKind;
        }
        else if (seenCards[0] == 4) rank = HandRanking::FourOfAKind;
        else if (seenCards[0] == 5) rank = HandRanking::FiveOfAKind;
    }

    bool operator<(const Hand& rhs)
    {
        // first check the ranks
        if (rank < rhs.rank) return true;
        if (rank > rhs.rank) return false;

        // ranks are the same, check individual cards
        for (size_t i = 0; i < HAND_SIZE; i++)
        {
            int lhsVal = CardRankingMap.at(cards[i]);
            int rhsVal = CardRankingMap.at(rhs.cards[i]);
            // if it is a wildcard hand then set the value of a joker to -1
            lhsVal = isWild && cards[i]=='J' ? -1 : lhsVal;
            rhsVal = rhs.isWild && rhs.cards[i]=='J' ? -1 : rhsVal;
            if(lhsVal < rhsVal) return true;
            if(lhsVal > rhsVal) return false;
        }
        return false;
    }
};

class Day7 : public DayBase
{
public:
    Day7(std::string filename);

    void solveDay();
    
private:
    int solvePartOne();
    int solvePartTwo();

    std::vector<Hand> m_allHands;
};

#endif
