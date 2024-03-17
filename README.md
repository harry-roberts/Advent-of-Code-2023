## Advent of Code 2023

These are my solutions for Advent of Code 2023. Each day inherits from a day base class, which handles reading the input into a vector of strings by line, and each solution works from there. 
A future task can be to optimise solutions where reading the input more directly could have a large impact, and also use multithreading.

Google Benchmark results for my inputs:
```
Running ../build/benchmark.out
Run on (12 X 3600 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 512 KiB (x6)
  L3 Unified 16384 KiB (x1)
Load Average: 0.45, 0.45, 0.29
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           307 us          306 us         2278
BM_Day2           387 us          387 us         1804
BM_Day3           323 us          323 us         2185
BM_Day4           471 us          471 us         1486
BM_Day5           131 us          131 us         5397
BM_Day6          4.03 us         4.03 us       174146
BM_Day7           490 us          490 us         1369
BM_Day8          4616 us         4616 us          152
BM_Day9           417 us          417 us         1669
BM_Day10          174 us          174 us         4019
BM_Day11         81.2 us         81.1 us         8626
```