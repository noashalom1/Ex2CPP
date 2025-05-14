// noapatito123@gmail.com
#include "SquareMat.hpp"

using namespace matrix;

namespace matrix{

// ==========================
//     PRIVATE FUNCTION
// ==========================

double SquareMat::getSum() const { // getSum for Comparison operator
    double sum = 0.0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            sum += data[i][j]; // accumulate all matrix elements
    return sum;
}

// ==========================
//     CONSTRUCTORS
// ==========================

SquareMat::SquareMat(int size) : SquareMat(size, 0.0){} // Delegate to scalar constructor

SquareMat::SquareMat(int size, double scalar) : size(size) { // Fill with scalar
    if (size <= 0) throw std::invalid_argument("Invalid matrix size.");
    data = new double *[size]; // allocate rows
        for (int i = 0; i < size; ++i)
        {
            data[i] = new double[size]; // allocate columns
            for (int j = 0; j < size; ++j)
            {
                data[i][j] = scalar; // initialize each element
            }
        }    
}

SquareMat::SquareMat(const SquareMat& other) : size(other.size), data(new double *[other.size]) { // Copy constructor
    for (int i = 0; i < size; ++i)
    {
        data[i] = new double[size]; // allocate new row
        for (int j = 0; j < size; ++j)
        {
            data[i][j] = other.data[i][j]; // copy each value
        }
    }
}

SquareMat::~SquareMat() { // Destructor
    if (!data) return; // nothing to delete
    for (int i = 0; i < size; ++i) 
        delete[] data[i]; // delete each row
    delete[] data; // delete row pointer array
}

// ==========================
//     ACCESS
// ==========================

double* SquareMat::operator[](int i) { // Allows write access to row i
    if (i < 0 || i >= size) throw std::out_of_range("Invalid row index.");
    return data[i]; // return pointer to row
}

const double* SquareMat::operator[](int i) const { // Allows read-only access to row i
    if (i < 0 || i >= size) throw std::out_of_range("Invalid row index.");
    return data[i]; // return const pointer to row
}

// ==========================
//     ASSIGNMENT
// ==========================

SquareMat& SquareMat::operator=(const SquareMat& other) { // Copy assignment 
    if (this != &other) {
            SquareMat temp(other); // copy first
            std::swap(size, temp.size); // swap internals
            std::swap(data, temp.data);
        }
        return *this;
}

SquareMat& SquareMat::operator=(double scalar) { // Assigns scalar value to all elements
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] = scalar; // assign scalar to each element
    return *this;
}

// ==========================
//     ARITHMETIC
// ==========================

SquareMat SquareMat::operator+(const SquareMat& other) const { // Matrix addition
    if (size != other.size)
        throw std::invalid_argument("Matrix sizes do not match for addition.");
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = data[i][j] + other[i][j]; // element-wise addition
    return res;
}

SquareMat SquareMat::operator-(const SquareMat& other) const { // Matrix subtraction 
    if (size != other.size)
        throw std::invalid_argument("Matrix sizes do not match for subtraction.");
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = data[i][j] - other[i][j]; // element-wise subtraction
    return res;
}

SquareMat SquareMat::operator*(const SquareMat& other) const { // Matrix multiplication
    if (size != other.size)
        throw std::invalid_argument("Matrix sizes do not match for multiplication.");
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            for (int k = 0; k < size; ++k)
                res[i][j] += data[i][k] * other[k][j]; // standard matrix multiplication
    return res;
}

SquareMat operator*(const SquareMat& mat, double scalar) { // Matrix * Scalar
    int size = mat.size;
    SquareMat res(size); 
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = mat[i][j] * scalar; // scalar multiplication
    return res;
}

SquareMat operator*(double scalar, const SquareMat& mat) { // Scalar * Matrix 
    return mat * scalar; // commutative scalar multiplication
}

SquareMat SquareMat::operator%(const SquareMat& other) const { // Element-wise multiplication
    if (size != other.size)
        throw std::invalid_argument("Matrix sizes do not match for element-wise multiplication.");
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = data[i][j] * other[i][j]; 
    return res;
}

SquareMat SquareMat::operator%(int scalar) const { // Modulo operation on each element 
    if (std::abs(scalar) < 1e-9)
        throw std::invalid_argument("Modulo by zero.");
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = static_cast<int>(data[i][j]) % scalar; // int modulo per element
    return res;
}

SquareMat SquareMat::operator/(double scalar) const { // Scalar division
    if (std::abs(scalar) < 1e-9)
        throw std::invalid_argument("Division by zero.");
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = data[i][j] / scalar; // scalar division
    return res;
}

SquareMat SquareMat::operator-() const { // Unary minus 
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = -data[i][j]; // negate each element
    return res;
}

SquareMat SquareMat::operator^(int power) const { // Power operator
    if (power < 0)
        throw std::invalid_argument("Negative exponent not supported.");
    SquareMat res(size, 0); // start with identity matrix
    for (int i = 0; i < size; ++i)
        res[i][i] = 1;

    SquareMat base(*this);
    while (power > 0) {
        if (power % 2 == 1)
            res = res * base; // multiply by base if odd bit
        base = base * base; // square the base
        power /= 2;
    }
    return res;
}

// ==========================
//     INCREMENT / DECREMENT
// ==========================

SquareMat& SquareMat::operator++() { // prefix increment: ++mat  
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            ++data[i][j]; // pre-increment each element
    return *this;
}

SquareMat SquareMat::operator++(int) { // postfix increment: mat++  
    SquareMat tmp(*this);
    ++(*this); // post-increment
    return tmp;
}

SquareMat& SquareMat::operator--() { // prefix decrement: --mat  
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            --data[i][j]; // pre-decrement each element
    return *this;
}

SquareMat SquareMat::operator--(int) { // postfix decrement: mat--  
    SquareMat tmp(*this);
    --(*this); // post-decrement
    return tmp;
}

// ==========================
//     TRANSPOSE
// ==========================

SquareMat SquareMat::operator~() const {
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[j][i] = data[i][j]; // transpose: swap indices
    return res;
}

// ========================================
//     COMPARISON OPERATORS - compare sums
// ========================================

bool SquareMat::operator==(const SquareMat& other) const {
    return getSum() == other.getSum(); 
}

bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}

bool SquareMat::operator<(const SquareMat& other) const {
    return getSum() < other.getSum();
}

bool SquareMat::operator<=(const SquareMat& other) const {
    return getSum() <= other.getSum();
}

bool SquareMat::operator>(const SquareMat& other) const {
    return getSum() > other.getSum();
}

bool SquareMat::operator>=(const SquareMat& other) const {
    return getSum() >= other.getSum();
}

// ==========================
//     DETERMINANT (!)
// ==========================

double SquareMat::operator!() const {
    const double EPSILON = 1e-9;
    if (size == 1)
        return data[0][0]; // determinant of 1x1 is the value itself

    double det = 1.0;
    SquareMat temp(*this); // make a copy to avoid modifying original

    for (int i = 0; i < size; ++i) {
        if (std::abs(temp.data[i][i]) < EPSILON) {
            bool found = false;
            for (int j = i + 1; j < size; ++j) {
                if (temp.data[j][i] > EPSILON) {
                    std::swap(temp.data[i], temp.data[j]); // swap rows
                    det *= -1; // account for row swap
                    found = true;
                    break;
                }
            }
            if (!found)
                return 0.0; // singular matrix
        }

        det *= temp.data[i][i];
        for (int j = i + 1; j < size; ++j) {
            double factor = temp.data[j][i] / temp.data[i][i];
            for (int k = i; k < size; ++k)
                temp.data[j][k] -= factor * temp.data[i][k]; // eliminate below
        }
    }
    return det;
}

// ==========================
//     COMPOUND ASSIGNMENT
// ==========================

SquareMat& SquareMat::operator+=(const SquareMat& other) {
    *this = *this + other;
    return *this;
}

SquareMat& SquareMat::operator-=(const SquareMat& other) {
    *this = *this - other;
    return *this;
}

SquareMat& SquareMat::operator*=(const SquareMat& other) {
    *this = *this * other;
    return *this;
}

SquareMat& SquareMat::operator*=(double scalar) {
    *this = *this * scalar;
    return *this;
}

SquareMat& SquareMat::operator/=(double scalar) {
    *this = *this / scalar;
    return *this;
}

SquareMat& SquareMat::operator%=(const SquareMat& other) {
    *this = *this % other;
    return *this;
}

SquareMat& SquareMat::operator%=(int scalar) {
    *this = *this % scalar;
    return *this;
}

// ==========================
//     OUTPUT <<
// ==========================

std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            os << mat[i][j] << " "; // print each element
        }
        os << "\n"; // new line after row
    }
    return os;
}
} // namespace matrix

