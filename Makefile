# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11 -Wall -Wextra

# Target executable
TARGET := RTES_project

# Source files
SRCS := main.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
