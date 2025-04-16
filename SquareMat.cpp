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
        if (this->getDim() != other.getDim()) {
            throw invalid_argument("Matrix dimension size must be equals");
        }
    }

    int SquareMatrix::getSize() const {
        return getDim() * getDim();
    }
    int SquareMatrix::getDim() const {
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
        for (int i = 0; i < getDim() * getDim(); ++i) {
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
        for (int i = 0; i < mat.getDim(); ++i) {
            for (int j = 0; j < mat.getDim(); ++j) {
                out << mat.matrix[i * mat.getDim() + j] << " ";
            }
            out << '\n';
        }
        return out;
    }

    float *SquareMatrix::operator[](int row) { // writing
        return &matrix[row * getDim()];
    }

    const float *SquareMatrix::operator[](int row) const { // reading
        return &matrix[row * getDim()];
    }


    SquareMatrix SquareMatrix::operator+(const SquareMatrix &other) const {
        checkdimensionSize(other);
        SquareMatrix temp(other.getDim(), true);
        for (int i = 0; i < getSize(); i++) {
            temp.matrix[i] = this->matrix[i] + other.matrix[i];
        }
        return temp;
    }


    SquareMatrix SquareMatrix::operator-(const SquareMatrix &other) const {
        checkdimensionSize(other);
        SquareMatrix temp(other.getDim(), true);
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
        SquareMatrix temp(other.getDim(), true);
        for (int i = 0; i < this->getDim(); i++) {
            for (int j = 0; j < getDim(); j++) {
                float sum = 0;
                for (int k = 0; k < getDim(); k++) {
                    sum += this->matrix[i * getDim() + k] * other.matrix[k * getDim() + j];
                }
                temp.matrix[i * getDim() + j] = sum;;
            }
        }
        return temp;
    }

    SquareMatrix SquareMatrix::operator%(const SquareMatrix &other) const {
        checkdimensionSize(other);
        SquareMatrix temp (other.getDim(),true);
        for (int i = 0; i < getSize();i++) {
            int tempMod = this->matrix[i] * other.matrix[i];
            temp.matrix[i] = tempMod;
        }
        return temp;
    }

}
