#include <iostream>
#include "SquareMat.hpp"

using namespace std;
using namespace Matrix;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

SquareMatrix createMatrix(float val = 1) {
    float arr[9];
    for (int i = 0; i < 9; ++i)
        arr[i] = val + i;
    return SquareMatrix(arr);
}


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
    SquareMatrix m1 = createMatrix(); // 1–9
    SquareMatrix m2 = createMatrix(10); // 10–18
    SquareMatrix result = m1 + m2;

    for (int i = 0; i < m1.getDimension(); ++i) {
        for (int j = 0; j < m1.getDimension(); ++j) {
            CHECK(result[i][j] == doctest::Approx(m1[i][j] + m2[i][j]));
        }
    }

    cout << "\n========================================\n";
}


TEST_CASE("operator -") {
    cout << "\n=== Running TEST_CASE: operator - ===\n";
    SquareMatrix m1 = createMatrix(10);
    SquareMatrix m2 = createMatrix(1);
    SquareMatrix result = m1 - m2;

    for (int i = 0; i < m1.getDimension(); ++i) {
        for (int j = 0; j < m1.getDimension(); ++j) {
            CHECK(result[i][j] == doctest::Approx(m1[i][j] - m2[i][j]));
        }
    }

    cout << "\n========================================\n";
}


TEST_CASE("operator - (Unary numeral)") {
    cout << "\n=== Running TEST_CASE: operator - (Unary numeral) ===\n";
    SquareMatrix m1 = createMatrix();
    -m1;

    for (int i = 0; i < m1.getDimension(); ++i) {
        for (int j = 0; j < m1.getDimension(); ++j) {
            CHECK(m1[i][j] == doctest::Approx(-(i * m1.getDimension() + j + 1)));
        }
    }

    cout << "\n========================================\n";
}


TEST_CASE("operator *") {
    cout << "\n=== Running TEST_CASE: operator * ===\n";

    float arr1[9] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    float arr2[9] = {
        9, 8, 7,
        6, 5, 4,
        3, 2, 1
    };

    SquareMatrix m1(arr1);
    SquareMatrix m2(arr2);
    SquareMatrix result = m1 * m2;

    float expected[9] = {
        30, 24, 18,
        84, 69, 54,
        138, 114, 90
    };

    for (int i = 0; i < 9; ++i) {
        CHECK(result[i / 3][i % 3] == doctest::Approx(expected[i]));
    }

    cout << result << endl;
    cout << "\n========================================\n";
}


TEST_CASE("operator % element-wise (mult)") {
    cout << "\n=== Running TEST_CASE: operator % element-wise (mult) ===\n";
    SquareMatrix m1 = createMatrix(1);
    SquareMatrix m2 = createMatrix(2);
    SquareMatrix result = m1 % m2;

    for (int i = 0; i < result.getDimension(); ++i) {
        for (int j = 0; j < result.getDimension(); ++j) {
            CHECK(result[i][j] == doctest::Approx(m1[i][j] * m2[i][j]));
        }
    }

    cout << result << endl;
    cout << "\n========================================\n";
}


TEST_CASE("operator [] writing") {
    cout << "\n=== Running TEST_CASE: operator [] writing ===\n";
    SquareMatrix m = createMatrix();
    cout << "Set all values to 7" << endl;

    for (int i = 0; i < m.getDimension(); ++i) {
        for (int j = 0; j < m.getDimension(); ++j) {
            m[i][j] = 7;
        }
    }

    for (int i = 0; i < m.getDimension(); ++i) {
        for (int j = 0; j < m.getDimension(); ++j) {
            CHECK(m[i][j] == doctest::Approx(7));
        }
    }

    cout << m << endl;
    cout << "\n========================================\n";
}


TEST_CASE("operator [] reading") {
    cout << "\n=== Running TEST_CASE: operator [] reading ===\n";
    SquareMatrix m = createMatrix();

    for (int i = 0; i < m.getDimension(); ++i) {
        for (int j = 0; j < m.getDimension(); ++j) {
            float expected = i * m.getDimension() + j + 1;
            CHECK(m[i][j] == doctest::Approx(expected));
        }
    }

    cout << "\n========================================\n";
}

TEST_CASE("operator = (copy constractor) ") {
    cout << "\n=== Running TEST_CASE: operator = (copy constractor)  ===\n";
    SquareMatrix m = createMatrix();
    SquareMatrix b = m;

    for (int i = 0; i < m.getDimension(); i++) {
        for (int j = 0; j < m.getDimension(); j++) {
            float mVal = m[i][j];
            CHECK(b[i][j] == doctest::Approx(mVal));
        }
    }


    cout << "\n========================================\n";
}

TEST_CASE("operator * (scalar) ") {
    cout << "\n=== Running TEST_CASE: operator * (scalar)   ===\n";
    SquareMatrix m = createMatrix();
    SquareMatrix b = m * 2;
    for (int i = 0; i < m.getDimension(); i++) {
        for (int j = 0; j < m.getDimension(); j++) {
            float mVal = b[i][j];
            CHECK(b[i][j] == doctest::Approx(mVal));
            cout << b[i][j] << " ";
        }
    }


    cout << "\n========================================\n";
}

TEST_CASE("operator % (scalar) ") {
    cout << "\n=== Running TEST_CASE: operator % (scalar)   ===\n";
    SquareMatrix m = createMatrix();
    int mod = 3;
    SquareMatrix b = m % mod;
    for (int i = 0; i < m.getDimension(); i++) {
        for (int j = 0; j < m.getDimension(); j++) {
            int temp = b[i][j];
            int mVal = temp % mod;
            CHECK(b[i][j] == doctest::Approx(mVal));
            cout << b[i][j] << " ";
        }
    }


    cout << "\n========================================\n";
}

TEST_CASE("operator / (scalar) ") {
    cout << "\n=== Running TEST_CASE: operator / (scalar)   ===\n";
    SquareMatrix m = createMatrix();
    int div = 3;
    SquareMatrix b = (m / div);
    for (int i = 0; i < m.getDimension(); i++) {
        for (int j = 0; j < m.getDimension(); j++) {
            float temp = m[i][j];
            float mVal = temp / div;
            CHECK(b[i][j] == doctest::Approx(mVal));
            cout << b[i][j] << " ";
        }
    }


    cout << "\n========================================\n";
}

TEST_CASE("operator ^ (scalar) ") {
    cout << "\n=== Running TEST_CASE: operator ^ (scalar)   ===\n";
    SquareMatrix m = createMatrix();
    int power = 3;
    SquareMatrix b = (m ^ power);
    SquareMatrix manual = m * m * m;
    for (int i = 0; i < m.getDimension(); i++) {
        for (int j = 0; j < m.getDimension(); j++) {
            CHECK(b[i][j] == doctest::Approx(manual[i][j]));
            cout << b[i][j] << " ";
        }
    }


    cout << "\n========================================\n";
}

TEST_CASE("operator += ") {
    cout << "\n=== Running TEST_CASE: operator +=   ===\n";
    SquareMatrix m = createMatrix();
    SquareMatrix b = createMatrix();
    m += b;
    for (int i = 0; i < m.getDimension(); i++) {
        for (int j = 0; j < m.getDimension(); j++) {
            CHECK(m[i][j] == doctest::Approx(b[i][j] + b[i][j]));
            cout << m[i][j] << " ";
        }
    }


    cout << "\n========================================\n";
}

TEST_CASE("operator -= ") {
    cout << "\n=== Running TEST_CASE: operator -=   ===\n";
    SquareMatrix m = createMatrix();
    SquareMatrix b = createMatrix();
    m -= b;
    for (int i = 0; i < m.getDimension(); i++) {
        for (int j = 0; j < m.getDimension(); j++) {
            CHECK(m[i][j] == doctest::Approx(0));
            cout << m[i][j] << " ";
        }
    }


    cout << "\n========================================\n";
}

TEST_CASE("operator *= ") {
    cout << "\n=== Running TEST_CASE: operator *=   ===\n";
    SquareMatrix m = createMatrix();
    SquareMatrix b = createMatrix();
    SquareMatrix manual = m * b;
    m *= b;
    for (int i = 0; i < m.getDimension(); i++) {
        for (int j = 0; j < m.getDimension(); j++) {
            CHECK(m[i][j] == doctest::Approx(manual[i][j]));
            cout << m[i][j] << " ";
        }
    }


    cout << "\n========================================\n";
}

TEST_CASE("operator *= (scalar) ") {
    cout << "\n=== Running TEST_CASE: operator *= (scalar)   ===\n";
    SquareMatrix m = createMatrix();
    SquareMatrix manual = m * 5;
    m *= 5;
    for (int i = 0; i < m.getDimension(); i++) {
        for (int j = 0; j < m.getDimension(); j++) {
            CHECK(m[i][j] == doctest::Approx(manual[i][j]));
            cout << m[i][j] << " ";
        }
    }


    cout << "\n========================================\n";
}

TEST_CASE("operator /= (scalar) ") {
    cout << "\n=== Running TEST_CASE: operator /= (scalar)   ===\n";
    SquareMatrix m = createMatrix();
    SquareMatrix manual = m / 5;
    m /= 5;
    for (int i = 0; i < m.getDimension(); i++) {
        for (int j = 0; j < m.getDimension(); j++) {
            CHECK(m[i][j] == doctest::Approx(manual[i][j]));
            cout << m[i][j] << " ";
        }
    }


    cout << "\n========================================\n";
}

TEST_CASE("operator %= (matrix element-wise)") {
    cout << "\n=== Running TEST_CASE: operator %= (matrix) ===\n";

    SquareMatrix m1 = createMatrix(); // 1 to 9
    SquareMatrix m2 = createMatrix(2); // 2 to 10

    SquareMatrix expected = m1 % m2; // manual result

    m1 %= m2;

    for (int i = 0; i < m1.getDimension(); i++) {
        for (int j = 0; j < m1.getDimension(); j++) {
            CHECK(m1[i][j] == doctest::Approx(expected[i][j]));
            cout << m1[i][j] << " ";
        }
    }

    cout << "\n========================================\n";
}


TEST_CASE("operator %= (scalar)") {
    cout << "\n=== Running TEST_CASE: operator %= (scalar) ===\n";

    SquareMatrix m = createMatrix();
    SquareMatrix manual = m % 5;

    m %= 5;

    for (int i = 0; i < m.getDimension(); i++) {
        for (int j = 0; j < m.getDimension(); j++) {
            CHECK(m[i][j] == doctest::Approx(manual[i][j]));
            cout << m[i][j] << " ";
        }
    }

    cout << "\n========================================\n";
}


TEST_CASE("operator == ") {
    cout << "\n=== Running TEST_CASE: operator == ===\n";
    SquareMatrix a = createMatrix(); // sum = 45
    SquareMatrix b = createMatrix(); // same
    CHECK(a == b);
    cout << "========================================\n";
}

TEST_CASE("operator != ") {
    cout << "\n=== Running TEST_CASE: operator != ===\n";
    SquareMatrix a = createMatrix(); // sum = 45
    SquareMatrix b = createMatrix(10); // 10 to 18  sum = 126
    CHECK(a != b);
    cout << "========================================\n";
}

TEST_CASE("operator < ") {
    cout << "\n=== Running TEST_CASE: operator < ===\n";
    SquareMatrix a = createMatrix(); // sum = 45
    SquareMatrix b = createMatrix(10); // sum = 126
    CHECK(a < b);
    cout << "========================================\n";
}

TEST_CASE("operator <= ") {
    cout << "\n=== Running TEST_CASE: operator <= ===\n";
    SquareMatrix a = createMatrix(); // sum = 45
    SquareMatrix b = createMatrix(); // sum = 45
    SquareMatrix c = createMatrix(10); // sum = 126
    CHECK(a <= b);
    CHECK(a <= c);
    cout << "========================================\n";
}

TEST_CASE("operator > ") {
    cout << "\n=== Running TEST_CASE: operator > ===\n";
    SquareMatrix a = createMatrix(10); // sum = 126
    SquareMatrix b = createMatrix(); // sum = 45
    CHECK(a > b);
    cout << "========================================\n";
}

TEST_CASE("operator >= ") {
    cout << "\n=== Running TEST_CASE: operator >= ===\n";
    SquareMatrix a = createMatrix(); // sum = 45
    SquareMatrix b = createMatrix(); // sum = 45
    SquareMatrix c = createMatrix(2); // sum > 45
    CHECK(a >= b);
    CHECK(c >= a);
    cout << "========================================\n";
}
