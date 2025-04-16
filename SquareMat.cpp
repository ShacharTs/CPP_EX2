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


    /**
     * Printing the matrix
     * @return
     */
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

    float *SquareMatrix::operator[](int row) { // writing
        return &matrix[row * getDimension()];
    }

    const float *SquareMatrix::operator[](int row) const { // reading
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
        SquareMatrix temp (other.getDimension(),true);
        for (int i = 0; i < getSize();i++) {
            int tempMod = this->matrix[i] * other.matrix[i];
            temp.matrix[i] = tempMod;
        }
        return temp;
    }

}
