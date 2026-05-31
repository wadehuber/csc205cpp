# Makefile for the lists video examples.
#
# Two separate programs are built:
#   LinkedListDriver  - uses the csc205 LinkedList we implemented
#   ListExamples      - uses the jsjf array-based ordered/unordered lists
#
#   make        build both programs (default)
#   make run    build and run both
#   make clean  delete the built programs
#
# Almost every data structure here is a GENERIC class, which in C++ means a
# header-only template (.h with everything, no .cpp). Therefore the only .cpp
# files are the drivers; the templates are pulled in via #include and need no
# entry in SOURCES.
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# ---- Program 1: LinkedListDriver (csc205 LinkedList) ----
LINKEDLIST_SOURCES = LinkedListDriver.cpp
LINKEDLIST_PROGRAM = LinkedListDriver

# ---- Program 2: ListExamples (jsjf array lists) ----
LISTEXAMPLES_SOURCES = ListExamples.cpp
LISTEXAMPLES_PROGRAM = ListExamples

all: $(LINKEDLIST_PROGRAM) $(LISTEXAMPLES_PROGRAM)

$(LINKEDLIST_PROGRAM): $(LINKEDLIST_SOURCES)
	$(CXX) $(CXXFLAGS) -o $(LINKEDLIST_PROGRAM) $(LINKEDLIST_SOURCES)

$(LISTEXAMPLES_PROGRAM): $(LISTEXAMPLES_SOURCES)
	$(CXX) $(CXXFLAGS) -o $(LISTEXAMPLES_PROGRAM) $(LISTEXAMPLES_SOURCES)

run: all
	./$(LINKEDLIST_PROGRAM)
	./$(LISTEXAMPLES_PROGRAM)

clean:
	rm -f $(LINKEDLIST_PROGRAM) $(LINKEDLIST_PROGRAM).exe
	rm -f $(LISTEXAMPLES_PROGRAM) $(LISTEXAMPLES_PROGRAM).exe
