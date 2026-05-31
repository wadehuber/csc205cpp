# Makefile for the module04 file I/O example.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program (and the output file)
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = FileIOExample.cpp
PROGRAM = fileio

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe myfile.txt
