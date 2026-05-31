# Makefile for the tasklist collection example.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.
#
# Priority.h, ToDoList.h and GetItDone.h are headers; the .cpp files below are
# compiled together into one program.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = TaskDriver.cpp GetItDone.cpp Task.cpp
PROGRAM = taskdriver

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
