# Makefile for the stacks & queues project.
#
# One program is built:
#   SQProjectSampleDriver - exercises LinkedQueue, LinkedStack, StackQueueUtil
#
#   make        build the program (default)
#   make run    build and run the program
#   make clean  delete the built program
#
# The linked data structures (LinearNode, LinkedQueue, LinkedStack) and the
# ADT interfaces (QueueADT, StackADT) are GENERIC classes, which in C++ means
# header-only templates (.h with everything, no .cpp). They are pulled in via
# #include and need no entry in SOURCES. The only .cpp files are the driver
# and the (non-generic) StackQueueUtil utility class.
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

PROGRAM = SQProjectSampleDriver
SOURCES = SQProjectSampleDriver.cpp csc205/StackQueueUtil.cpp

all: $(PROGRAM)

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: all
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
