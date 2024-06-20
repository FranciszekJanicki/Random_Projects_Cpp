#include "Rational.h"

Rational::Rational(int num, int den) : num_(num) { // inicjalizuje pole num_ wartoscia num
    if (den) {
        den_ = den;
    } else {
        den_ = 1;
    }
}

void Rational::set(int num, int den) {
    num_ = num;
    if (den) {
        den_ = den;
    }
}

int Rational::num() const {
    return num_;
}

int Rational::den() const {
    return den_;
}

void Rational::set_num(int num) {
    num_ = num;
}

void Rational::set_den(int den) {
    if (den) {
        den_ = den;
    }
}

Rational Rational::operator+(const Rational& rhs) const {
    return Rational(this->num_ * rhs.den_ + rhs.num_ * this->den_,
        this->den_ * rhs.den_);
}

Rational Rational::operator-(const Rational& rhs) const {
    return Rational(this->num_ * rhs.den_ - rhs.num_ * this->den_,
        this->den_ * rhs.den_);
}

Rational Rational ::operator*(const Rational& rhs) const {
    return Rational(this->num_ * rhs.num_, this->den_ * rhs.den_);
}

Rational::operator double() const {
    return static_cast<double>(num_) / den_;
}

/*Rational Rational::add(const Rational& other) const {
    return Rational(num_ * other.den_ + other.num_ * den_,
                    den_ * other.den_);
}

Rational Rational::subtract(const Rational &other) const {
    return Rational(num_ * other.den_ - other.num_ * den_,
                    den_ * other.den_);
}*/

void Rational::print() const {
    if (den_ == 1) {
        std::cout << num_;
    } else {
        std::cout << num_ << "/" << den_;
    }
}

ostream& operator<<(ostream& str, const Rational& rhs) {
    if (rhs.den_ == 1) {
        str << rhs.num_;
    }
    else {
        str << rhs.num_ << '/' << rhs.den_;
    }
    return str;
}

istream& operator>>(istream& str, Rational& rhs) {
    string input;
    str >> input;

    size_t pos = input.find('/');

    if (pos != std::string::npos) {
        string numStr = input.substr(0, pos);
        string denStr = input.substr(pos + 1);
        rhs.set_num(stoi(numStr));
        rhs.set_den(stoi(denStr));
    }
    else {
        rhs.set_num(stoi(input));
        rhs.set_den(1);
    }
    return str;
}