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
#include "day14.h"
#include "day15.h"
#include "day16.h"

static void BM_Day1(benchmark::State& state)
{
    for (auto _ : state)
    {
        d1::Day1 day1("../src/inputs/input_day1.txt", false);
        day1.solveDay();
        day1.verify(54450, 54265);
    }
}
BENCHMARK(BM_Day1);

static void BM_Day2(benchmark::State& state)
{
    for (auto _ : state)
    {
        d2::Day2 day2("../src/inputs/input_day2.txt", false);
        day2.solveDay();
        day2.verify(2913, 55593);
    }
}
BENCHMARK(BM_Day2);

static void BM_Day3(benchmark::State& state)
{
    for (auto _ : state)
    {
        d3::Day3 day3("../src/inputs/input_day3.txt", false);
        day3.solveDay();
        day3.verify(553825, 93994191);
    }
}
BENCHMARK(BM_Day3);

static void BM_Day4(benchmark::State& state)
{
    for (auto _ : state)
    {
        d4::Day4 day4("../src/inputs/input_day4.txt", false);
        day4.solveDay();
        day4.verify(25183, 5667240);
    }
}
BENCHMARK(BM_Day4);

static void BM_Day5(benchmark::State& state)
{
    for (auto _ : state)
    {
        d5::Day5 day5("../src/inputs/input_day5.txt", false);
        day5.solveDay();
        day5.verify(26273516, 34039469);
    }
}
BENCHMARK(BM_Day5);

static void BM_Day6(benchmark::State& state)
{
    for (auto _ : state)
    {
        d6::Day6 day6("../src/inputs/input_day6.txt", false);
        day6.solveDay();
        day6.verify(625968, 43663323);
    }
}
BENCHMARK(BM_Day6);

static void BM_Day7(benchmark::State& state)
{
    for (auto _ : state)
    {
        d7::Day7 day7("../src/inputs/input_day7.txt", false);
        day7.solveDay();
        day7.verify(251029473, 251003917);
    }
}
BENCHMARK(BM_Day7);

static void BM_Day8(benchmark::State& state)
{
    for (auto _ : state)
    {
        d8::Day8 day8("../src/inputs/input_day8.txt", false);
        day8.solveDay();
        day8.verify(12361, 18215611419223);
    }
}
BENCHMARK(BM_Day8);

static void BM_Day9(benchmark::State& state)
{
    for (auto _ : state)
    {
        d9::Day9 day9("../src/inputs/input_day9.txt", false);
        day9.solveDay();
        day9.verify(1921197370, 1124);
    }
}
BENCHMARK(BM_Day9);

static void BM_Day10(benchmark::State& state)
{
    for (auto _ : state)
    {
        d10::Day10 day10("../src/inputs/input_day10.txt", false);
        day10.solveDay();
        day10.verify(6786, 495);
    }
}
BENCHMARK(BM_Day10);

static void BM_Day11(benchmark::State& state)
{
    for (auto _ : state)
    {
        d11::Day11 day11("../src/inputs/input_day11.txt", false);
        day11.solveDay();
        day11.verify(10231178, 622120986954);
    }
}
BENCHMARK(BM_Day11);

static void BM_Day12(benchmark::State& state)
{
    for (auto _ : state)
    {
        d12::Day12 day12("../src/inputs/input_day12.txt", false);
        day12.solveDay();
        day12.verify(7916, 37366887898686);
    }
}
BENCHMARK(BM_Day12);

static void BM_Day13(benchmark::State& state)
{
    for (auto _ : state)
    {
        d13::Day13 day13("../src/inputs/input_day13.txt", false);
        day13.solveDay();
        day13.verify(35538, 30442);
    }
}
BENCHMARK(BM_Day13);

static void BM_Day14(benchmark::State& state)
{
    for (auto _ : state)
    {
        d14::Day14 day14("../src/inputs/input_day14.txt", false);
        day14.solveDay();
        day14.verify(110565, 89845);
    }
}
BENCHMARK(BM_Day14);

static void BM_Day15(benchmark::State& state)
{
    for (auto _ : state)
    {
        d15::Day15 day15("../src/inputs/input_day15.txt", false);
        day15.solveDay();
        day15.verify(514394, 236358);
    }
}
BENCHMARK(BM_Day15);

static void BM_Day16(benchmark::State& state)
{
    for (auto _ : state)
    {
        d16::Day16 day16("../src/inputs/input_day16.txt", false);
        day16.solveDay();
        day16.verify(6902, 7697);
    }
}
BENCHMARK(BM_Day16);

BENCHMARK_MAIN();
