#ifndef AOC_DAY_BASE
#define AOC_DAY_BASE

#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>

class DayBase
{
public:
    virtual void solveDay() = 0; // internally solve the day's problem
    virtual void print() = 0; // display the solution

    virtual ~DayBase() = default;
};

// To solve a day, a specific day class just need to inherit from a suitable DayBaseImpl, 
// and implement the solvePartOne() and solvePartTwo() functions
// As a pointer to a DayBase, any day can be solved with solveDay(), and the answer
// printed with print()
// As a DayBaseImpl implementation, the solution can be verified without printing 
// with verify(), e.g. for individual benchmarking

template<typename P1=uint64_t, typename P2=uint64_t>
class DayBaseImpl : public DayBase
{
public:
    void solveDay() override
    {
        m_partOneAnswer = solvePartOne();
        m_partTwoAnswer = solvePartTwo();
    }

    void print() override
    {
        std::cout << "Part 1: " << m_partOneAnswer << std::endl;
        std::cout << "Part 2: " << m_partTwoAnswer << std::endl;
    }

    void verify(P1 ans1, P2 ans2)
    {
        assert(ans1 == m_partOneAnswer);
        assert(ans2 == m_partTwoAnswer);
    }

    using Part1Type = P1;
    using Part2Type = P2;

protected:
    // available function for reading input into vector of strings by line
    // can either use this general function or implement a day-specific version
    void readInputToStringVec(const std::string& filename, bool print = true)
    {
        auto start = std::chrono::high_resolution_clock::now();
        std::ifstream file(filename);
        std::string str; 
        while (std::getline(file, str))
        {
            m_inputLines.push_back(str);
        }
        if (print)
        {
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            std::cout << "Read time for " << filename << " was " 
                      << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() 
                      << " microseconds\n";
        }
    }

    // implement these for a specific day
    virtual P1 solvePartOne() = 0;
    virtual P2 solvePartTwo() = 0;

    std::vector<std::string> m_inputLines;
    P1 m_partOneAnswer;
    P2 m_partTwoAnswer;
};

#endif
