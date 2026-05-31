# Makefile for the parsing examples.
#
# Each program is independent and has its own target:
#   make strings    build ParsingStrings
#   make scanner    build ParsingWithScanner
#   make split      build ParsingWithSplit
#   make            build all of them
#   make clean      delete the built programs
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: strings scanner split

strings: ParsingStrings.cpp
	$(CXX) $(CXXFLAGS) -o strings ParsingStrings.cpp

scanner: ParsingWithScanner.cpp
	$(CXX) $(CXXFLAGS) -o scanner ParsingWithScanner.cpp

split: ParsingWithSplit.cpp
	$(CXX) $(CXXFLAGS) -o split ParsingWithSplit.cpp

clean:
	rm -f strings scanner split *.exe
