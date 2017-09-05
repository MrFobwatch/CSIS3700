//
// Created by Kevin on 9/1/2017.
//

#include "Fraction.h"

Fraction::Fraction() {
    setNumer(0);
    setDenom(1);
}
Fraction::Fraction(int numer){
    setNumer(numer);
    setDenom(1);
}

Fraction::Fraction(int numer, int denom){
    setNumer(numer);
    setDenom(denom);
}

int Fraction::getNumer() const {
    return numer;
}

void Fraction::setNumer(int numer) {
    Fraction::numer = numer;
}

int Fraction::getDenom() const {
    return denom;
}

void Fraction::setDenom(int denom) {
    Fraction::denom = denom;
}

void Fraction::setFrac() {
    setNumer(0);
    setDenom(1);
}

void Fraction::setFrac(int numer) {
    setNumer(numer);
    setDenom(1);
}

void Fraction::setFrac(int numer, int denom) {
    setNumer(numer);
    setDenom(denom);
}

Fraction Fraction::operator=(const Fraction &fraction) {
    numer = fraction.numer;
    denom = fraction.denom;
}

Fraction operator+(const Fraction &fraction1, const Fraction &fraction2) {
    int numerResult,denomResult;
    numerResult = fraction1.getNumer() + fraction2.getNumer();
    denomResult = fraction1.getDenom() + fraction2.getDenom();
    return Fraction(numerResult, denomResult);
}

Fraction operator-(const Fraction &fraction1, const Fraction &fraction2) {
    int numerResult,denomResult;
    numerResult = fraction1.getNumer() - fraction2.getNumer();
    denomResult = fraction1.getDenom() - fraction2.getDenom();
    return Fraction(numerResult, denomResult);
}

Fraction operator*(const Fraction &fraction1, const Fraction &fraction2) {
    int numerResult,denomResult;
    numerResult = fraction1.getNumer() * fraction2.getNumer();
    denomResult = fraction1.getDenom() * fraction2.getDenom();
    return Fraction(numerResult, denomResult);
}

Fraction operator/(const Fraction &fraction1, const Fraction &fraction2) {
    int numerResult,denomResult;
    numerResult = fraction1.getNumer() * fraction2.getDenom();
    denomResult = fraction1.getDenom() * fraction2.getNumer();
    return Fraction(numerResult, denomResult);
}

bool operator<(const Fraction &fraction1, const Fraction &fraction2) {
    bool lessthan = false;
    if ((fraction1.getNumer() / fraction2.getDenom()) < (fraction2.getNumer() / fraction2.getDenom())) {
        lessthan = true;
    }
    return lessthan;
}

bool operator>(const Fraction &fraction1, const Fraction &fraction2) {
    bool greatthan = false;
    if ((fraction1.getNumer() / fraction2.getDenom()) > (fraction2.getNumer() / fraction2.getDenom())) {
        greatthan = true;
    }
    return greatthan;
}

bool operator<=(const Fraction &fraction1, const Fraction &fraction2) {
    bool lessequal = false;
    if ((fraction1 < fraction2) || (fraction1 == fraction2)) {
        lessequal = true;
    }
    return lessequal;
}

bool operator>=(const Fraction &fraction1, const Fraction &fraction2) {
    bool greatequal = false;
    if ((fraction1 > fraction2) || (fraction1 == fraction2)) {
        greatequal = true;
    }
    return greatequal;
}

bool operator==(const Fraction &fraction1, const Fraction &fraction2) {
    bool equal = false;
    if ((fraction1.getNumer() / fraction2.getDenom()) == (fraction2.getNumer() / fraction2.getDenom())) {
        equal = true;
    }
    return equal;
}

bool operator!=(const Fraction &fraction1, const Fraction &fraction2) {
    return !(fraction1==fraction2);
}

bool operator<(const Fraction &fraction, const int n) {
    bool lessthan = false;
    if ((fraction.getNumer() / fraction.getDenom()) < n ) {
        lessthan = true;
    }
    return lessthan;
}

bool operator>(const Fraction &fraction, const int n) {
    bool greatthan = false;
    if ((fraction.getNumer() / fraction.getDenom()) > n ) {
        greatthan = true;
    }
    return greatthan;
}

bool operator<=(const Fraction &fraction, const int n) {
    bool lessequal = false;
    if ((fraction < n) || (fraction == n)) {
        lessequal = true;
    }
    return lessequal;
}

bool operator>=(const Fraction &fraction, const int n) {
    bool greatequal = false;
    if ((fraction < n) || (fraction == n)) {
        greatequal = true;
    }
    return greatequal;
}

bool operator==(const Fraction &fraction, const int n) {
    bool equal = false;
    if ((fraction.getNumer()/fraction.getDenom()) == n) {
        equal = true;
    }
    return equal;
}

bool operator!=(const Fraction &fraction, const int n) {
    return !(fraction == n);
}

std::istream &operator>>(std::istream &ins, Fraction &fraction){
    ins >> fraction.numer >> fraction.denom;
    return ins;
}

std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
    out << fraction.getNumer() << "/" << fraction.getDenom();
    return out;
}


