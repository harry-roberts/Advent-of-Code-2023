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
Load Average: 0.32, 0.10, 0.04
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           309 us          309 us         2260
BM_Day2           375 us          375 us         1866
BM_Day3           327 us          327 us         2069
BM_Day4           418 us          418 us         1636
BM_Day5           130 us          130 us         5302
BM_Day6          3.90 us         3.90 us       180241
BM_Day7           525 us          525 us         1363
BM_Day8           519 us          519 us         1378
BM_Day9           314 us          314 us         2195
BM_Day10          256 us          256 us         2776
BM_Day11          324 us          324 us         2148
BM_Day12        13642 us        13642 us           54
BM_Day13          242 us          242 us         3015
BM_Day14        34741 us        34741 us           20
```