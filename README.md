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
Load Average: 0.45, 0.38, 0.31
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           312 us          312 us         2278
BM_Day2           605 us          605 us         1149
BM_Day3           845 us          845 us          832
BM_Day4           460 us          460 us         1508
BM_Day5           128 us          128 us         5462
BM_Day6          3.82 us         3.82 us       183601
BM_Day7           874 us          874 us          790
BM_Day8          4458 us         4458 us          156
BM_Day9           413 us          413 us         1684
BM_Day10          173 us          173 us         4052
BM_Day11          324 us          324 us         2159
```