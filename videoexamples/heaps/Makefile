# Makefile for the heaps video examples.
#
# Two programs are built here:
#   HeapExample   - LinkedHeap / LinkedBinarySearchTree demo
#   SortPhoneList - heapSort demo on an array of Contacts
#
# The priority-queue driver (PQTester) has its own Makefile in priorityqueue/.
#
# Almost all of the jsjf / csc205 code is generic, so it is HEADER-ONLY
# (templates live entirely in .h files). That is why each program needs only
# its single driver .cpp on the command line -- the headers are pulled in via
# #include.
#
#   make        build both programs
#   make run    build and run both
#   make clean  delete the built programs
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

HEAP_PROGRAM = HeapExample
SORT_PROGRAM = SortPhoneList

all: $(HEAP_PROGRAM) $(SORT_PROGRAM)

$(HEAP_PROGRAM): HeapExample.cpp
	$(CXX) $(CXXFLAGS) -o $(HEAP_PROGRAM) HeapExample.cpp

$(SORT_PROGRAM): SortPhoneList.cpp
	$(CXX) $(CXXFLAGS) -o $(SORT_PROGRAM) SortPhoneList.cpp

run: all
	./$(HEAP_PROGRAM)
	./$(SORT_PROGRAM)

clean:
	rm -f $(HEAP_PROGRAM) $(HEAP_PROGRAM).exe
	rm -f $(SORT_PROGRAM) $(SORT_PROGRAM).exe
