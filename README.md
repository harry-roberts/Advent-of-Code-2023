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
Load Average: 0.33, 0.30, 0.24
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           298 us          298 us         2352
BM_Day2           607 us          607 us         1149
BM_Day3           847 us          847 us          821
BM_Day4           490 us          490 us         1422
BM_Day5           129 us          129 us         5406
BM_Day6          3.95 us         3.95 us       178069
BM_Day7           891 us          891 us          776
BM_Day8          4541 us         4541 us          154
BM_Day9           419 us          419 us         1676
```