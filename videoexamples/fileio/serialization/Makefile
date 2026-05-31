# Makefile for the serialization examples.
#
# NOTE: C++ has no built-in object serialization like Java's Serializable.
# These programs do it MANUALLY by writing/reading each field as text.
#
# Each program is independent and has its own target:
#   make writer     build ObjectWriter (creates students.dat)
#   make reader     build ObjectReader (reads students.dat)
#   make            build both
#   make clean      delete the built programs and students.dat
#
# Run ObjectWriter first, then ObjectReader, to see the Student round-trip.
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: writer reader

writer: ObjectWriter.cpp Student.cpp Student.h
	$(CXX) $(CXXFLAGS) -o writer ObjectWriter.cpp Student.cpp

reader: ObjectReader.cpp Student.cpp Student.h
	$(CXX) $(CXXFLAGS) -o reader ObjectReader.cpp Student.cpp

clean:
	rm -f writer reader *.exe students.dat
