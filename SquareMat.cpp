#include "SquareMat.hpp"
#include <limits>

using namespace std;


//** To access a slot in 2d array is  matrix[i * matrix.size + j]


namespace Matrix {
    SquareMatrix::SquareMatrix(const int size) {
        this->size = size;
        this->matrix = new float [size * size]();

        for (int i = 0; i < this->size; ++i) {
            cout << "Enter row " << i << " values (" << this->size << " numbers): ";
            for (int j = 0; j < this->size; ++j) {
                cin >> matrix[i * this->size + j];
            }
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    SquareMatrix::SquareMatrix(const float sqMatrix[],int size) :size(size) {
        matrix = new float[size * size];
        for (int i = 0; i < size * size; i++) {
            matrix[i] = sqMatrix[i];
        }
    }


    SquareMatrix::~SquareMatrix() {
        delete[] matrix;
    }



    std::ostream& operator<<(std::ostream& out, const SquareMatrix& mat) {
        cout << "Printing matrix" <<endl;
        for (int i = 0; i < mat.size; ++i) {
            for (int j = 0; j < mat.size; ++j) {
                out << mat.matrix[i * mat.size + j] << " ";
            }
            out << '\n';
        }
        return out;
    }




}
