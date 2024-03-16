## Advent of Code 2023

These are my solutions for Advent of Code 2023. Each day inherits from a day base class, which handles reading the input into a vector of strings by line, and each solution works from there. 
A future task can be to optimise solutions where reading the input more directly could have a large impact, and also use multithreading.

Google Benchmark results for my inputs:
```
Running ../build/benchmark.out
Run on (12 X 3599.99 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 512 KiB (x6)
  L3 Unified 16384 KiB (x1)
Load Average: 0.15, 0.28, 0.23
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           309 us          309 us         2257
BM_Day2           613 us          613 us         1144
BM_Day3           858 us          858 us          803
BM_Day4           478 us          478 us         1462
BM_Day5           130 us          130 us         5372
BM_Day6          3.96 us         3.96 us       176782
BM_Day7           899 us          899 us          761
BM_Day8          4476 us         4476 us          157
BM_Day9           429 us          429 us         1620
BM_Day10          173 us          173 us         4054
BM_Day11         82.0 us         81.9 us         7872
```