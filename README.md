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
Load Average: 0.62, 0.37, 0.27
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           309 us          309 us         2266
BM_Day2           391 us          391 us         1814
BM_Day3           852 us          852 us          822
BM_Day4           483 us          483 us         1462
BM_Day5           132 us          132 us         5312
BM_Day6          4.04 us         4.04 us       177151
BM_Day7           910 us          910 us          759
BM_Day8          4660 us         4660 us          151
BM_Day9           426 us          426 us         1666
BM_Day10          173 us          173 us         4018
BM_Day11         81.8 us         81.8 us         8563
```