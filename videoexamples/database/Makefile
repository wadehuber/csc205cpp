# Makefile for the videoexamples/database examples.
#
#   make        build all the programs
#   make run    build and run them
#   make clean  delete the built programs and the generated csc205.db
#
# These programs use the SQLite C library. You must have the SQLite
# development package installed and link with -lsqlite3 (placed AFTER the
# source files on the command line).
#
#   Debian/Ubuntu/WSL:  sudo apt-get install libsqlite3-dev
#   Windows (MSYS2):    pacman -S mingw-w64-x86_64-sqlite3
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDLIBS = -lsqlite3

PROGRAMS = sqlitetest databaseexample

all: $(PROGRAMS)

sqlitetest: SQLiteTest.cpp
	$(CXX) $(CXXFLAGS) -o sqlitetest SQLiteTest.cpp $(LDLIBS)

databaseexample: DatabaseExample.cpp
	$(CXX) $(CXXFLAGS) -o databaseexample DatabaseExample.cpp $(LDLIBS)

run: all
	./sqlitetest
	./databaseexample

clean:
	rm -f $(PROGRAMS) $(addsuffix .exe,$(PROGRAMS)) csc205.db
