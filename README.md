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
Load Average: 0.56, 0.36, 0.27
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Day1           304 us          304 us         2298
BM_Day2           379 us          379 us         1847
BM_Day3           321 us          321 us         2171
BM_Day4           416 us          416 us         1697
BM_Day5           134 us          134 us         5244
BM_Day6          4.07 us         4.07 us       172857
BM_Day7           484 us          484 us         1398
BM_Day8           513 us          513 us         1000
BM_Day9           303 us          303 us         2300
BM_Day10          175 us          175 us         3916
BM_Day11         79.8 us         79.8 us         8618
BM_Day12        13320 us        13320 us           54
```