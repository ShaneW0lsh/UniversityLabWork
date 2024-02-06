# Makefile for a C++ project with explicit header dependencies

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra

# Source files, header files, and output executable
SRC = Launcher.cpp Kolomychenko_Daniil_231_329_lab62.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = run

# Default target (first target in the file)
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

# Generic rule to build object files from source files
%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJ) $(EXECUTABLE)

