#include <benchmark/benchmark.h>

// benchmark program to test each individual day
// inside benchmark loop, create the day object, solve, and verify the answer

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
#include "day12.h"
#include "day13.h"

static void BM_Day1(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day1 d1("../src/inputs/input_day1.txt", false);
        d1.solveDay();
        d1.verify(54450, 54265);
    }
}
BENCHMARK(BM_Day1);

static void BM_Day2(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day2 d2("../src/inputs/input_day2.txt", false);
        d2.solveDay();
        d2.verify(2913, 55593);
    }
}
BENCHMARK(BM_Day2);

static void BM_Day3(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day3 d3("../src/inputs/input_day3.txt", false);
        d3.solveDay();
        d3.verify(553825, 93994191);
    }
}
BENCHMARK(BM_Day3);

static void BM_Day4(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day4 d4("../src/inputs/input_day4.txt", false);
        d4.solveDay();
        d4.verify(25183, 5667240);
    }
}
BENCHMARK(BM_Day4);

static void BM_Day5(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day5 d5("../src/inputs/input_day5.txt", false);
        d5.solveDay();
        d5.verify(26273516, 34039469);
    }
}
BENCHMARK(BM_Day5);

static void BM_Day6(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day6 d6("../src/inputs/input_day6.txt", false);
        d6.solveDay();
        d6.verify(625968, 43663323);
    }
}
BENCHMARK(BM_Day6);

static void BM_Day7(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day7 d7("../src/inputs/input_day7.txt", false);
        d7.solveDay();
        d7.verify(251029473, 251003917);
    }
}
BENCHMARK(BM_Day7);

static void BM_Day8(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day8 d8("../src/inputs/input_day8.txt", false);
        d8.solveDay();
        d8.verify(12361, 18215611419223);
    }
}
BENCHMARK(BM_Day8);

static void BM_Day9(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day9 d9("../src/inputs/input_day9.txt", false);
        d9.solveDay();
        d9.verify(1921197370, 1124);
    }
}
BENCHMARK(BM_Day9);

static void BM_Day10(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day10 d10("../src/inputs/input_day10.txt", false);
        d10.solveDay();
        d10.verify(6786, 495);
    }
}
BENCHMARK(BM_Day10);

static void BM_Day11(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day11 d11("../src/inputs/input_day11.txt", false);
        d11.solveDay();
        d11.verify(10231178, 622120986954);
    }
}
BENCHMARK(BM_Day11);

static void BM_Day12(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day12 d12("../src/inputs/input_day12.txt", false);
        d12.solveDay();
        d12.verify(7916, 37366887898686);
    }
}
BENCHMARK(BM_Day12);

static void BM_Day13(benchmark::State& state)
{
    for (auto _ : state)
    {
        Day13 d13("../src/inputs/input_day13.txt", false);
        d13.solveDay();
        d13.verify(35538, 30442);
    }
}
BENCHMARK(BM_Day13);

BENCHMARK_MAIN();
