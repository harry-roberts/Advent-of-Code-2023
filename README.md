## Advent of Code 2023

These are my solutions for Advent of Code 2023. Each day implements a templated base class depending on the answer type, and are then solved via the common base class interface.

A Google Benchmark program is included to performance test each individual day. The results for my inputs are:
```
Running ../build/benchmark.out
Run on (12 X 3600.02 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 512 KiB (x6)
  L3 Unified 16384 KiB (x1)
Load Average: 0.37, 0.22, 0.12
-----------------------------------------------------
Benchmark                           Time   Iterations
-----------------------------------------------------
BM_Day1                           338 us         2089
BM_Day2                           388 us         1780
BM_Day3                           339 us         2098
BM_Day4                           467 us         1164
BM_Day5                           134 us         5142
BM_Day6                          4.00 us       176297
BM_Day7                           500 us         1385
BM_Day8                           513 us         1000
BM_Day9                           309 us         2264
BM_Day10                          241 us         2871
BM_Day11                          318 us         2188
BM_Day12_1Thread/real_time       8328 us           82
BM_Day12_8Thread/real_time       2600 us          268
BM_Day13                          213 us         3253
BM_Day14                        33643 us           21
BM_Day15                          348 us         1992
BM_Day16                        12208 us           57
```