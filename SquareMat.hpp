#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP
#include <iostream>



namespace Matrix {
    class SquareMatrix {
    private:
        int dimensionSize;
        float *matrix;

        SquareMatrix(int dimensionSize, bool allocateOnly);
        void checkdimensionSize(const SquareMatrix &other) const;

    public:
        // Class constractor
        //explicit SquareMatrix(int size);
        explicit SquareMatrix(const float matrix[], int dimensionSize);

        SquareMatrix(const SquareMatrix& other); // copy constractor
        SquareMatrix& operator=(const SquareMatrix& other); // assignment operator

        // Class destructor
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
        float operator!() const;        // Determinant

        // Element access
        float* operator[](int row);              // for writing
        const float* operator[](int row) const;  // for reading


        // Comparisons (based on sum of elements)
        bool operator==(const SquareMatrix& other) const;
        bool operator!=(const SquareMatrix& other) const;
        bool operator<(const SquareMatrix& other) const;
        bool operator<=(const SquareMatrix& other) const;
        bool operator>(const SquareMatrix& other) const;
        bool operator>=(const SquareMatrix& other) const;

        // Friend functions
        friend SquareMatrix operator*(float scalar, const SquareMatrix& mat); // scalar * matrix
        friend std::ostream& operator<<(std::ostream& out, const SquareMatrix& mat); // cout << matrix  . Done


    };


}


#endif //SQUAREMAT_HPP
