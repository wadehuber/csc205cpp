# Makefile for the "defining" custom-exception-with-a-field example.
#
#   make        build the program
#   make run    build and run it
#   make clean  delete the built program
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# BankAccount.cpp holds main() AND the BankAccount methods; it uses
# InsufficientFundsException (header-only). Compile them together.
SOURCES = BankAccount.cpp
PROGRAM = BankAccount

$(PROGRAM): $(SOURCES) BankAccount.h InsufficientFundsException.h
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(SOURCES)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(PROGRAM).exe
