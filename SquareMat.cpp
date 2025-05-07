#include "SquareMat.hpp"

using namespace matrix;

namespace matrix{

// ==========================
//     PRIVATE FUNCTIONS
// ==========================

void SquareMat::alloc() {
    data = new double*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
        for (int j = 0; j < size; ++j)
            data[i][j] = 0.0;
    }
}

void SquareMat::dealloc() {
    for (int i = 0; i < size; ++i)
        delete[] data[i];
    delete[] data;
}

void SquareMat::copyFrom(const SquareMat& other) {
    size = other.size;
    alloc();
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] = other.data[i][j];
}

double SquareMat::getSum() const {
    double sum = 0.0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            sum += data[i][j];
    return sum;
}

// ==========================
//     CONSTRUCTORS
// ==========================

SquareMat::SquareMat(int size) : SquareMat(size, 0.0){}

SquareMat::SquareMat(int size, double scalar) : size(size) {
    if (size <= 0)
        throw std::invalid_argument("Matrix size must be positive.");
    alloc();
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] = scalar;
}

SquareMat::SquareMat(const SquareMat& other) {
    copyFrom(other);
}

SquareMat::~SquareMat() {
    dealloc();
}

// ==========================
//     ACCESS
// ==========================

double* SquareMat::operator[](int i) {
    if (i < 0 || i >= size) throw std::out_of_range("Invalid row index.");
    return data[i];
}

const double* SquareMat::operator[](int i) const {
    if (i < 0 || i >= size) throw std::out_of_range("Invalid row index.");
    return data[i];
}

// ==========================
//     ASSIGNMENT
// ==========================

SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this != &other) {
        dealloc();
        copyFrom(other);
    }
    return *this;
}

SquareMat& SquareMat::operator=(double scalar) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] = scalar;
    return *this;
}

// ==========================
//     ARITHMETIC
// ==========================

SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size)
        throw std::invalid_argument("Matrix sizes do not match for addition.");
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = data[i][j] + other[i][j];
    return res;
}

SquareMat SquareMat::operator-(const SquareMat& other) const {
    if (size != other.size)
        throw std::invalid_argument("Matrix sizes do not match for subtraction.");
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = data[i][j] - other[i][j];
    return res;
}

SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size)
        throw std::invalid_argument("Matrix sizes do not match for multiplication.");
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            for (int k = 0; k < size; ++k)
                res[i][j] += data[i][k] * other[k][j];
    return res;
}

SquareMat SquareMat::operator*(double scalar) const {
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = data[i][j] * scalar;
    return res;
}

SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar;
}

// =======================================
//     MODULO, MULTIPLICATION, DIVISION
// =======================================

SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size)
        throw std::invalid_argument("Matrix sizes do not match for element-wise multiplication.");
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = data[i][j] * other[i][j];
    return res;
}

SquareMat SquareMat::operator%(int scalar) const {
    if (scalar == 0)
        throw std::invalid_argument("Modulo by zero.");
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = static_cast<int>(data[i][j]) % scalar;
    return res;
}

SquareMat SquareMat::operator/(double scalar) const {
    if (scalar == 0.0)
        throw std::invalid_argument("Division by zero.");
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = data[i][j] / scalar;
    return res;
}

// ===========================
//     UNARY MINUS OPERATOR
// ===========================

SquareMat SquareMat::operator-() const {
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[i][j] = -data[i][j];
    return res;
}

// ===========================
//     POWER OPERATOR
// ===========================

SquareMat SquareMat::operator^(int power) const {
    if (power < 0)
        throw std::invalid_argument("Negative exponent not supported.");
    SquareMat res(size, 0);
    for (int i = 0; i < size; ++i)
        res[i][i] = 1;

    SquareMat base(*this);
    while (power > 0) {
        if (power % 2 == 1)
            res = res * base;
        base = base * base;
        power /= 2;
    }
    return res;
}

// ==========================
//     INCREMENT / DECREMENT
// ==========================

SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            ++data[i][j];
    return *this;
}

SquareMat SquareMat::operator++(int) {
    SquareMat tmp(*this);
    ++(*this);
    return tmp;
}

SquareMat& SquareMat::operator--() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            --data[i][j];
    return *this;
}

SquareMat SquareMat::operator--(int) {
    SquareMat tmp(*this);
    --(*this);
    return tmp;
}

// ==========================
//     TRANSPOSE
// ==========================

SquareMat SquareMat::operator~() const {
    SquareMat res(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            res[j][i] = data[i][j];
    return res;
}

// ==========================
//     COMPARISON OPERATORS
// ==========================

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
    if (size == 1)
        return data[0][0];

    double det = 1.0;
    SquareMat temp(*this);

    for (int i = 0; i < size; ++i) {
        if (temp.data[i][i] == 0.0) {
            bool found = false;
            for (int j = i + 1; j < size; ++j) {
                if (temp.data[j][i] != 0.0) {
                    std::swap(temp.data[i], temp.data[j]);
                    det *= -1;
                    found = true;
                    break;
                }
            }
            if (!found)
                return 0.0;
        }

        det *= temp.data[i][i];
        for (int j = i + 1; j < size; ++j) {
            double factor = temp.data[j][i] / temp.data[i][i];
            for (int k = i; k < size; ++k)
                temp.data[j][k] -= factor * temp.data[i][k];
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
    for (int i = 0; i < mat.getSize(); ++i) {
        for (int j = 0; j < mat.getSize(); ++j) {
            os << mat[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

int SquareMat::getSize() const {
    return size;
}

} // namespace matrix

