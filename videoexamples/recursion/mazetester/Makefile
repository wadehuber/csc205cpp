# Makefile for the recursive maze solver.
#
#   make        build the program
#   make run    build and run it (then type a maze filename, e.g. testfile.txt)
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# The driver (MazeTester) and the helper classes (Maze, MazeSolver) compile together.
SOURCES = MazeTester.cpp Maze.cpp MazeSolver.cpp
PROGRAM = MazeTester

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
