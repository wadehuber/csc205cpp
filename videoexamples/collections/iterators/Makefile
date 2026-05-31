# Makefile for the iterators examples.
#
#   make        build all the programs
#   make run    build and run them
#   make clean  delete the built programs
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.
#
# Note: EvenNumbers.h is a header-only class, so it is not compiled on its own.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

PROGRAMS = iteratorexample stringiterator

all: $(PROGRAMS)

iteratorexample: IteratorExample.cpp EvenNumbers.h
	$(CXX) $(CXXFLAGS) -o iteratorexample IteratorExample.cpp

stringiterator: StringIterator.cpp
	$(CXX) $(CXXFLAGS) -o stringiterator StringIterator.cpp

run: all
	./iteratorexample
	./stringiterator

clean:
	rm -f $(PROGRAMS) $(addsuffix .exe,$(PROGRAMS))
