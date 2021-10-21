#ifndef COMPLEX_H
#define COMPLEX_H


class Complex
{
public:
    Complex();
    double a, b;
    Complex(double _a, double _b);
    Complex operator*(const Complex& other)const;
    Complex operator*(const double& other)const;
    Complex operator+(const Complex& other)const;
    Complex operator-(const Complex& other)const;
    Complex operator^(const int& other)const;
    Complex operator/(const Complex &other) const;
    double get_abs();
};

#endif // COMPLEX_H
