# Compiler
CXX ?= g++

CXXFLAGS := -std=c++11

program.exe: Main.cpp Minesweeper.cpp MineCell.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Disable built-in Makefile rules
.SUFFIXES:

clean:
	rm -rvf *.exe *.out.txt *.out.ppm *.dSYM *.stackdump