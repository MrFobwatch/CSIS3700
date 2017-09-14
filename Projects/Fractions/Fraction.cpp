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
    bool lessthan = false;
    if ((numer / denom) < (fraction.numer / fraction.denom)) {
        lessthan = true;
    }
    return lessthan;
}

bool Fraction::operator>(const Fraction &fraction) {
    bool greatthan = false;
    if ((numer / denom) > ((fraction.numer) / fraction.denom)) {
        greatthan = true;
    }
    return greatthan;
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
    Fraction frac(numer,denom);
    bool greatequal = false;
    if ((frac > fraction) || (frac == fraction)) {
        greatequal = true;
    }
    return greatequal;
}

bool Fraction::operator==(const Fraction &fraction) {
    bool equal = false;
    if ((numer / denom) == (fraction.numer / fraction.denom)) {
        equal = true;
    }
    return equal;
}

bool Fraction::operator!=(const Fraction &fraction) {
    Fraction frac(numer,denom);
    return !(frac==fraction);
}

bool Fraction::operator<(const int n) {
    bool lessthan = false;
    if ((numer / denom) < n ) {
        lessthan = true;
    }
    return lessthan;
}

bool Fraction::operator>(const int n) {
    bool greatthan = false;
    if ((numer / denom) > n ) {
        greatthan = true;
    }
    return greatthan;
}

bool Fraction::operator<=(const int n) {
    Fraction frac(numer,denom);
    bool lessequal = false;
    if ((frac < n) || (frac == n)) {
        lessequal = true;
    }
    return lessequal;
}

bool Fraction::operator>=(const int n) {
    Fraction frac(numer,denom);
    bool greatequal = false;
    if ((frac < n) || (frac == n)) {
        greatequal = true;
    }
    return greatequal;
}

bool Fraction::operator==(const int n) {
    bool equal = false;
    if ((numer / denom) == n) {
        equal = true;
    }
    return equal;
}

bool Fraction::operator!=(const int n) {
    Fraction frac(numer,denom);
    return !(frac == n);
}

std::istream &operator>>(std::istream &ins, Fraction &fraction){
    ins >> fraction.numer >> fraction.denom;
    return ins;
}

std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
    out << fraction.numer << "/" << fraction.denom;
    return out;
}



