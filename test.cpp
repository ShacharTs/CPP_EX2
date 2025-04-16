#include <iostream>
#include "SquareMat.hpp"

using namespace std;
using namespace Matrix;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("Invalid array") {
    cout << "\n=== Running TEST_CASE: Invalid array ===\n";
    float arr1[] = {1, 2, 3, 4, 5};
    cout << "Array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }
    CHECK_THROWS_AS(SquareMatrix m1(arr1), invalid_argument);
    cout << "\n========================================\n";
}

TEST_CASE("Invalid dim size (2 Matrix)") {
    cout << "\n=== Running TEST_CASE: Invalid dim size (2 Matrix) ===\n";
    float arr1[] = {1, 2, 3, 4};
    float arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Array1: ";
    for (int i = 0; i < 4; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "Array2: ";
    for (int i = 0; i < 9; i++) {
        cout << arr2[i] << " ";
    }
    SquareMatrix m1(arr1);
    SquareMatrix m2(arr2);
    CHECK_THROWS_AS(SquareMatrix m3 = m1+m2, invalid_argument);
    cout << "\n========================================\n";
}


TEST_CASE("operator +") {
    cout << "\n=== Running TEST_CASE: operator + ===\n";
    float arr1[] = {1, 2, 3, 4};
    float arr2[] = {4, 3, 2, 1};
    SquareMatrix m1(arr1);
    SquareMatrix m2(arr2);
    SquareMatrix result = m1 + m2;
    CHECK(result[0][0] == doctest::Approx(5));
    CHECK(result[0][1] == doctest::Approx(5));
    CHECK(result[1][0] == doctest::Approx(5));
    CHECK(result[1][1] == doctest::Approx(5));
    cout << "\n========================================\n";
}

TEST_CASE("operator -") {
    cout << "\n=== Running TEST_CASE: operator - ===\n";
    float arr1[] = {1, 2, 3, 4};
    float arr2[] = {4, 3, 2, 1};
    SquareMatrix m1(arr1);
    SquareMatrix m2(arr2);
    SquareMatrix result = m1 - m2;
    CHECK(result[0][0] == doctest::Approx(-3));
    CHECK(result[0][1] == doctest::Approx(-1));
    CHECK(result[1][0] == doctest::Approx(1));
    CHECK(result[1][1] == doctest::Approx(3));
    cout << "\n========================================\n";
}
TEST_CASE("operator - (Unary numeral)") {
    cout << "\n=== Running TEST_CASE: operator - (Unary numeral) ===\n";
    float arr1[] = {1, 2, 3, 4};
    SquareMatrix m1(arr1);
    -m1;
    cout << "Check operator - (Unary numeral)" << endl;
    CHECK(m1[0][0] == doctest::Approx(-1));
    CHECK(m1[0][1] == doctest::Approx(-2));
    CHECK(m1[1][0] == doctest::Approx(-3));
    CHECK(m1[1][1] == doctest::Approx(-4));
    cout << "\n========================================\n";
}
