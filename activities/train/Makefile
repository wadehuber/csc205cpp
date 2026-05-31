# Makefile for the train activity.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.
#
# Note: TrainCar is a header-only template, so it is not listed in SOURCES.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = TrainDriver.cpp Train.cpp
PROGRAM = traindriver

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
