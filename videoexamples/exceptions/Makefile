# Makefile for the root-level exception video examples.
#
#   make        build all the programs
#   make run    build and run the non-interactive ones
#   make clean  delete the built programs
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Each example program is independent and has its own main().
PROGRAMS = ExceptionExample ExceptionExample2 ExceptionProp ExceptionsMultiCatch FinallyExample

all: $(PROGRAMS)

ExceptionExample: ExceptionExample.cpp
	$(CXX) $(CXXFLAGS) -o ExceptionExample ExceptionExample.cpp

ExceptionExample2: ExceptionExample2.cpp
	$(CXX) $(CXXFLAGS) -o ExceptionExample2 ExceptionExample2.cpp

ExceptionProp: ExceptionProp.cpp
	$(CXX) $(CXXFLAGS) -o ExceptionProp ExceptionProp.cpp

ExceptionsMultiCatch: ExceptionsMultiCatch.cpp
	$(CXX) $(CXXFLAGS) -o ExceptionsMultiCatch ExceptionsMultiCatch.cpp

FinallyExample: FinallyExample.cpp
	$(CXX) $(CXXFLAGS) -o FinallyExample FinallyExample.cpp

# Run the non-interactive examples (FinallyExample reads from stdin).
run: $(PROGRAMS)
	./ExceptionExample
	./ExceptionExample2
	./ExceptionProp
	./ExceptionsMultiCatch

clean:
	rm -f $(PROGRAMS) $(addsuffix .exe,$(PROGRAMS))
