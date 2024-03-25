## Advent of Code 2023

These are my solutions for Advent of Code 2023. Each day implements a templated base class depending on the answer type, and are then solved via the common base class interface.

A Google Benchmark program is included to performance test each individual day. The results for my inputs are:
```
Running ../build/benchmark.out
Run on (12 X 3600.01 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 512 KiB (x6)
  L3 Unified 16384 KiB (x1)
Load Average: 0.27, 0.30, 0.23
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           317 us          317 us         2220
BM_Day2           382 us          382 us         1822
BM_Day3           325 us          325 us         2145
BM_Day4           435 us          435 us         1606
BM_Day5           133 us          133 us         5125
BM_Day6          3.97 us         3.97 us       176108
BM_Day7           517 us          517 us         1382
BM_Day8           500 us          500 us         1348
BM_Day9           311 us          311 us         2198
BM_Day10          241 us          241 us         2876
BM_Day11          322 us          322 us         2163
BM_Day12        13802 us        13802 us           52
BM_Day13          235 us          235 us         2967
```