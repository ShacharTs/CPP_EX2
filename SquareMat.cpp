#include "SquareMat.hpp"
#include <limits>

using namespace std;

// Note to myself
// To access a slot in 2d array is matrix[i * matrix.size + j]


namespace Matrix {
    /**
     * a private helper constructor for all the operators
     * @param dimensionSize .
     */
    SquareMatrix::SquareMatrix(const int dimensionSize, bool) : dimensionSize(dimensionSize) {
        matrix = new float[dimensionSize * dimensionSize]();
    }

    /**
     * Check if both matrix, have the same dimension size
     * @param other
     * @return
     */
    void SquareMatrix::checkdimensionSize(const SquareMatrix &other) const {
        if (this->getDimension() != other.getDimension()) {
            throw invalid_argument("Matrix dimension size must be equals");
        }
    }

    int SquareMatrix::getSize() const {
        return getDimension() * getDimension();
    }

    int SquareMatrix::getDimension() const {
        return this->dimensionSize;
    }

    float countTotal(const SquareMatrix &matrix) {
        float sum = 0;
        for (int i = 0; i < matrix.getDimension(); i++) {
            for (int j = 0; j < matrix.getDimension(); j++) {
                sum += matrix[i][j];
            }
        }
        return sum;
    }


    /**
     * Destructor
     */
    SquareMatrix::~SquareMatrix() {
        delete[] matrix;
    }



    // Copy constructor
    SquareMatrix::SquareMatrix(const SquareMatrix &other)
        : dimensionSize(other.dimensionSize) {
        matrix = new float[getSize()];
        for (int i = 0; i < getDimension() * getDimension(); ++i) {
            matrix[i] = other.matrix[i];
        }
    }

    // Copy assignment operator
    SquareMatrix &SquareMatrix::operator=(const SquareMatrix &other) {
        if (this == &other) {
            return *this; // self-assignment guard
        }
        delete[] matrix;

        matrix = new float[other.getSize()];
        for (int i = 0; i < other.getSize(); ++i) {
            matrix[i] = other.matrix[i];
        }
        return *this;
    }


    /**
     * =============================================================================
     *                              Operator Behavior Note
     * -----------------------------------------------------------------------------
     *          All the operators work in the same way:
     *          this->matrix   => the left-hand side argument (lhs)
     *          other.matrix   => the right-hand side argument (rhs)
     * -----------------------------------------------------------------------------
     */


    float *SquareMatrix::operator[](int row) {
        // writing
        return &matrix[row * getDimension()];
    }

    const float *SquareMatrix::operator[](int row) const {
        // reading
        return &matrix[row * getDimension()];
    }


    SquareMatrix SquareMatrix::operator+(const SquareMatrix &other) const {
        checkdimensionSize(other);
        SquareMatrix temp(other.getDimension(), true);
        for (int i = 0; i < getSize(); i++) {
            temp.matrix[i] = this->matrix[i] + other.matrix[i];
        }
        return temp;
    }


    SquareMatrix SquareMatrix::operator-(const SquareMatrix &other) const {
        checkdimensionSize(other);
        SquareMatrix temp(other.getDimension(), true);
        for (int i = 0; i < getSize(); i++) {
            temp.matrix[i] = this->matrix[i] - other.matrix[i];
        }
        return temp;
    }

    SquareMatrix SquareMatrix::operator-() {
        for (int i = 0; i < getSize(); i++) {
            this->matrix[i] = this->matrix[i] * (-1);
        }
        return *this;
    }

    SquareMatrix SquareMatrix::operator*(const SquareMatrix &other) const {
        checkdimensionSize(other);
        SquareMatrix temp(other.getDimension(), true);
        for (int i = 0; i < this->getDimension(); i++) {
            for (int j = 0; j < getDimension(); j++) {
                float sum = 0;
                for (int k = 0; k < getDimension(); k++) {
                    sum += this->matrix[i * getDimension() + k] * other.matrix[k * getDimension() + j];
                }
                temp.matrix[i * getDimension() + j] = sum;;
            }
        }
        return temp;
    }

    SquareMatrix SquareMatrix::operator%(const SquareMatrix &other) const {
        checkdimensionSize(other);
        SquareMatrix temp(other.getDimension(), true);
        for (int i = 0; i < getSize(); i++) {
            int tempMod = this->matrix[i] * other.matrix[i];
            temp.matrix[i] = tempMod;
        }
        return temp;
    }

    SquareMatrix SquareMatrix::operator*(const float scalar) const {
        SquareMatrix temp(*this);
        for (int i = 0; i < getSize(); i++) {
            temp.matrix[i] = this->matrix[i] * scalar;
        }
        return temp;
    }

    SquareMatrix SquareMatrix::operator%(const int mod) const {
        SquareMatrix temp(*this);
        for (int i = 0; i < getSize(); i++) {
            const int temp1 = this->matrix[i];
            temp.matrix[i] = (temp1 % mod);
        }
        return temp;
    }

    SquareMatrix SquareMatrix::operator/(const float scalar) const {
        if (scalar == 0) {
            throw invalid_argument("Scalar can not be zero");
        }
        SquareMatrix temp(*this);
        for (int i = 0; i < getSize(); i++) {
            const float temp1 = this->matrix[i];
            temp.matrix[i] = temp1 / scalar;
        }
        return temp;
    }

    SquareMatrix SquareMatrix::operator^(int power) const {
        if (power < 0) {
            throw invalid_argument("Power must be positive");
        }
        if (power == 0) {
            SquareMatrix I(*this);
            for (int i = 0; i < getSize(); i++) {
                I.matrix[i] = 1;
            }
            return I;
        }
        SquareMatrix temp(*this);
        if (power > 0) {
            for (int i = 1; i < power; i++) {
                temp = temp * (*this);
            }
        }
        return temp;
    }

    SquareMatrix &SquareMatrix::operator+=(const SquareMatrix &other) {
        checkdimensionSize(other);
        for (int i = 0; i < getSize(); i++) {
            this->matrix[i] += other.matrix[i];
        }
        return *this;
    }

    SquareMatrix &SquareMatrix::operator-=(const SquareMatrix &other) {
        checkdimensionSize(other);
        for (int i = 0; i < getSize(); i++) {
            this->matrix[i] -= other.matrix[i];
        }
        return *this;
    }

    SquareMatrix &SquareMatrix::operator*=(const SquareMatrix &other) {
        checkdimensionSize(other);
        *this = *this * other;
        return *this;
    }

    SquareMatrix &SquareMatrix::operator*=(const float scalar) {
        *this = *this * scalar;
        return *this;
    }


    SquareMatrix &SquareMatrix::operator/=(const float scalar) {
        *this = *this / scalar;
        return *this;
    }

    SquareMatrix &SquareMatrix::operator%=(const SquareMatrix &other) {
        checkdimensionSize(other);
        for (int i = 0; i < getSize(); i++) {
            this->matrix[i] *= other.matrix[i];
        }
        return *this;
    }

    SquareMatrix &SquareMatrix::operator%=(const int mod) {
        *this = *this % mod;
        return *this;
    }

    SquareMatrix &SquareMatrix::operator~() {
        for (int i = 0; i < this->getDimension(); i++) {
            for (int j = i + 1; j < this->getDimension(); j++) {
                const float temp1 = this->matrix[i * getDimension() + j];
                const float temp2 = this->matrix[j * getDimension() + i];
                this->matrix[i * getDimension() + j] = temp2;
                this->matrix[j * getDimension() + i] = temp1;
            }
        }
        return *this;
    }


    bool SquareMatrix::operator==(const SquareMatrix &other) const {
        return Matrix::countTotal(*this) == Matrix::countTotal(other);
    }

    bool SquareMatrix::operator!=(const SquareMatrix &other) const {
        return Matrix::countTotal(*this) != Matrix::countTotal(other);
    }

    bool SquareMatrix::operator<(const SquareMatrix &other) const {
        return Matrix::countTotal(*this) < Matrix::countTotal(other);
    }

    bool SquareMatrix::operator<=(const SquareMatrix &other) const {
        return Matrix::countTotal(*this) <= Matrix::countTotal(other);
    }

    bool SquareMatrix::operator>(const SquareMatrix &other) const {
        return Matrix::countTotal(*this) > Matrix::countTotal(other);
    }

    bool SquareMatrix::operator>=(const SquareMatrix &other) const {
        return Matrix::countTotal(*this) >= Matrix::countTotal(other);
    }

    SquareMatrix &SquareMatrix::operator++() {
        for (int i = 0; i < getSize(); i++) {
            this->matrix[i] += 1;
        }
        return *this;
    }

    SquareMatrix &SquareMatrix::operator--() {
        for (int i = 0; i < getSize(); i++) {
            this->matrix[i] -= 1;
        }
        return *this;
    }

    SquareMatrix SquareMatrix::operator++(int) {
        SquareMatrix temp(*this);
        for (int i = 0; i < this->getSize(); i++) {
            this->matrix[i] += 1;
        }
        return temp;
    }

    SquareMatrix SquareMatrix::operator--(int) {
        SquareMatrix temp(*this);
        for (int i = 0; i < this->getSize(); i++) {
            this->matrix[i] -= 1;
        }
        return temp;
    }


    SquareMatrix operator*(float scalar, const SquareMatrix &mat) {
        return mat * scalar;
    }

    float SquareMatrix::detHelper(const float* matrix, int dim) {
        if (dim == 1) {
            return matrix[0];
        }

        if (dim == 2) {
            return matrix[0] * matrix[3] - matrix[1] * matrix[2];
        }

        float det = 0;
        float* subMatrix = new float[(dim - 1) * (dim - 1)];

        for (int col = 0; col < dim; ++col) {
            // Build submatrix excluding row 0 and column `col`
            int subIndex = 0;
            for (int i = 1; i < dim; ++i) {
                for (int j = 0; j < dim; ++j) {
                    if (j == col) {
                        continue;
                    }
                    subMatrix[subIndex++] = matrix[i * dim + j];
                }
            }

            const float sign = (col % 2 == 0) ? 1.0f : -1.0f;
            det += sign * matrix[col] * detHelper(subMatrix, dim - 1);
        }

        delete[] subMatrix;
        return det;
    }


    float SquareMatrix::operator!() {
        return detHelper(this->matrix, this->getDimension());
    }



    std::ostream &operator<<(std::ostream &out, const SquareMatrix &mat) {
        cout << "Printing matrix" << endl;
        for (int i = 0; i < mat.getDimension(); ++i) {
            for (int j = 0; j < mat.getDimension(); ++j) {
                out << mat.matrix[i * mat.getDimension() + j] << " ";
            }
            out << '\n';
        }
        return out;
    }
}
