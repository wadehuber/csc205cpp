# Makefile for the bufferedio examples.
#
# Each program is independent and has its own target:
#   make consoleinput   build ConsoleInputDemo
#   make output         build OutputExamples
#   make reader         build TextFileReader
#   make writer         build TextFileWriter
#   make                build all of them
#   make clean          delete the built programs and generated output.txt
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: consoleinput output reader writer

consoleinput: ConsoleInputDemo.cpp
	$(CXX) $(CXXFLAGS) -o consoleinput ConsoleInputDemo.cpp

output: OutputExamples.cpp
	$(CXX) $(CXXFLAGS) -o output OutputExamples.cpp

reader: TextFileReader.cpp
	$(CXX) $(CXXFLAGS) -o reader TextFileReader.cpp

writer: TextFileWriter.cpp
	$(CXX) $(CXXFLAGS) -o writer TextFileWriter.cpp

clean:
	rm -f consoleinput output reader writer *.exe output.txt
