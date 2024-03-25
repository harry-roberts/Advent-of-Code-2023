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
Load Average: 0.50, 0.27, 0.24
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           309 us          309 us         2196
BM_Day2           384 us          384 us         1830
BM_Day3           330 us          330 us         2095
BM_Day4           425 us          425 us         1633
BM_Day5           132 us          132 us         5323
BM_Day6          3.98 us         3.98 us       174706
BM_Day7           486 us          486 us         1444
BM_Day8           491 us          491 us         1320
BM_Day9           302 us          302 us         2317
BM_Day10          253 us          253 us         2729
BM_Day11          320 us          320 us         2154
BM_Day12        13926 us        13926 us           53
```