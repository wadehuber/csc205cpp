# Makefile for the inheritance video examples.
#
# This folder holds two independent programs:
#   myanimals          - the Animal / Dog / Cat / SugarGlider hierarchy
#   overloadrideexample- the overload-vs-override example (overloadvsride/)
#
#   make            build both programs
#   make run        build and run both
#   make clean      delete the built programs
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

ANIMALS_SOURCES = MyAnimals.cpp \
                  animals/Animal.cpp \
                  animals/Cat.cpp \
                  animals/Dog.cpp \
                  animals/SugarGlider.cpp
ANIMALS_PROGRAM = myanimals

OVERLOAD_SOURCES = overloadvsride/OverLoadRideExample.cpp \
                   overloadvsride/Base.cpp \
                   overloadvsride/Derived.cpp
OVERLOAD_PROGRAM = overloadrideexample

all: $(ANIMALS_PROGRAM) $(OVERLOAD_PROGRAM)

$(ANIMALS_PROGRAM): $(ANIMALS_SOURCES)
	$(CXX) $(CXXFLAGS) -o $(ANIMALS_PROGRAM) $(ANIMALS_SOURCES)

$(OVERLOAD_PROGRAM): $(OVERLOAD_SOURCES)
	$(CXX) $(CXXFLAGS) -o $(OVERLOAD_PROGRAM) $(OVERLOAD_SOURCES)

run: all
	./$(ANIMALS_PROGRAM)
	./$(OVERLOAD_PROGRAM)

clean:
	rm -f $(ANIMALS_PROGRAM) $(ANIMALS_PROGRAM).exe
	rm -f $(OVERLOAD_PROGRAM) $(OVERLOAD_PROGRAM).exe
