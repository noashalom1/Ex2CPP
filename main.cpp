// noapatito123@gmail.com
#include "SquareMat.hpp"

using namespace std;
using namespace matrix;

int main() {
    try {
        // New Mat
        SquareMat A(3);       
        SquareMat B(3, 3);      
        SquareMat C(3);         
        A = 2;
        
        // Access
        A[0][0] = 1;
        A[1][1] = 2;
        A[2][2] = 3;
        A[1][0] = 4;
        SquareMat D(A); // copy constructor
        
        // print
        cout << "\nMatrix A:\n" << A;
        cout << "\nMatrix B:\n" << B;
        cout << "\nMatrix C:\n" << C;
        cout << "\nMatrix D:\n" << D;

        // addition
        cout << "\n=== Addition: A + B ===" << endl;
        cout << (A + B) << endl;

        // subtraction
        cout << "=== Subtraction: B - A ===" << endl;
        cout << (B - A) << endl;

        // Matrix Multiplication
        cout << "=== Matrix Multiplication: A * B ===" << endl;
        cout << (A * B) << endl;

        // Scalar Multiplication: Matrix*Scalar
        cout << "=== Matrix*Scalar: A * 2 ===" << endl;
        cout << (A * 2) << endl;
        
        // Scalar Multiplication: Scalar*Matrix
        cout << "=== Scalar*Matrix: 3 * A ===" << endl;
        cout << (3 * A) << endl;
       
        // Matrix Element-wise Modulo Operation
        cout << "=== Matrix Element-wise Modulo Operation: A % B ===" << endl;
        cout << (A % B) << endl;
    
        // Scalar Modulo
        cout << "=== Scalar Modulo: B % 2 ===" << endl;
        cout << (B % 2) << endl;

        // Scalar Division 
        cout << "=== Scalar Division: B / 2 ===" << endl;
        cout << (B / 2) << endl;
    
        // Unary Minus
        cout << "=== Unary Minus: -A ===" << endl;
        cout << (-A) << endl;

        // Power Operator 
        cout << "=== Power Operator: A ^ 2 ===" << endl;
        cout << (A ^ 2) << endl;
     
        // Increment & Decrement
        cout << "=== Increment & Decrement ===" << endl;
        C = A; // copy assignment operator
        cout << "C = A:\n" << C;
        cout << "\nC++:\n" << C++;
        cout << "\nC now is:\n" << C;
        cout << "\n--C:\n" << --C;

        // Transpose
        cout << "\n=== Transpose of A: ===\n" << ~A;

        // Comparison
        cout << "\n=== Comparison ===" << endl;
        cout << boolalpha;
        cout << "A == B? " << (A == B) << endl;
        cout << "\nA != B? " << (A != B) << endl;
        cout << "\nA > B? " << (A > B) << endl;
        cout << "\nA < B? " << (A < B) << endl;
        cout << "\nA <= B? " << (A <= B) << endl;
        cout << "\nA >= B? " << (A >= B) << endl;

        // Determinant
        cout << "\n=== Determinant of A: ===\n" << !A << endl;

        // Compound assignment
        cout << "\n=== Compound Assignment ===" << endl;
        C += B;
        cout << "C += B:\n" << C;

        C -= B;
        cout << "\nC -= B:\n" << C;

        C *= A;
        cout << "\nC *= A:\n" << C;

        C *= 2;
        cout << "\nC *= 2:\n" << C;

        C /= 2;
        cout << "\nC /= 2:\n" << C;

        C %= A;
        cout << "\nC %= A:\n" << C;

        C %= 3;
        cout << "\nC %= 3:\n" << C;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
