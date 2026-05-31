# Makefile for the cppreview/strings examples.
#
#   make        build all the programs
#   make run    build and run them
#   make clean  delete the built programs
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

PROGRAMS = stringexamples morestringexamples stringsandcharacters sentences

all: $(PROGRAMS)

# Driver + helper class (String205) compiled together.
stringexamples: StringExamples.cpp String205.cpp String205.h
	$(CXX) $(CXXFLAGS) -o stringexamples StringExamples.cpp String205.cpp

morestringexamples: MoreStringExamples.cpp
	$(CXX) $(CXXFLAGS) -o morestringexamples MoreStringExamples.cpp

stringsandcharacters: StringsAndCharacters.cpp
	$(CXX) $(CXXFLAGS) -o stringsandcharacters StringsAndCharacters.cpp

sentences: Sentences.cpp
	$(CXX) $(CXXFLAGS) -o sentences Sentences.cpp

run: all
	./stringexamples
	./morestringexamples
	./stringsandcharacters
	./sentences

clean:
	rm -f $(PROGRAMS) $(addsuffix .exe,$(PROGRAMS))
