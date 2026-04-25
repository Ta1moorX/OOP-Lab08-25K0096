#include <iostream>
using namespace std;

class ComplexNumber {
    float real, imag;
public:
    ComplexNumber(float r = 0, float i = 0) : real(r), imag(i) {}

    ComplexNumber operator+(const ComplexNumber& c) {
        return ComplexNumber(real + c.real, imag + c.imag);
    }
    ComplexNumber operator-(const ComplexNumber& c) {
        return ComplexNumber(real - c.real, imag - c.imag);
    }

    ComplexNumber operator*(const ComplexNumber& c) {
        return ComplexNumber(real*c.real - imag*c.imag,
                             real*c.imag + imag*c.real);
    }
    bool operator==(const ComplexNumber& c) {
        return (real == c.real && imag == c.imag);
    }

    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    ComplexNumber c1(3, 4), c2(1, 2);
    ComplexNumber c3(8, 3), c4(5, 6);
    ComplexNumber c5(2, 3), c6(1, 4);
    ComplexNumber c7(3, 5), c8(4, 5);

    cout << "Addition:       "; (c1 + c2).display();
    cout << "Subtraction:    "; (c3 - c4).display();
    cout << "Multiplication: "; (c5 * c6).display();
    cout << "Equality (3+5i == 3+5i): " << (c7 == c7 ? "Equal" : "Not Equal") << endl;
    cout << "Equality (3+5i == 4+5i): " << (c7 == c8 ? "Equal" : "Not Equal") << endl;

    return 0;
}