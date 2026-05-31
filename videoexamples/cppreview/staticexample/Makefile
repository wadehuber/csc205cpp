# Makefile for the cppreview/staticexample example.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Driver + helper class compiled together.
SOURCES = StaticExample.cpp Static.cpp
PROGRAM = staticexample

$(PROGRAM): $(SOURCES) Static.h
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
