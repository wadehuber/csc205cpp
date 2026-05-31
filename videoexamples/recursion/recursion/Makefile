# Makefile for the recursion examples (nested recursion/recursion folder).
#
#   make        build all the programs
#   make run    build and run them
#   make clean  delete the built programs
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Each example program is independent and has its own main().
PROGRAMS = RecursionExamples RecursionWithArrays RecursionWithStrings RecursiveMathFunctions

all: $(PROGRAMS)

RecursionExamples: RecursionExamples.cpp
	$(CXX) $(CXXFLAGS) -o RecursionExamples RecursionExamples.cpp

RecursionWithArrays: RecursionWithArrays.cpp
	$(CXX) $(CXXFLAGS) -o RecursionWithArrays RecursionWithArrays.cpp

RecursionWithStrings: RecursionWithStrings.cpp
	$(CXX) $(CXXFLAGS) -o RecursionWithStrings RecursionWithStrings.cpp

RecursiveMathFunctions: RecursiveMathFunctions.cpp
	$(CXX) $(CXXFLAGS) -o RecursiveMathFunctions RecursiveMathFunctions.cpp

run: $(PROGRAMS)
	./RecursionExamples
	./RecursionWithArrays
	./RecursionWithStrings
	./RecursiveMathFunctions

clean:
	rm -f $(PROGRAMS) $(addsuffix .exe,$(PROGRAMS))
