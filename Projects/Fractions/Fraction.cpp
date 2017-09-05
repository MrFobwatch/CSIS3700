//
// Created by Kevin on 9/1/2017.
//

#include "Fraction.h"

Fraction::Fraction() {
    this->numer=0;
    this->denom=1;
}
Fraction::Fraction(int numer){
    this->numer=numer;
    this->denom=1;
}

Fraction::Fraction(int numer, int denom){
    this->numer=numer;
    this->denom=denom;
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

void Fraction::FractionEquals() {

}

void Fraction::setFrac(int numer, int denom) {

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
    if ((fraction1.getNumer() / fraction2.getDenom()) < (fraction2.getNumer() / fraction2.getDenom())) {
        greatthan = true;
    }
    return greatthan;
}

bool operator<=(const Fraction &fraction1, const Fraction &fraction2) {
    bool lessequal = false;
    return lessequal;
}

bool operator>=(const Fraction &fraction1, const Fraction &fraction2) {
    bool greatequal = false;
    return greatequal;
}

bool operator==(const Fraction &fraction1, const Fraction &fraction2) {
    bool lessequal = false;
    return lessequal;
}

bool operator!=(const Fraction &fraction1, const Fraction &fraction2) {
    bool lessequal = false;
    return lessequal;
}

bool operator<(const Fraction &fraction, const int n) {
    bool lessequal = false;
    return lessequal;
}

bool operator>(const Fraction &fraction, const int n) {
    bool lessequal = false;
    return lessequal;
}

bool operator<=(const Fraction &fraction, const int n) {
    bool lessequal = false;
    return lessequal;
}

bool operator>=(const Fraction &fraction, const int n) {
    bool lessequal = false;
    return lessequal;
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

std::istream &operator>>(std::istream &in, Fraction &fraction){

    return in;
}

std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
    out << fraction.getNumer() << "/" << fraction.getDenom();
    return out;
}


