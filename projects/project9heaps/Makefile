# Makefile for Project 9 (heaps): a stack and a queue built on a heap.
#
# One program is built here:
#   Project9TestDriver - exercises HeapStack / HeapQueue and Sorting.smallest_n
#
# Almost all of the jsjf / csc205 code is generic, so it is HEADER-ONLY
# (templates live entirely in .h files). That is why the program needs only its
# single driver .cpp on the command line -- the headers are pulled in via
# #include.
#
#   make        build the program
#   make run    build and run
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

PROGRAM = Project9TestDriver

all: $(PROGRAM)

$(PROGRAM): Project9TestDriver.cpp
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) Project9TestDriver.cpp

run: all
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
