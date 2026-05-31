# Makefile for the top-level IterableExample.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.
#
# The sub-directories (box, collections, genericexample, iterators, tasklist)
# each have their own Makefile.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = IterableExample.cpp
PROGRAM = iterableexample

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
