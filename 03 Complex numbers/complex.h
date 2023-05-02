#pragma once
#include<cmath>
#include<iostream>

using namespace std;

class Complex
{
private:
    long double realScale;
    long double imagScale;
public:
    constexpr Complex() : Complex(0, 0)  {};
    constexpr Complex(double real) : Complex(real, 0) {};
    explicit constexpr Complex(double realN, double imagN) : realScale(realN), imagScale(imagN) {};
    Complex(const Complex &rhs);

    double real() const;
    double imag() const;
    void real(double newVal);
    void imag(double newVal);

    Complex operator=(const Complex& complex);
    void operator+=(const double scalar);
    void operator+=(const Complex& complex);
    void operator-=(const double scalar);
    void operator-=(const Complex& complex);
    void operator/=(const double scalar);
    void operator/=(const Complex& complex);
    void operator*=(const double scalar);
    void operator*=(const Complex& complex);
};

Complex operator+(const Complex& complex);
Complex operator-(const Complex& complex);

Complex operator+(const Complex& complex, const double scalar);
Complex operator+(const Complex& leftCmplx, const Complex& rightCmplx);
Complex operator-(const Complex& complex, const double scalar);
Complex operator-(const Complex& leftCmplx, const Complex& rightCmplx);
Complex operator/(const Complex& complex, const double scalar);
Complex operator/(const double scalar, const Complex& complex);
Complex operator/(const Complex& leftCmplx, const Complex& rightCmplx);
Complex operator*(const Complex& complex, const double scalar);
Complex operator*(const Complex& leftCmplx, const Complex& rightCmplx);

bool operator==(const Complex& complex, const double scalar);
bool operator==(const Complex& leftCmplx, const Complex& rightCmplx);

bool operator!=(const Complex& complex, const double scalar);
bool operator!=(const Complex& leftCmplx, const Complex& rightCmplx);

double real(const Complex& complex);
double imag(const Complex& complex);

double abs(const Complex& complex);

Complex& operator<(Complex& leftCmplx, Complex& rightCmplx);

ostream& operator<<(ostream& os, const Complex& complex);
istream& operator>>(istream& is, Complex& complex);

constexpr Complex operator""_i(long double scalar)
{
    return Complex(0,scalar);
}
constexpr Complex operator""_i(unsigned long long int scalar)
{
    return Complex(0,scalar);
}


//#include"complex.cpp"