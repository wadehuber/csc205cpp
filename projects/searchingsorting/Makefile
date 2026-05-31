# Makefile for the searching/sorting sample driver.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# Note: csc205/Sorting.h is a header-only template, so it is NOT listed in
# SOURCES (templates compile when included, not separately).
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = SortingSearchingSampleDriver.cpp \
          cards/PlayingCard.cpp \
          cards/Deck.cpp
PROGRAM = sortingsearching

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
