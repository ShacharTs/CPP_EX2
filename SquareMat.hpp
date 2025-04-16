#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP
#include <iostream>
#include <cmath>


namespace Matrix {
    class SquareMatrix {
    private:
        int dimensionSize;
        float *matrix;

        SquareMatrix(int dimensionSize, bool allocateOnly);

        void checkdimensionSize(const SquareMatrix &other) const;




    public:
        // Template constructor for auto-detecting array size
        template<size_t N>
        explicit SquareMatrix(const float (&arr)[N]) {
            // no need to check, this can not happened because of compile
            // if ( arr == nullptr || N == 0) {
            //     throw std::invalid_argument("Array can not be empty");
            // }
            const int dim = std::sqrt(N);
            if (dim * dim != N) {
                throw std::invalid_argument("Array size is not a perfect square.");
            }

            dimensionSize = dim;
            matrix = new float[N];
            for (size_t i = 0; i < N; ++i) {
                matrix[i] = arr[i];
            }
        }
        auto getSize() const -> int;
        auto getDimension() const -> int;
        float countTotal(const SquareMatrix &matrix);

        SquareMatrix(const SquareMatrix &other); // copy constractor
        SquareMatrix &operator=(const SquareMatrix &other); // assignment operator

        // Class destructor
        ~SquareMatrix();

        // Basic arithmetic operators
        SquareMatrix operator+(const SquareMatrix &other) const;
        SquareMatrix operator-(const SquareMatrix &other) const;
        SquareMatrix operator-(); // Unary minus
        SquareMatrix operator*(const SquareMatrix &other) const;
        SquareMatrix operator%(const SquareMatrix &other) const; // element-wise (mult)

        // Scalar operations
        SquareMatrix operator*(float scalar) const;
        SquareMatrix operator%(int mod) const;
        SquareMatrix operator/(float scalar) const;
        SquareMatrix operator^(int power) const;



        // Compound assignment
        SquareMatrix &operator+=(const SquareMatrix &other);
        SquareMatrix &operator-=(const SquareMatrix &other);
        SquareMatrix &operator*=(const SquareMatrix &other);
        SquareMatrix &operator/=(const SquareMatrix &other);
        SquareMatrix &operator%=(const SquareMatrix &other);
        SquareMatrix &operator*=(float scalar);
        SquareMatrix &operator%=(int mod);
        SquareMatrix &operator/=(float scalar);

        // Increment / Decrement
        // Prefix -> do it and then update
        // Postfix -> update and then do it
        SquareMatrix &operator++(); // Prefix ++
        SquareMatrix operator++(int); // Postfix ++
        SquareMatrix &operator--(); // Prefix --
        SquareMatrix operator--(int); // Postfix --

        // Transpose and determinant
        SquareMatrix operator~() const; // Transpose
        float operator!() const; // Determinant

        // Element access
        float *operator[](int row); // for writing
        const float *operator[](int row) const; // for reading


        // Comparisons (based on sum of elements)
        bool operator==(const SquareMatrix &other) const;
        bool operator!=(const SquareMatrix &other) const;
        bool operator<(const SquareMatrix &other) const;
        bool operator<=(const SquareMatrix &other) const;
        bool operator>(const SquareMatrix &other) const;
        bool operator>=(const SquareMatrix &other) const;

        // Friend functions
        friend SquareMatrix operator*(float scalar, const SquareMatrix &mat); // scalar * matrix
        friend std::ostream &operator<<(std::ostream &out, const SquareMatrix &mat); // cout << matrix  . Done
    };
}


#endif //SQUAREMAT_HPP
