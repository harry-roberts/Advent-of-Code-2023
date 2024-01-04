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
Load Average: 0.17, 0.15, 0.09
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           309 us          309 us         2265
BM_Day2           616 us          616 us         1138
BM_Day3           864 us          864 us          823
BM_Day4           467 us          467 us         1507
BM_Day5           135 us          135 us         5237
BM_Day6          3.99 us         3.99 us       177043
BM_Day7           885 us          885 us          768
BM_Day8          4418 us         4418 us          158
```