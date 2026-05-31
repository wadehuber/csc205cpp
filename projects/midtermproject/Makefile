# Makefile for the CSC205 midterm project starter code.
#
#   make        build the program (default)
#   make run    build and run it
#   make clean  delete the built program
#
# FastQueue, FastStack and LinkedList are GENERIC classes, which in C++ means
# header-only templates (.h with everything, no .cpp). They are pulled in via
# #include and need no entry in SOURCES -- the only .cpp file is the driver.
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = MidtermExam.cpp
PROGRAM = MidtermExam

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
