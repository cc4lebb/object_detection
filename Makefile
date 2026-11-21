# Compiler and flags
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Werror -O2 -g -MMD -MP
LDFLAGS  :=
LDLIBS   :=

# Project structure
SRCDIR := src
OBJDIR := build
TARGET := main

# Recursively discover all .cpp files (handles new folders/files on creation)
SRCS := $(shell find $(SRCDIR) -name '*.cpp' 2>/dev/null) $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Link the final binary
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

# Compile source files into object files (auto-creates subdirectories)
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I. -c -o $@ $<

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Run the compiled binary
run: $(TARGET)
	./$(TARGET)

# Auto-dependency tracking (pulled in after first build)
-include $(OBJS:.o=.d)

# Phony targets
.PHONY: all clean run
