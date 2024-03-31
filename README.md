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
Load Average: 0.74, 0.52, 0.31
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           321 us          321 us         2145
BM_Day2           381 us          381 us         1742
BM_Day3           318 us          318 us         2127
BM_Day4           461 us          461 us         1498
BM_Day5           129 us          129 us         5327
BM_Day6          4.08 us         4.07 us       138139
BM_Day7           499 us          499 us         1385
BM_Day8           522 us          522 us         1341
BM_Day9           325 us          325 us         2175
BM_Day10          249 us          249 us         2828
BM_Day11          326 us          326 us         2160
BM_Day12        13675 us        13675 us           51
BM_Day13          240 us          240 us         2903
BM_Day14        33807 us        33807 us           20
BM_Day15          383 us          383 us         1797
BM_Day16        20392 us        20392 us           35
```