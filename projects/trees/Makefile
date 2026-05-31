# Makefile for the trees project (CSC205 Project 8 starter code).
#
# One program is built here:
#   TreeProjectTestDriver - exercises LinkedBinarySearchTree, LinkedBSTOrderedSet
#                           and Sorting::bstSort
#
# Almost all of the jsjf / csc205 code is generic, so it is HEADER-ONLY
# (templates live entirely in .h files). That is why the program needs only its
# single driver .cpp on the command line -- the headers are pulled in via
# #include.
#
#   make        build the program
#   make run    build and run the program
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

PROGRAM = TreeProjectTestDriver

all: $(PROGRAM)

$(PROGRAM): TreeProjectTestDriver.cpp
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) TreeProjectTestDriver.cpp

run: all
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
