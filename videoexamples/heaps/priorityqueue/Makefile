# Makefile for the priority-queue example.
#
#   PQTester - drives PriorityQueue<std::string>
#
# PriorityQueue, PrioritizedObject and the jsjf heap it uses are all generic
# and HEADER-ONLY, so only the driver .cpp needs to be compiled.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

PQ_PROGRAM = PQTester

all: $(PQ_PROGRAM)

$(PQ_PROGRAM): PQTester.cpp
	$(CXX) $(CXXFLAGS) -o $(PQ_PROGRAM) PQTester.cpp

run: all
	./$(PQ_PROGRAM)

clean:
	rm -f $(PQ_PROGRAM) $(PQ_PROGRAM).exe
