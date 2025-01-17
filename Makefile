# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -pthread -Wall -Wextra

# Directories
SRC_DIR = ./scr/app
BUILD_DIR = ./build
BIN_DIR = ./bin

# Target executable
TARGET = $(BIN_DIR)/main

# Source files
SRCS = main.cpp \
       $(SRC_DIR)/fileHandling/IO.cpp \
       $(SRC_DIR)/processMang/processMag.cpp \
       $(SRC_DIR)/encryptDecrypt/eDecrypt.cpp

# Object files
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compiling
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean
