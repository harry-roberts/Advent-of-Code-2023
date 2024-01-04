#include "day_base.h"

#include <fstream>
#include <chrono>
#include <iostream>

void DayBase::readInput(std::string filename, bool print)
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
        std::cout << "Read time for " << filename << " was " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " microseconds" << std::endl;
    }
    
}
