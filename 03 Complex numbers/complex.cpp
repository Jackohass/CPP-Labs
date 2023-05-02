#include"complex.h"

// constexpr Complex::Complex() : Complex(0, 0)  {}
// constexpr Complex::Complex(double real) : Complex(real, 0) {}
// constexpr Complex::Complex(double realN, double imagN) : realScale(realN), imagScale(imagN) {}
Complex::Complex(const Complex &rhs)
{
    realScale = rhs.realScale;
    imagScale = rhs.imagScale;
}

double Complex::real() const {return realScale;}
double Complex::imag() const {return imagScale;}
void Complex::real(double newVal) {realScale = newVal;}
void Complex::imag(double newVal) {imagScale = newVal;}

Complex Complex::operator=(const Complex& complex)
{
    realScale = complex.realScale;
    imagScale = complex.imagScale;
    return *this;
}
void Complex::operator+=(const double scalar)
{
    realScale += scalar;
}
void Complex::operator+=(const Complex& complex)
{
    realScale += complex.realScale;
    imagScale += complex.imagScale;
}
void Complex::operator-=(const double scalar)
{
    realScale -= scalar;
}
void Complex::operator-=(const Complex& complex)
{
    realScale -= complex.realScale;
    imagScale -= complex.imagScale;
}
void Complex::operator/=(const double scalar)
{
    realScale /= scalar;
    imagScale /= scalar;
}
void Complex::operator/=(const Complex& complex)
{
    long double pow0 = pow(complex.realScale,2);
    long double pow1 = pow(complex.imagScale,2);
    long double divisor = pow0+pow1;
    long double is0 = imagScale*complex.realScale;
    long double is1 = realScale*complex.imagScale;
    long double rs0 = realScale*complex.realScale;
    long double rs1 = imagScale*complex.imagScale;
    realScale = (rs0+rs1)/divisor;
    imagScale = (is0-is1)/divisor;
}
void Complex::operator*=(const double scalar)
{
    realScale *= scalar;
    imagScale *= scalar;
}
void Complex::operator*=(const Complex& complex)
{
    long double is0 = realScale*complex.imagScale;
    long double is1 = imagScale*complex.realScale;
    long double rs0 = realScale*complex.realScale;
    long double rs1 = imagScale*complex.imagScale;
    realScale = (rs0-rs1);
    imagScale = (is0+is1);
}

Complex operator+(const Complex& complex)
{
    return complex;
}
Complex operator-(const Complex& complex)
{
    return Complex(-complex.real(), -complex.imag());
}

Complex operator+(const Complex& complex, const double scalar)
{
    return Complex(complex.real()+scalar, complex.imag());
}
Complex operator+(const Complex& leftCmplx, const Complex& rightCmplx)
{
    return Complex(leftCmplx.real()+rightCmplx.real(), leftCmplx.imag()+rightCmplx.imag());
}
Complex operator-(const Complex& complex, const double scalar)
{
    return Complex(complex.real()-scalar, complex.imag());
}
Complex operator-(const Complex& leftCmplx, const Complex& rightCmplx)
{
    return Complex(leftCmplx.real()-rightCmplx.real(), leftCmplx.imag()-rightCmplx.imag());
}
Complex operator/(const Complex& complex, const double scalar)
{
    return Complex(complex.real()/scalar, complex.imag()/scalar);
}
Complex operator/(const double scalar, const Complex& complex)
{
    long double divisor = pow(complex.real(),2)+pow(complex.imag(),2);
    return Complex(complex.real()*scalar/divisor, complex.imag()*scalar/divisor);
}
Complex operator/(const Complex& leftCmplx, const Complex& rightCmplx)
{
    long double pow0 = pow(rightCmplx.real(),2);
    long double pow1 = pow(rightCmplx.imag(),2);
    long double divisor = pow0+pow1;
    long double is0 = leftCmplx.imag()*rightCmplx.real();
    long double is1 = leftCmplx.real()*rightCmplx.imag();
    long double rs0 = leftCmplx.real()*rightCmplx.real();
    long double rs1 = leftCmplx.imag()*rightCmplx.imag();

    
    return Complex((rs0+rs1)/divisor, (is0-is1)/divisor);
}
Complex operator*(const Complex& complex, const double scalar)
{
    return Complex(complex.real()*scalar, complex.imag()*scalar);
}
Complex operator*(const Complex& leftCmplx, const Complex& rightCmplx)
{
    return Complex(
        (leftCmplx.real()*rightCmplx.real()-leftCmplx.imag()*rightCmplx.imag()),
        (leftCmplx.real()*rightCmplx.imag()+leftCmplx.imag()*rightCmplx.real())
    );
}

bool operator==(const Complex& complex, const double scalar)
{
    return complex.real() == scalar && complex.imag() == 0;
}
bool operator==(const Complex& leftCmplx, const Complex& rightCmplx)
{
    return leftCmplx.real() == rightCmplx.real() && leftCmplx.imag() == rightCmplx.imag();
}

bool operator!=(const Complex& complex, const double scalar)
{
    return !(complex==scalar);
}
bool operator!=(const Complex& leftCmplx, const Complex& rightCmplx)
{
    return !(leftCmplx==rightCmplx);
}

double real(const Complex& complex)
{
    return complex.real();
}
double imag(const Complex& complex)
{
    return complex.imag();
}

double abs(const Complex& complex)
{
    return sqrt(pow(complex.real(),2) + pow(complex.imag(),2));
}

Complex& operator<(Complex& leftCmplx, Complex& rightCmplx)
{
    return abs(leftCmplx) < abs(rightCmplx) ? leftCmplx : rightCmplx;
}

ostream& operator<<(ostream& os, const Complex& complex)
{
    os << "(" << complex.real() << "," << complex.imag() << ")";;
    return os;
}
istream& operator>>(istream& is, Complex& complex)
{
    double real = 0, imag = 0;
    if(is.peek() == '(')
    {
        is.ignore(1,' ');
        is >> real;
        if(is.peek() == ',')
        {
            is.ignore(1,' ');
            is >> imag;
        }
    }
    else
    {
        is >> real;
    }
    complex = Complex(real, imag);
    return is;
}