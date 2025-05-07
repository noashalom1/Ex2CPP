# Source and header files
SRC = SquareMat.cpp
HDR = SquareMat.hpp
MAIN = main.cpp
TEST = test.cpp

# Output binary files
MAIN_EXE = Main
TEST_EXE = Test

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# ===========================
# Build and run the demo program
# Usage: make Main
# ===========================
Main: $(SRC) $(MAIN)
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXE) $(SRC) $(MAIN)

# ===========================
# Build and run unit tests using doctest
# Usage: make test
# ===========================
test: $(SRC) $(TEST)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXE) $(SRC) $(TEST)
	./$(TEST_EXE)

# ===========================
# Run valgrind for memory leak check
# Usage: make valgrind
# ===========================
valgrind: $(SRC) $(MAIN)
	$(CXX) $(CXXFLAGS) -g -o $(MAIN_EXE) $(SRC) $(MAIN)
	valgrind --leak-check=full --track-origins=yes ./$(MAIN_EXE)

# ===========================
# Clean up binary and temporary files
# Usage: make clean
# ===========================
clean:
	rm -f $(MAIN_EXE) $(TEST_EXE) *.o
