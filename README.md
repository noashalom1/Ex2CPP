# Ex2CPP - SquareMat Project

## Author

Noa Patito 
Email: noapatito123@gmail.com

## Overview

This project provides a C++ implementation of a dynamic square matrix class `SquareMat` with a set of arithmetic, comparison, and utility operators.  
The matrix supports various operations including addition, subtraction, multiplication, scalar operations, transpose, determinant calculation, and more.  
The code also includes comprehensive unit testing using the `doctest` framework.

---

## Project Structure

- `SquareMat.hpp` — Header file containing the `SquareMat` class declaration.
- `SquareMat.cpp` — Implementation file for `SquareMat` class methods.
- `main.cpp` — Demonstration program that shows usage of the `SquareMat` class and its features.
- `test.cpp` — Unit tests for `SquareMat` using `doctest`.
- `Makefile` — Provides commands to build, run, test, and clean the project.

---

## Features

- Dynamic allocation of square matrix of doubles.
- Access operator: allows to write and read-only from matrix ([][]).
- Arithmetic operations: `+`, `-`, `*`, `/`, `%`, unary `-`, `^` (power).
- Increment and decrement operators: `++mat`, `mat++`, `--mat`, `mat--`.
- Transpose operator `~`.
- Comparison operators: `==`, `!=`, `<`, `<=`, `>`, `>=`.
- Determinant calculation using Gaussian elimination (`!` operator).
- Compound assignment operators: `+=`, `-=`, `*=`, `/=`, `%=`.
- Overloaded `<<` operator to display the matrix.
- Support for both copy constructor and assignment operator.
- Memory-safe implementation using copy-and-swap idiom.
- Comprehensive test coverage using `doctest`.

---

## How to Build and Run

### Build and Run the Demo
- make Main – Compile all source files and run the main program.
- make test – Run the unit tests
- make valgrind – Check for memory leaks
- make clean – Clean all build files

### Prerequisites
- C++17 or later
- `make`
- `g++` compiler
- `valgrind` (optional, for memory leak checks)

---

## Notes

- The private helper function - `getSum` are tested using a friend class TestHelper.
- The doctest framework is used for lightweight and efficient unit testing.
- Exception handling is used to manage invalid matrix operations (like mismatched sizes or division by zero).
