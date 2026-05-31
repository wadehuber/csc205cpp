# Makefile for the polymorphism video examples.
#
# Two separate programs are built:
#   myanimals  - the MyAnimals driver (animals/ + Airplane)
#   firm       - the payroll Firm driver (Staff + employees/)
#
#   make        build both programs
#   make run    build and run both
#   make clean  delete the built programs
#
# On Windows, use "mingw32-make" if you installed MinGW-w64.

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# ---- Program 1: MyAnimals ----
ANIMAL_SOURCES = MyAnimals.cpp \
                 Airplane.cpp \
                 animals/Animal.cpp \
                 animals/Dog.cpp \
                 animals/Cat.cpp \
                 animals/Bat.cpp \
                 animals/Eagle.cpp
ANIMAL_PROGRAM = myanimals

# ---- Program 2: payroll Firm ----
FIRM_SOURCES = payroll/Firm.cpp \
               payroll/Staff.cpp \
               payroll/employees/StaffMember.cpp \
               payroll/employees/Employee.cpp \
               payroll/employees/Executive.cpp \
               payroll/employees/Hourly.cpp \
               payroll/employees/Volunteer.cpp
FIRM_PROGRAM = firm

all: $(ANIMAL_PROGRAM) $(FIRM_PROGRAM)

$(ANIMAL_PROGRAM): $(ANIMAL_SOURCES)
	$(CXX) $(CXXFLAGS) -o $(ANIMAL_PROGRAM) $(ANIMAL_SOURCES)

$(FIRM_PROGRAM): $(FIRM_SOURCES)
	$(CXX) $(CXXFLAGS) -o $(FIRM_PROGRAM) $(FIRM_SOURCES)

run: all
	./$(ANIMAL_PROGRAM)
	./$(FIRM_PROGRAM)

clean:
	rm -f $(ANIMAL_PROGRAM) $(ANIMAL_PROGRAM).exe
	rm -f $(FIRM_PROGRAM) $(FIRM_PROGRAM).exe
