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
Load Average: 0.09, 0.15, 0.15
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           306 us          306 us         2310
BM_Day2           379 us          379 us         1833
BM_Day3           314 us          314 us         2174
BM_Day4           438 us          438 us         1601
BM_Day5           131 us          131 us         5371
BM_Day6          4.07 us         4.07 us       172417
BM_Day7           483 us          483 us         1392
BM_Day8           511 us          511 us         1437
BM_Day9           309 us          309 us         2269
BM_Day10          173 us          173 us         4019
BM_Day11         81.0 us         80.9 us         848
```