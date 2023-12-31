BUILD_DIR = ../build
BUILD_EXE = $(BUILD_DIR)/main.out

CXX = g++
CXXFLAGS = -std=c++20 -Wall -O2 -I../include/
OUTFLAG = -o $(BUILD_EXE)

$(BUILD_DIR):
	@ mkdir -p $(BUILD_DIR)

SOURCES = $(wildcard *.cpp) $(wildcard days/*.cpp)

all: $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SOURCES) $(OUTFLAG)

run: all
	@ $(BUILD_EXE)

clean:
	@ echo Cleaning build
	@ rm -r $(BUILD_DIR)
	