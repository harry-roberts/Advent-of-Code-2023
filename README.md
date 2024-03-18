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
Load Average: 0.37, 0.44, 0.36
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           310 us          310 us         2246
BM_Day2           382 us          382 us         1799
BM_Day3           336 us          336 us         2094
BM_Day4           473 us          473 us         1484
BM_Day5           131 us          131 us         5342
BM_Day6          4.03 us         4.03 us       173531
BM_Day7           490 us          490 us         1415
BM_Day8           500 us          500 us         1422
BM_Day9           309 us          309 us         2287
BM_Day10          174 us          174 us         3622
BM_Day11         80.2 us         80.1 us         8423
```