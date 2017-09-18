//
// Created by Kevin on 9/1/2017.
//

#include "Fraction.h"

static int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

Fraction::Fraction() {
    setFrac();
}
Fraction::Fraction(int num){
    setFrac(num);
}

Fraction::Fraction(int num, int den){
   setFrac(num,den);
}

void Fraction::setFrac() {
    numer = 0;
    denom = 1;
}

void Fraction::setFrac(int num) {
    numer = num;
    denom = 1;
}

void Fraction::setFrac(int num, int den) { //Also reduces fractions
    if (num < 0) {
        num = -num;
        den = -den;
    }
    int g = gcd(num, den);
    num /= g;
    den /= g;
    numer = num;
    denom = den;
}

Fraction Fraction::operator=(const Fraction &fraction) {
    numer = fraction.numer;
    denom = fraction.denom;
}

Fraction Fraction::operator+(const Fraction &fraction) {
    int numerResult,denomResult;
    numerResult = numer * fraction.denom + fraction.numer * denom;
    denomResult = denom * fraction.denom;
    return Fraction(numerResult, denomResult);
}

Fraction Fraction::operator-(const Fraction &fraction) { //Simplify at the end of subtraction
    int numerResult,denomResult;
    numerResult = numer - fraction.numer;
    if (fraction.denom == denom) {
        denomResult = fraction.denom;
    }
    else {
        numerResult = ((numer * fraction.denom) - (fraction.numer * denom));
        denomResult = (denom * fraction.denom);
    }
    return Fraction(numerResult, denomResult);
}

Fraction Fraction::operator*(const Fraction &fraction) {
    int numerResult,denomResult;
    numerResult = numer * fraction.numer;
    denomResult = denom * fraction.denom;
    return Fraction(numerResult, denomResult);
}

Fraction Fraction::operator/(const Fraction &fraction) {
    int numerResult,denomResult;
    numerResult = numer * fraction.denom;
    denomResult = denom * fraction.numer;
    return Fraction(numerResult, denomResult);
}

bool Fraction::operator<(const Fraction &fraction) {
    if (denom * fraction.denom >= 0)
    {
        return numer * fraction.denom < fraction.numer * denom;
    }
    else
    {
        return numer * fraction.denom > fraction.numer * denom;
    }
}

bool Fraction::operator>(const Fraction &fraction) {
    if (denom * fraction.denom >= 0)
    {
        return numer * fraction.denom > fraction.numer * denom;
    }
    else
    {
        return numer * fraction.denom < fraction.numer * denom;
    }
}

bool Fraction::operator<=(const Fraction &fraction) {
    Fraction frac(numer,denom);
    bool lessequal = false;
    if ((frac < fraction) || (frac == fraction)) {
        lessequal = true;
    }
    return lessequal;
}

bool Fraction::operator>=(const Fraction &fraction) {
    bool greatequal = false;
    if ((*this > fraction) || (*this == fraction)) {
        greatequal = true;
    }
    return greatequal;
}

bool Fraction::operator==(const Fraction &fraction) {
    return (numer == fraction.numer) && (denom == fraction.denom);
}

bool Fraction::operator!=(const Fraction &fraction) {
    return !(*this==fraction);
}

bool Fraction::operator<(const int n) {
    return *this < Fraction(n);
}

bool Fraction::operator>(const int n) {
    return *this > Fraction(n);
}

bool Fraction::operator<=(const int n) {
    return *this <= Fraction(n);
}

bool Fraction::operator>=(const int n) {
    return *this >= Fraction(n);
}

bool Fraction::operator==(const int n) {
    return *this == Fraction(n);
}

bool Fraction::operator!=(const int n) {
    return *this != Fraction(n);
}

std::istream &operator>>(std::istream &ins, Fraction &fraction){
    char slash='/';
    ins >> fraction.numer >> slash >> fraction.denom;
    return ins;
}

std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
    out << fraction.numer << "/" << fraction.denom;
    return out;
}



