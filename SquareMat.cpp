#include "SquareMat.hpp"
#include <limits>

using namespace std;


//** To access a slot in 2d array is  matrix[i * matrix.size + j]


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
        if (this->dimensionSize != other.dimensionSize) {
            throw invalid_argument("Matrix dimension size must be equals");
        }
    }

    int SquareMatrix::getSize() const {
        return dimensionSize * dimensionSize;
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
        matrix = new float[dimensionSize * dimensionSize];
        for (int i = 0; i < dimensionSize * dimensionSize; ++i) {
            matrix[i] = other.matrix[i];
        }
    }

    // Copy assignment operator
    SquareMatrix &SquareMatrix::operator=(const SquareMatrix &other) {
        if (this == &other) {
            return *this; // self-assignment guard
        }
        delete[] matrix;

        dimensionSize = other.dimensionSize;
        matrix = new float[dimensionSize * dimensionSize];
        for (int i = 0; i < dimensionSize * dimensionSize; ++i) {
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


    /**
     * Printing the matrix
     * @return
     */
    std::ostream &operator<<(std::ostream &out, const SquareMatrix &mat) {
        cout << "Printing matrix" << endl;
        for (int i = 0; i < mat.dimensionSize; ++i) {
            for (int j = 0; j < mat.dimensionSize; ++j) {
                out << mat.matrix[i * mat.dimensionSize + j] << " ";
            }
            out << '\n';
        }
        return out;
    }

    float *SquareMatrix::operator[](int row) { // writing
        return &matrix[row * dimensionSize];
    }

    const float *SquareMatrix::operator[](int row) const { // reading
        return &matrix[row * dimensionSize];
    }


    SquareMatrix SquareMatrix::operator+(const SquareMatrix &other) const {
        checkdimensionSize(other);
        SquareMatrix temp(other.dimensionSize, true);
        for (int i = 0; i < dimensionSize * dimensionSize; i++) {
            temp.matrix[i] = this->matrix[i] + other.matrix[i];
        }
        return temp;
    }


    SquareMatrix SquareMatrix::operator-(const SquareMatrix &other) const {
        checkdimensionSize(other);
        SquareMatrix temp(other.dimensionSize, true);
        for (int i = 0; i < dimensionSize * dimensionSize; i++) {
            temp.matrix[i] = this->matrix[i] - other.matrix[i];
        }
        return temp;
    }

    SquareMatrix SquareMatrix::operator-() {
        for (int i = 0; i < this->dimensionSize * this->dimensionSize; i++) {
            this->matrix[i] = this->matrix[i] * (-1);
        }
        return *this;
    }

    SquareMatrix SquareMatrix::operator*(const SquareMatrix &other) const {
        checkdimensionSize(other);
        SquareMatrix temp(other.dimensionSize, true);
        for (int i = 0; i < this->dimensionSize; i++) {
            for (int j = 0; j < dimensionSize; j++) {
                float sum = 0;
                for (int k = 0; k < dimensionSize; k++) {
                    sum += this->matrix[i * dimensionSize + k] * other.matrix[k * dimensionSize + j];
                }
                temp.matrix[i * dimensionSize + j] = sum;;
            }
        }
        return temp;
    }

    SquareMatrix SquareMatrix::operator%(const SquareMatrix &other) const {
        checkdimensionSize(other);
        SquareMatrix temp (other.dimensionSize,true);
        for (int i = 0; i < getSize();i++) {
            int tempMod = this->matrix[i] * other.matrix[i];
            temp.matrix[i] = tempMod;
        }
        return temp;
    }

}
