# Makefile for the Towers of Hanoi recursion example.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# The driver (SolveTowers) and the helper class (TowersOfHanoi) compile together.
SOURCES = SolveTowers.cpp TowersOfHanoi.cpp
PROGRAM = SolveTowers

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
