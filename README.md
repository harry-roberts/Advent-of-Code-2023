## Advent of Code 2023

These are my solutions for Advent of Code 2023. Each day inherits from a day base class, which handles reading the input into a vector of strings by line, and each solution works from there. 
A future task can be to optimise solutions where reading the input more directly could have a large impact, and also use multithreading.

Google Benchmark results for my inputs:
```
Running ../build/benchmark.out
Run on (12 X 3600.01 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 512 KiB (x6)
  L3 Unified 16384 KiB (x1)
Load Average: 0.41, 0.18, 0.07
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           300 us          300 us         2343
BM_Day2           608 us          608 us         1152
BM_Day3           853 us          853 us          825
BM_Day4           462 us          462 us         1509
BM_Day5           129 us          129 us         5437
BM_Day6          3.93 us         3.93 us       179557
BM_Day7           889 us          889 us          762
BM_Day8          4482 us         4482 us          157
BM_Day9           404 us          404 us         1731
BM_Day10          164 us          164 us         4310
```