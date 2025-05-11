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

    double getSum() const; // helper function to calculate the sum of all elements

public:
    // Constructors
    SquareMat(int size); // Default constructor
    explicit SquareMat(int size, double scalar); // Fill with scalar
    SquareMat(const SquareMat& other); // Copy constructor
    ~SquareMat(); // Destructor

    // Access  
    double* operator[](int i); // allows write access to row i  
    const double* operator[](int i) const; // allows read-only access to row i  

    // Assignment  
    SquareMat& operator=(const SquareMat& other); // copy assignment  
    SquareMat& operator=(double scalar); // assigns scalar value to all elements  

    // Arithmetic operators  
    SquareMat operator+(const SquareMat& other) const; // matrix addition  
    SquareMat operator-(const SquareMat& other) const; // matrix subtraction  
    SquareMat operator*(const SquareMat& other) const; // matrix multiplication  
    SquareMat operator*(double scalar) const; // scalar multiplication  
    friend SquareMat operator*(double scalar, const SquareMat& mat); // scalar * matrix (commutative form)  

    SquareMat operator%(const SquareMat& other) const; // element-wise multiplication (Hadamard product)  
    SquareMat operator%(int scalar) const; // modulo operation on each element  
    SquareMat operator/(double scalar) const; // scalar division  

    SquareMat operator-() const; // unary minus (negate all elements)  
    SquareMat operator^(int power) const; // matrix raised to integer power  

    // Increment / Decrement  
    SquareMat& operator++(); // prefix increment: ++mat  
    SquareMat operator++(int); // postfix increment: mat++  
    SquareMat& operator--(); // prefix decrement: --mat  
    SquareMat operator--(int); // postfix decrement: mat--  

    // Transpose  
    SquareMat operator~() const; // matrix transpose  

    // Comparison  
    bool operator==(const SquareMat& other) const; // equality (currently based on sum)  
    bool operator!=(const SquareMat& other) const; // inequality  
    bool operator<(const SquareMat& other) const; // compare by sum  
    bool operator<=(const SquareMat& other) const; // compare by sum  
    bool operator>(const SquareMat& other) const; // compare by sum  
    bool operator>=(const SquareMat& other) const; // compare by sum  

    // Determinant  
    double operator!() const; // returns the determinant of the matrix  

    // Compound assignment  
    SquareMat& operator+=(const SquareMat& other); // add and assign  
    SquareMat& operator-=(const SquareMat& other); // subtract and assign  
    SquareMat& operator*=(const SquareMat& other); // multiply and assign  
    SquareMat& operator*=(double scalar); // scalar multiply and assign  
    SquareMat& operator/=(double scalar); // scalar divide and assign  
    SquareMat& operator%=(const SquareMat& other); // element-wise multiply and assign  
    SquareMat& operator%=(int scalar); // modulo and assign  

    // Output  
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat); // stream output of matrix  

    int getSize() const; // getter for size  
};

} // namespace matrix

#endif
