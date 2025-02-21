# Compiler
CXX = g++
CXXFLAGS = -Wall -g

# Files
SRC = main.cpp mathfuncs.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable
EXEC = output

# Default target
all: $(EXEC)

# Link object files to create executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp file into a .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(EXEC)

# Ensure object files are always checked
.PHONY: all clean