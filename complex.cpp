#include "complex.h"

Complex :: Complex() {}

Complex:: Complex(double _a, double _b) {
    a = _a;
    b = _b;
}

Complex Complex :: operator*(const Complex& x)const {
    return Complex(a * x.a - b * x.b, a * x.b + b * x.a);
}

Complex Complex :: operator*(const double& x)const {
    return Complex(a * x, x * b);
}

Complex Complex :: operator+(const Complex& x)const {
    return Complex(a + x.a, x.b + b);
}

Complex Complex :: operator-(const Complex& x)const {
    return Complex(a - x.a, x.b - b);
}

Complex Complex :: operator^(const int& p)const {
    double ans_a = a, ans_b = b;
    for (int i = 0; i < p - 1; ++i) {
        double _a = a * ans_a - b * ans_b, _b = a * ans_b + b * ans_a;
        ans_a = _a;
        ans_b = _b;
    }
    return Complex(ans_a, ans_b);
}

Complex Complex :: operator/(const Complex &x) const {
    return Complex((a * x.a + b * x.b) / (x.a * x.a + x.b * x.b),
                   (b * x.a - a * x.b) / (x.a * x.a + x.b * x.b));
}

double Complex :: get_abs() {
    return a * a + b * b;
}
