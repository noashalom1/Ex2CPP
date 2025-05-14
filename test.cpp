// noapatito123@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"

using namespace matrix;

namespace matrix {

class TestHelper { // TestHelper has access now because it's a friend
public:
    static double callGetSum(const SquareMat& mat) {
        return mat.getSum();
    }
    static int callGetSize(const SquareMat& mat) {
        return mat.getSize();
    }

 };

TEST_CASE("Test private getSum using friend helper") { // test for private getSum
    SquareMat mat(2, 3);
    CHECK(TestHelper::callGetSum(mat) == 12);
 }

 TEST_CASE("Test private getSize using friend helper") { // test for private getSize
    SquareMat mat(2, 3);
    CHECK(TestHelper::callGetSize(mat) == 2);
 }

TEST_CASE("Matrix creation and indexing") { // test constructor with scalar and direct element access
    SquareMat mat(2, 5);
    CHECK(mat[0][0] == 5);
    CHECK(mat[1][1] == 5);
    mat[0][1] = 3;
    CHECK(mat[0][1] == 3);
}

TEST_CASE("Matrix addition and subtraction") { // test A + B and B - A for element-wise operations
    SquareMat A(2, 2);
    SquareMat B(2, 3);
    SquareMat C = A + B;
    CHECK(C[0][0] == 5);
    CHECK(C[1][1] == 5);
    C = B - A;
    CHECK(C[0][0] == 1);
}

TEST_CASE("Matrix scalar multiplication and division") { // test scalar multiplication and division
    SquareMat A(2, 2);
    SquareMat B = A * 3;
    CHECK(B[0][0] == 6);
    B = 2 * A;
    CHECK(B[1][1] == 4);
    SquareMat C = B / 2;
    CHECK(C[1][0] == 2);
}

TEST_CASE("Unary minus and increment/decrement") { // test -A, ++A, A++, --A, A--
    SquareMat A(2);
    A[0][0] = 1;
    A[1][1] = -2;
    SquareMat B = -A;
    CHECK(B[0][0] == -1);
    CHECK(B[1][1] == 2);

    ++A;
    CHECK(A[0][0] == 2);
    A++;
    CHECK(A[0][0] == 3);

    --A;
    CHECK(A[0][0] == 2);
    A--;
    CHECK(A[0][0] == 1);
}

TEST_CASE("Matrix multiplication and power") { // test A * A and A ^ n
    SquareMat I(2);
    I[0][0] = 1;
    I[1][1] = 1;
    SquareMat M = I ^ 3;
    CHECK(M[0][0] == 1);
    CHECK(M[1][1] == 1);
}

TEST_CASE("Comparison operators") { // test ==, !=, <, <=, >, >
    SquareMat A(2, 2);
    SquareMat B(2, 3);
    CHECK((A == A) == true);
    CHECK((A != B) == true);
    CHECK((B > A) == true);
    CHECK((A < B) == true);
    CHECK((A <= A) == true);
    CHECK((B >= A) == true);
}

TEST_CASE("Element-wise modulo and scalar modulo") { // test A % B and A % scalar
    SquareMat A(2);
    A[0][0] = 5;
    A[1][1] = 4;
    SquareMat B(2);
    B[0][0] = 2;
    B[1][1] = 3;
    SquareMat C = A % B;
    CHECK(C[0][0] == 10); // 5 * 2
    SquareMat D = A % 3;
    CHECK(D[0][0] == 2); // 5 % 3
}

TEST_CASE("Compound assignment operators") { // test A += B, A -= B, A *= B, etc.
    SquareMat A(2, 1);
    SquareMat B(2, 2);

    A += B;
    CHECK(A[0][0] == 3);

    A -= B;
    CHECK(A[0][0] == 1);

    A *= B;
    CHECK(A[0][0] == 4);

    A *= 2;
    CHECK(A[0][0] == 8);

    A /= 2;
    CHECK(A[0][0] == 4);

    SquareMat C(2, 2);
    A %= C;
    CHECK(A[0][0] == 8);

    A %= 3;
    CHECK(A[0][0] == 2);
}

TEST_CASE("Transpose") { // test ~A
    SquareMat A(2);
    A[0][1] = 7;
    SquareMat B = ~A;
    CHECK(B[1][0] == 7);
    CHECK(B[0][1] == 0);
}

TEST_CASE("Determinant") { // test determinant (!A)
    SquareMat A(2);
    A[0][0] = 4;
    A[0][1] = 2;
    A[1][0] = 3;
    A[1][1] = 1;
    CHECK((!A) == doctest::Approx(-2));
}

TEST_CASE("Copy constructor and assignment") { // test copy constructor and operator=
    SquareMat A(2, 5);
    SquareMat B = A;  // Copy constructor
    CHECK(B[0][0] == 5);
    B[0][0] = 10;
    CHECK(A[0][0] == 5); // A should not change

    SquareMat C(2);
    C = A; // Assignment operator
    CHECK(C[1][1] == 5);
}

TEST_CASE("Exception: invalid matrix size") { // test invalid sizes
    CHECK_THROWS_AS(SquareMat(0), std::invalid_argument);
    CHECK_THROWS_AS(SquareMat(-3), std::invalid_argument);
}

TEST_CASE("Exception: out-of-bounds access") { // test invalid row access
    SquareMat A(2);
    CHECK_THROWS_AS({ (void)A[-1][0]; }, std::out_of_range);
    CHECK_THROWS_AS({ (void)A[2][1]; }, std::out_of_range);
}

TEST_CASE("Exception: addition/subtraction with different sizes") { // test A + B, A - B where sizes mismatch
    SquareMat A(2);
    SquareMat B(3);
    CHECK_THROWS_AS(A + B, std::invalid_argument);
    CHECK_THROWS_AS(A - B, std::invalid_argument);
}

TEST_CASE("Exception: multiplication with different sizes") { // test A * B with size mismatch
    SquareMat A(2);
    SquareMat B(3);
    CHECK_THROWS_AS(A * B, std::invalid_argument);
}

TEST_CASE("Exception: modulo with different sizes or zero scalar") { // test A % B (bad sizes) and A % 0
    SquareMat A(2);
    SquareMat B(3);
    CHECK_THROWS_AS(A % B, std::invalid_argument);
    CHECK_THROWS_AS(A % 0, std::invalid_argument);
}

TEST_CASE("Exception: division by zero") { // test A / 0
    SquareMat A(2, 5);
    CHECK_THROWS_AS(A / 0.0, std::invalid_argument);
    CHECK_THROWS_AS(A /= 0.0, std::invalid_argument);
}

TEST_CASE("Exception: negative power") { // test A ^ -1
    SquareMat A(2);
    CHECK_THROWS_AS(A ^ -1, std::invalid_argument);
}

TEST_CASE("1x1 Matrix behavior") { // test single element matrix behavior
    SquareMat A(1, 5);
    CHECK(A[0][0] == 5);
    CHECK((!A) == 5);
    SquareMat B = A ^ 3;
    CHECK(B[0][0] == 125);
}

TEST_CASE("Self-assignment") { // test A = A
    SquareMat A(2, 3);
    A = A;
    CHECK(A[0][0] == 3);
}

TEST_CASE("Scalar assignment") { // test A = scalar
    SquareMat A(2, 1);
    A = 7;
    CHECK(A[1][1] == 7);
}

TEST_CASE("Double transpose") { // test ~~A == A
    SquareMat A(2);
    A[0][1] = 9;
    SquareMat B = ~~A;
    CHECK(B[0][1] == 9);
}

TEST_CASE("Multiplying by identity matrix") { // test A * I = A
    SquareMat I(2);
    I[0][0] = 1;
    I[1][1] = 1;

    SquareMat A(2);
    A[0][0] = 2;
    A[0][1] = 3;
    A[1][0] = 4;
    A[1][1] = 5;

    SquareMat B = A * I;
    CHECK(B[0][0] == 2);
    CHECK(B[1][1] == 5);
}

TEST_CASE("Determinant requires row swap") { // test !A with pivot = 0 requiring row swap
    SquareMat mat(3, 0.0);
    mat[0][0] = 0.0;
    mat[0][1] = 2.0;
    mat[1][0] = 1.0;
    mat[1][1] = 3.0;
    mat[2][2] = 1.0;
    CHECK(!mat != doctest::Approx(0.0));
}

TEST_CASE("Determinant returns 0 when no row swap possible") { // test !A returns 0 if column is all zero
    SquareMat mat(2, 0.0);
    mat[0][0] = 0.0;
    mat[0][1] = 2.0;
    mat[1][0] = 0.0;
    mat[1][1] = 3.0;
    CHECK(!mat == doctest::Approx(0.0));
}

TEST_CASE("Print operator<< outputs matrix correctly") { // test string output of matrix
    SquareMat mat(2);
    mat[0][0] = 1.5;
    mat[0][1] = 2.0;
    mat[1][0] = 3.5;
    mat[1][1] = 4.0;

    std::ostringstream oss;
    oss << mat;

    std::string expected = "1.5 2 \n3.5 4 \n";
    CHECK(oss.str() == expected);
}

} // namespace matrix
    




