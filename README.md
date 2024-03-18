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
Load Average: 0.70, 0.42, 0.19
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           311 us          311 us         2256
BM_Day2           388 us          388 us         1805
BM_Day3           326 us          326 us         2162
BM_Day4           464 us          464 us         1516
BM_Day5           134 us          134 us         5223
BM_Day6          4.04 us         4.04 us       175155
BM_Day7           501 us          501 us         1365
BM_Day8           496 us          496 us         1437
BM_Day9           417 us          417 us         1672
BM_Day10          172 us          172 us         4030
BM_Day11         82.1 us         82.0 us         8505
```