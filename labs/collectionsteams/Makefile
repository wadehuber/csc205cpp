# Makefile for the collectionsteams starter code.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.
#
# Note: Team and ArrayListTeam are header-only templates (in csc205/),
# so they are not listed in SOURCES.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = TeamCollection.cpp
PROGRAM = teamcollection

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
