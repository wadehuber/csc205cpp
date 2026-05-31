# Makefile for the cppreview/cppreview examples.
#
#   make        build all the programs
#   make run    build and run the non-interactive ones
#   make clean  delete the built programs
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Each example is an independent program.
PROGRAMS = arrays controlstructures functions commonmistakes mathandrandom \
           objectreferences wrapper classexample

all: $(PROGRAMS)

arrays: Arrays.cpp
	$(CXX) $(CXXFLAGS) -o arrays Arrays.cpp

controlstructures: ControlStructures.cpp
	$(CXX) $(CXXFLAGS) -o controlstructures ControlStructures.cpp

functions: Functions.cpp
	$(CXX) $(CXXFLAGS) -o functions Functions.cpp

commonmistakes: CommonMistakes.cpp
	$(CXX) $(CXXFLAGS) -o commonmistakes CommonMistakes.cpp

mathandrandom: MathAndRandom.cpp
	$(CXX) $(CXXFLAGS) -o mathandrandom MathAndRandom.cpp

objectreferences: ObjectReferences.cpp
	$(CXX) $(CXXFLAGS) -o objectreferences ObjectReferences.cpp

wrapper: Wrapper.cpp
	$(CXX) $(CXXFLAGS) -o wrapper Wrapper.cpp

classexample: ClassExample.cpp ClassExample.h
	$(CXX) $(CXXFLAGS) -o classexample ClassExample.cpp

# Runs the programs that do NOT read from stdin.
# (controlstructures reads an integer, so it is left out of "run".)
run: all
	./arrays
	./functions
	./commonmistakes
	./mathandrandom
	./objectreferences
	./wrapper
	./classexample

clean:
	rm -f $(PROGRAMS) $(addsuffix .exe,$(PROGRAMS))
