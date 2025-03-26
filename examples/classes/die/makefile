# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Target executable name
TARGET = snakeeyes

# Source files
SOURCES = snakeeyes.cpp die.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Compile source files
%.o: %.cpp $(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)