# Makefile for the module03 polymorphism example.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = PolymorphismDriver.cpp \
          animals/Animal.cpp \
          animals/Dog.cpp \
          animals/Bear.cpp \
          fighters/Boxer.cpp
PROGRAM = polymorphism

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
