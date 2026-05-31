# Makefile for the collections project.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.
#
# Note: Bag, Team, MyBag and BagTeam are header-only templates, so they
# are NOT listed here -- only the .cpp files need compiling.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = CollectionsProject.cpp
PROGRAM = collections

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
