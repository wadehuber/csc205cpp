# Makefile for the module06 collections example.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.
#
# Note: MyCollection and EasyCollection are header-only templates, so
# they are NOT listed here -- only the .cpp files need compiling.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = ModuleFive.cpp PlacesIveBeen.cpp
PROGRAM = collections

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
