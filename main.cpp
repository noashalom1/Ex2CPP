#include "SquareMat.hpp"

using namespace std;
using namespace matrix;

int main() {
    try {
        // יצירת מטריצות
        SquareMat A(3);       
        SquareMat B(3, 3);      
        SquareMat C(3);         
        A = 2;
        
        // שינוי איברים ספציפיים
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
        cout << "\n=== Subtraction: B - A ===" << endl;
        cout << (B - A) << endl;

        // Matrix Multiplication
        cout << "\n=== Matrix Multiplication: A * B ===" << endl;
        cout << (A * B) << endl;

        // Scalar Multiplication: Matrix*Scalar
        cout << "\n=== Matrix*Scalar: A * 2 ===" << endl;
        cout << (A * 2) << endl;
        
        // Scalar Multiplication: Scalar*Matrix
        cout << "\n=== Scalar*Matrix: 3 * A ===" << endl;
        cout << (3 * A) << endl;
       
        // Matrix Element-wise Modulo Operation
        cout << "\n=== Matrix Element-wise Modulo Operation: A % B ===" << endl;
        cout << (A % B) << endl;
    
        // Scalar Modulo
        cout << "\n=== Scalar Modulo: B % 2 ===" << endl;
        cout << (B % 2) << endl;

        // Scalar Division 
        cout << "\n=== Scalar Division: B / 2 ===" << endl;
        cout << (B / 2) << endl;
    
        // Unary Minus
        cout << "\n=== Unary Minus: -A ===" << endl;
        cout << (-A) << endl;

        // Power Operator 
        cout << "\n=== Power Operator: A ^ 2 ===" << endl;
        cout << (A ^ 2) << endl;
     
        C = A; // copy assignment operator
        cout << "\nC = A:\n" << C;
        cout << "C++:\n" << C++;
        cout << "C now is:\n" << C;
        cout << "--C:\n" << --C;

        // Transpose
        cout << "Transpose of A:\n" << ~A;

        // השוואות
        cout << boolalpha;
        cout << "A == B? " << (A == B) << endl;
        cout << "A != B? " << (A != B) << endl;
        cout << "A > B? " << (A > B) << endl;
        cout << "A < B? " << (A < B) << endl;
        cout << "A <= B? " << (A <= B) << endl;
        cout << "A >= B? " << (A >= B) << endl;

        // Determinant
        cout << "Determinant of A: " << !A << endl;

        // השמה משולבת
        C = A;
        C += B;
        cout << "C += B:\n" << C;

        C -= B;
        cout << "C -= B:\n" << C;

        C *= A;
        cout << "C *= A:\n" << C;

        C *= 2;
        cout << "C *= 2:\n" << C;

        C /= 2;
        cout << "C /= 2:\n" << C;

        C %= A;
        cout << "C %= A (element-wise mul):\n" << C;

        C %= 3;
        cout << "C %= 3:\n" << C;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
