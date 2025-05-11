// noapatito123@gmail.com
#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>
#include <stdexcept>

namespace matrix {

class SquareMat {
private:
    int size;
    double** data;

    double getSum() const;

public:
    // Constructors
    SquareMat(int size);                       // Default constructor
    explicit SquareMat(int size, double scalar); // Fill with scalar
    SquareMat(const SquareMat& other);         // Copy constructor
    ~SquareMat();                              // Destructor

    // Access
    double* operator[](int i);
    const double* operator[](int i) const;

    // Assignment
    SquareMat& operator=(const SquareMat& other);
    SquareMat& operator=(double scalar);

    // Arithmetic operators
    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator*(const SquareMat& other) const;
    SquareMat operator*(double scalar) const;
    friend SquareMat operator*(double scalar, const SquareMat& mat);

    SquareMat operator%(const SquareMat& other) const;
    SquareMat operator%(int scalar) const;
    SquareMat operator/(double scalar) const;

    SquareMat operator-() const;
    SquareMat operator^(int power) const;

    // Increment / Decrement
    SquareMat& operator++();    // Pre
    SquareMat operator++(int);  // Post
    SquareMat& operator--();    // Pre
    SquareMat operator--(int);  // Post

    // Transpose
    SquareMat operator~() const;

    // Comparison
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;

    // Determinant
    double operator!() const;

    // Compound assignment
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(const SquareMat& other);
    SquareMat& operator*=(double scalar);
    SquareMat& operator/=(double scalar);
    SquareMat& operator%=(const SquareMat& other);
    SquareMat& operator%=(int scalar);

    // Output
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);

    int getSize() const;

};

} // namespace matrix

#endif
