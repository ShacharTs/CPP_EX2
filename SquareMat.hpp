#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>

namespace Matrix {
    class SquareMatrix {
    private:
        int size;
        double *matrix;

    public:
        // Class
        explicit SquareMatrix(int size);
        ~SquareMatrix();

        // Basic arithmetic operators
        SquareMatrix operator+(const SquareMatrix& other) const;
        SquareMatrix operator-(const SquareMatrix& other) const;
        SquareMatrix operator-() const; // Unary minus
        SquareMatrix operator*(const SquareMatrix& other) const;
        SquareMatrix operator%(const SquareMatrix& other) const; // element-wise

        // Scalar operations
        SquareMatrix operator*(double scalar) const;
        SquareMatrix operator%(int mod) const;
        SquareMatrix operator/(int scalar) const;
        SquareMatrix operator^(int power) const;

        // Compound assignment
        SquareMatrix& operator+=(const SquareMatrix& other);
        SquareMatrix& operator-=(const SquareMatrix& other);
        SquareMatrix& operator*=(const SquareMatrix& other);
        SquareMatrix& operator/=(const SquareMatrix& other);
        SquareMatrix& operator%=(const SquareMatrix& other);
        SquareMatrix& operator*=(double scalar);
        SquareMatrix& operator%=(int mod);
        SquareMatrix& operator/=(int scalar);

        // Increment / Decrement
        // Prefix -> do it and then update
        // Postfix -> update and then do it
        SquareMatrix& operator++();      // Prefix ++
        SquareMatrix operator++(int);    // Postfix ++
        SquareMatrix& operator--();      // Prefix --
        SquareMatrix operator--(int);    // Postfix --

        // Transpose and determinant
        SquareMatrix operator~() const;  // Transpose
        double operator!() const;        // Determinant

        // Element access
        double* operator[](int row);              // Modify
        const double* operator[](int row) const;  // Read-only

        // Comparisons (based on sum of elements)
        bool operator==(const SquareMatrix& other) const;
        bool operator!=(const SquareMatrix& other) const;
        bool operator<(const SquareMatrix& other) const;
        bool operator<=(const SquareMatrix& other) const;
        bool operator>(const SquareMatrix& other) const;
        bool operator>=(const SquareMatrix& other) const;

        // Friend functions
        friend SquareMatrix operator*(double scalar, const SquareMatrix& mat);
        friend std::ostream& operator<<(std::ostream& out, const SquareMatrix& mat);
    };

}


#endif //SQUAREMAT_HPP
