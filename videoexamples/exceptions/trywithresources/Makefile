# Makefile for the try-with-resources / RAII example.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# TryWithResourcesExample (main) uses the OpenClose class. Compile together.
SOURCES = TryWithResourcesExample.cpp OpenClose.cpp
PROGRAM = TryWithResourcesExample

$(PROGRAM): $(SOURCES) OpenClose.h
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
