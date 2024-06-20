#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Time {
    int seconds = 0, minutes = 0, hours = 0;
public:
    Time(int secs = 0);
    void convertToSec();
    void convertToMin();
    void convertToHour();
    void setSecs(const int& s);
    void setMins(const int& m);
    void setHours(const int& h);
    Time operator+(const Time& rhs) const;
    Time operator-(const Time& rhs) const;
    Time operator*(const int& scalar) const;
    friend std::ostream& operator<<(std::ostream& str, const Time& rhs);
    friend std::istream& operator>>(std::istream& str, Time& rhs);
    operator int() const;  // Conversion operator to int
};

