# Makefile for the exceptionsunfortunate lab (starter code).
#
#   make        build the program
#   make run    build and run it (reads a starting count)
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = UnfortunateExceptions.cpp UnfortunateEvents.cpp
PROGRAM = unfortunateexceptions

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
