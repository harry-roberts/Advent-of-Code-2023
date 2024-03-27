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
Load Average: 0.35, 0.19, 0.20
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           305 us          305 us         2332
BM_Day2           379 us          379 us         1846
BM_Day3           321 us          321 us         2168
BM_Day4           436 us          436 us         1554
BM_Day5           132 us          132 us         5199
BM_Day6          3.91 us         3.91 us       178876
BM_Day7           498 us          498 us         1369
BM_Day8           505 us          505 us         1370
BM_Day9           318 us          318 us         2212
BM_Day10          247 us          247 us         2830
BM_Day11          321 us          321 us         2197
BM_Day12        13331 us        13331 us           50
BM_Day13          237 us          237 us         3059
BM_Day14        33293 us        33293 us           21
BM_Day15          390 us          390 us         1818
```