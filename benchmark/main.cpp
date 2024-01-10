#include <benchmark/benchmark.h>

#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"
#include "day7.h"
#include "day8.h"
#include "day9.h"
#include "day10.h"
#include "day11.h"

static void BM_Day1(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day1 d1("../src/inputs/input_day1.txt", false);
        d1.solveDay(false);
    }
}
BENCHMARK(BM_Day1);

static void BM_Day2(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day2 d2("../src/inputs/input_day2.txt", false);
        d2.solveDay(false);
    }
}
BENCHMARK(BM_Day2);

static void BM_Day3(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day3 d3("../src/inputs/input_day3.txt", false);
        d3.solveDay(false);
    }
}
BENCHMARK(BM_Day3);

static void BM_Day4(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day4 d4("../src/inputs/input_day4.txt", false);
        d4.solveDay(false);
    }
}
BENCHMARK(BM_Day4);

static void BM_Day5(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day5 d5("../src/inputs/input_day5.txt", false);
        d5.solveDay(false);
    }
}
BENCHMARK(BM_Day5);

static void BM_Day6(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day6 d6("../src/inputs/input_day6.txt", false);
        d6.solveDay(false);
    }
}
BENCHMARK(BM_Day6);

static void BM_Day7(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day7 d7("../src/inputs/input_day7.txt", false);
        d7.solveDay(false);
    }
}
BENCHMARK(BM_Day7);

static void BM_Day8(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day8 d8("../src/inputs/input_day8.txt", false);
        d8.solveDay(false);
    }
}
BENCHMARK(BM_Day8);

static void BM_Day9(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day9 d9("../src/inputs/input_day9.txt", false);
        d9.solveDay(false);
    }
}
BENCHMARK(BM_Day9);

static void BM_Day10(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day10 d10("../src/inputs/input_day10.txt", false);
        d10.solveDay(false);
    }
}
BENCHMARK(BM_Day10);

static void BM_Day11(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day11 d11("../src/inputs/input_day11.txt", false);
        d11.solveDay(false);
    }
}
BENCHMARK(BM_Day11);

BENCHMARK_MAIN();
