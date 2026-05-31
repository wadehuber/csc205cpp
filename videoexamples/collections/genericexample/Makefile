# Makefile for the generics example.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.
#
# Note: Thing.h is a header-only template, so it is not compiled on its own.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = GenericsExample.cpp
PROGRAM = genericsexample

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
