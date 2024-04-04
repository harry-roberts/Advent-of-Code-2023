## Advent of Code 2023

These are my solutions for Advent of Code 2023. Each day implements a templated base class depending on the answer type, and are then solved via the common base class interface.

A Google Benchmark program is included to performance test each individual day. The results for my inputs are:
```
Running ../build/benchmark.out
Run on (12 X 3600 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 512 KiB (x6)
  L3 Unified 16384 KiB (x1)
Load Average: 0.66, 0.47, 0.42
-----------------------------------------------------
Benchmark                           Time   Iterations
-----------------------------------------------------
BM_Day1                           320 us         2211
BM_Day2                           389 us         1738
BM_Day3                           337 us         2137
BM_Day4                           423 us         1656
BM_Day5                           129 us         5148
BM_Day6                          4.03 us       174183
BM_Day7                           511 us         1347
BM_Day8                           520 us         1000
BM_Day9                           311 us         2233
BM_Day10                          247 us         2861
BM_Day11                          326 us         2024
BM_Day12_1Thread/real_time       8537 us           83
BM_Day12_8Thread/real_time       2627 us          256
BM_Day13                          219 us         3203
BM_Day14                        33140 us           21
BM_Day15                          369 us         1851
BM_Day16                        20339 us           35
```