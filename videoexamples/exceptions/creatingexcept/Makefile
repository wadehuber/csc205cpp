# Makefile for the "creatingexcept" custom-exception example.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# CreatingExceptions uses the YouDidTheWrongThingException class (header-only),
# so only the .cpp needs compiling.
SOURCES = CreatingExceptions.cpp
PROGRAM = CreatingExceptions

$(PROGRAM): $(SOURCES) YouDidTheWrongThingException.h
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
