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
Load Average: 0.86, 0.48, 0.31
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           310 us          310 us         2256
BM_Day2           380 us          380 us         1819
BM_Day3           325 us          325 us         2130
BM_Day4           465 us          465 us         1512
BM_Day5           134 us          134 us         5168
BM_Day6          3.95 us         3.95 us       175627
BM_Day7           891 us          891 us          769
BM_Day8          4460 us         4460 us          155
BM_Day9           417 us          417 us         1662
BM_Day10          173 us          173 us         4022
BM_Day11         80.9 us         80.8 us         8526
```