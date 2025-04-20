# Simple Square Matrix Library
### Shachar Tsrafati

## Overview
This project implements a `SquareMatrix` class in C++ for working with N×N matrices of floats. It supports: basic arithmetic, scalar operations, element-wise operations, comparison, transpose, determinant, and more.

## Project Structure
- **SquareMat.hpp**: Class declaration and public interface.
- **SquareMat.cpp**: Class implementation (constructors, operators, helpers).
- **test.cpp**: Unit tests using a Doctest framework.

## SquareMatrix Class

### Constructors & Destructors
- **`SquareMatrix(const float (&arr)[N])`**: Creates a matrix from a flat float array of size N = dim².
- **Copy constructor & copy assignment**: Safe copying of matrix data.
- **Destructor**: Releases allocated memory.

### Operators
- **Arithmetic**: `+`, `-` (binary), unary `-` (negation).
- **Matrix multiplication**: `*` (matrix × matrix).
- **Element-wise multiplication**: `%` (multiplies corresponding elements).
- **Scalar operations**: `* scalar`, `/ scalar`, `% int`.
- **Power**: `^` (non-negative integer power; 0 → identity matrix).
- **Increment/Decrement**: `++`, `--` (prefix & postfix).
- **Transpose**: `~` (swap rows and columns in place).
- **Determinant**: `!` (recursive helper for size ≥ 1).
- **Compound assignment**: `+=`, `-=`, `*=`, `/=`, `%=` for matrix and scalar.
- **Comparison**: `==`, `!=`, `<`, `<=`, `>`, `>=` (based on the sum of all elements).
- **Element access**: `operator[](row)[col]` for reading/writing.
- **Stream output**: `operator<<` prints rows line by line.

### Error Handling
- Throws `std::invalid_argument` on dimension mismatch, zero division, invalid power, or non-square input array.
- **Future improvement**: Add bounds checking for `operator[]` to throw `std::out_of_range`.

## Tests
All operators and error cases are covered in `test.cpp`. Tests use the Doctest framework. To run:
1. Install Doctest.
2. Compile and run:
   ```bash
   g++ -std=c++17 -o test SquareMat.cpp test.cpp
   ./test
