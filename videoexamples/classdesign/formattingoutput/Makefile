# Makefile for the formattingoutput examples.
#
#   make        build all the programs
#   make run    build and run them
#   make clean  delete the built programs
#
# This directory has three independent programs, each built as its own target.
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

PROGRAMS = formattingdoubles numberformatting printfexample

all: $(PROGRAMS)

formattingdoubles: FormattingDoubles.cpp
	$(CXX) $(CXXFLAGS) -o formattingdoubles FormattingDoubles.cpp

numberformatting: NumberFormatting.cpp
	$(CXX) $(CXXFLAGS) -o numberformatting NumberFormatting.cpp

printfexample: PrintfExample.cpp
	$(CXX) $(CXXFLAGS) -o printfexample PrintfExample.cpp

run: all
	./formattingdoubles
	./numberformatting
	./printfexample

clean:
	rm -f $(PROGRAMS) $(addsuffix .exe,$(PROGRAMS))
