#include <iostream>
#include "SquareMat.hpp"

using namespace std;
using namespace Matrix;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("operator +") {
    float data1[] = {1, 2, 3, 4};
    float data2[] = {4, 3, 2, 1};

    SquareMatrix m1(data1, 2);
    SquareMatrix m2(data2, 2);

    cout << m1 << endl;

    cout << m2 << endl;


    SquareMatrix result = m1 + m2;

    cout << result << endl;

    CHECK(result[0][0] == doctest::Approx(5));
    CHECK(result[0][1] == doctest::Approx(5));
    CHECK(result[1][0] == doctest::Approx(5));
    CHECK(result[1][1] == doctest::Approx(5));

}

