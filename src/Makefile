# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
LDFLAGS = -lncurses

# Directories
BUILD_DIR = ../build
BIN_DIR = ../bin
SRC_DIR = .  # The current directory where the Makefile and main.cpp are located

# Files
SOURCES = $(shell find . -name '*.cpp')
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = BrickGame

# Debug prints
$(info SOURCES = $(SOURCES))
$(info OBJECTS = $(OBJECTS))

# Targets
all: $(BUILD_DIR) $(EXECUTABLE)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)  # Create build directory if it doesn't exist

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $@  # Link against ncurses

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Create necessary subdirectories in the build directory
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)

.PHONY: all clean test