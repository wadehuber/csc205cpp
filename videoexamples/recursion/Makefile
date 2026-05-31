# Makefile for the root-level recursion / algorithm-analysis video examples.
#
#   make        build all the programs
#   make run    build and run them
#   make clean  delete the built programs
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Each example program is independent and has its own main().
PROGRAMS = Algorithms AnalyzeLoops RecursionVsLoop RecursiveDefinition

all: $(PROGRAMS)

Algorithms: Algorithms.cpp
	$(CXX) $(CXXFLAGS) -o Algorithms Algorithms.cpp

AnalyzeLoops: AnalyzeLoops.cpp
	$(CXX) $(CXXFLAGS) -o AnalyzeLoops AnalyzeLoops.cpp

RecursionVsLoop: RecursionVsLoop.cpp
	$(CXX) $(CXXFLAGS) -o RecursionVsLoop RecursionVsLoop.cpp

RecursiveDefinition: RecursiveDefinition.cpp
	$(CXX) $(CXXFLAGS) -o RecursiveDefinition RecursiveDefinition.cpp

run: $(PROGRAMS)
	./Algorithms
	./AnalyzeLoops
	./RecursionVsLoop
	./RecursiveDefinition

clean:
	rm -f $(PROGRAMS) $(addsuffix .exe,$(PROGRAMS))
