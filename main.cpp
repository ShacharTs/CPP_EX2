#include <iostream>
#include "SquareMat.hpp"
using namespace std;
using namespace Matrix;


int main() {


    float array[] = {1,2,3,4};
    SquareMatrix matrix2 (array,2);

    cout << matrix2 << endl;
}