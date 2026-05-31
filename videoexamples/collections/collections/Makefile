# Makefile for the Java Collections API examples.
#
#   make        build all the programs
#   make run    build and run them
#   make clean  delete the built programs
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

PROGRAMS = arraylistexample hashmapexample gradebook

all: $(PROGRAMS)

arraylistexample: ArrayListExample.cpp
	$(CXX) $(CXXFLAGS) -o arraylistexample ArrayListExample.cpp

hashmapexample: HashMapExample.cpp
	$(CXX) $(CXXFLAGS) -o hashmapexample HashMapExample.cpp

gradebook: GradeBook.cpp
	$(CXX) $(CXXFLAGS) -o gradebook GradeBook.cpp

run: all
	./arraylistexample
	./hashmapexample
	./gradebook

clean:
	rm -f $(PROGRAMS) $(addsuffix .exe,$(PROGRAMS))
