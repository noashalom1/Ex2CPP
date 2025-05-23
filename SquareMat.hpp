// noapatito123@gmail.com
#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>
#include <stdexcept>

namespace matrix {

class TestHelper;

class SquareMat {
private:
    int size;
    double** data;

    double getSum() const; // helper function to calculate the sum of all elements
    friend class TestHelper; // declare test helper as friend

public:
    // Constructors 
    SquareMat(int size); // Default constructor
    explicit SquareMat(int size, double scalar); // Fill with scalar
    SquareMat(const SquareMat& other); // Copy constructor
    ~SquareMat(); // Destructor

    // Access operator
    double* operator[](int i); // allows write access to row i  
    const double* operator[](int i) const; // allows read-only access to row i  

    // Assignment operators 
    SquareMat& operator=(const SquareMat& other); // copy assignment  
    SquareMat& operator=(double scalar); // assigns scalar value to all elements  

    // Arithmetic operators  
    SquareMat operator+(const SquareMat& other) const; // matrix addition  
    SquareMat operator-(const SquareMat& other) const; // matrix subtraction  
    SquareMat operator*(const SquareMat& other) const; // matrix multiplication  
    friend SquareMat operator*(const SquareMat& mat, double scalar); // Matrix * scalar 
    friend SquareMat operator*(double scalar, const SquareMat& mat); // scalar * matrix 

    SquareMat operator%(const SquareMat& other) const; // element-wise multiplication (Hadamard product)  
    SquareMat operator%(int scalar) const; // modulo operation on each element  
    SquareMat operator/(double scalar) const; // scalar division  
    
    SquareMat operator-() const; // Unary minus operator

    SquareMat operator^(int power) const; // Power - matrix raised to integer power  

    // Increment and Decrement operators
    SquareMat& operator++(); // prefix increment: ++mat  
    SquareMat operator++(int); // postfix increment: mat++  
    SquareMat& operator--(); // prefix decrement: --mat  
    SquareMat operator--(int); // postfix decrement: mat--  

    // Transpose operator
    SquareMat operator~() const; // matrix transpose  

    // Comparison operator
    bool operator==(const SquareMat& other) const; // equality (currently based on sum)  
    bool operator!=(const SquareMat& other) const; // inequality  
    bool operator<(const SquareMat& other) const; // compare by sum  
    bool operator<=(const SquareMat& other) const; // compare by sum  
    bool operator>(const SquareMat& other) const; // compare by sum  
    bool operator>=(const SquareMat& other) const; // compare by sum  

    // Determinant operator 
    double operator!() const; // returns the determinant of the matrix  

    // Compound assignment operators
    SquareMat& operator+=(const SquareMat& other); // add and assign  
    SquareMat& operator-=(const SquareMat& other); // subtract and assign  
    SquareMat& operator*=(const SquareMat& other); // multiply and assign  
    SquareMat& operator*=(double scalar); // scalar multiply and assign  
    SquareMat& operator/=(double scalar); // scalar divide and assign  
    SquareMat& operator%=(const SquareMat& other); // element-wise multiply and assign  
    SquareMat& operator%=(int scalar); // modulo and assign  

    // Output  
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat); // stream output of matrix  
};

} // namespace matrix

#endif
