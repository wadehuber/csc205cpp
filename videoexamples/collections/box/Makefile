# Makefile for the box generic-class example.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.
#
# Note: Box.h is a header-only template, so it is not compiled on its own --
# only the .cpp files are listed here.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = BoxDriver.cpp Cat.cpp
PROGRAM = boxdriver

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
