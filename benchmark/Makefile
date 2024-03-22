BUILD_DIR = ../build
BUILD_EXE = $(BUILD_DIR)/benchmark.out
CXX = g++
CXXFLAGS = -std=c++20 -Wall -O3
BMFLAGS = -isystem ../../tools/benchmark/include -I../include/ -L../../tools/benchmark/build/src -lbenchmark -lpthread
OUTFLAG = -o $(BUILD_EXE)
DEBUGFLAG = -g

$(BUILD_DIR):
	@ mkdir -p $(BUILD_DIR)

SOURCES = $(wildcard *.cpp) $(wildcard ../src/days/*.cpp)

all: $(BUILD_DIR)
	$(CXX) $(SOURCES) $(CXXFLAGS) $(BMFLAGS) $(OUTFLAG)

run: all
	@ $(BUILD_EXE) --benchmark_time_unit=us

debug: $(BUILD_DIR)
	$(CXX) $(SOURCES) $(CXXFLAGS) $(BMFLAGS) $(DEBUGFLAG) $(OUTFLAG)

clean:
	@ echo Cleaning build
	@ rm -r $(BUILD_DIR)
