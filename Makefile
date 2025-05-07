
CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wcast-qual -Wformat=2 -Wundef -Werror=float-equal -Wshadow -Wcast-align -Wunused -Wnull-dereference -Wdouble-promotion -Wfloat-equal -I src/include
LDFLAGS := 

# Source and build directories
SRCDIR := src
OBJDIR := build
INCDIR := src/include

# List all source files here (excluding test files)
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
SOURCES := $(filter-out $(SRCDIR)/main.cpp, $(SOURCES))

# Main file
MAIN := $(SRCDIR)/main.cpp

# Object files
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
MAIN_OBJ := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(MAIN))

# Final executable
TARGET := CookieDB

# Default rule
all: $(TARGET)

# Linking the main binary
$(TARGET): $(MAIN_OBJ) $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Compile each .cpp to .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean