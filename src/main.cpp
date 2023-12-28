#include "AdventOfCode.h"

#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char** argv)
{
    AdventOfCode aoc;

    if (argc > 2)
    {
        std::cerr << "One argument can be given for a specific day" << std::endl;
    }
    else if (argc == 2)
    {
        std::string arg = argv[1];
        try 
        {
            std::size_t pos;
            size_t x = std::stoi(arg, &pos);
            if (pos < arg.size())
                std::cerr << "Trailing characters after number: " << arg << '\n';
            else
                aoc.solveDay(x);
        } 
        catch (std::invalid_argument const &ex) 
        {
            std::cerr << "Invalid number: " << arg << '\n';
        } 
        catch (std::out_of_range const &ex) 
        {
            std::cerr << "Number out of range: " << arg << '\n';
        }
    }
    else
    {
        aoc.solveAllDays();
    }
    
    return 0;
}
