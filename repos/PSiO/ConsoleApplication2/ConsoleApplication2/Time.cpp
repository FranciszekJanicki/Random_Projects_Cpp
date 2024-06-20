#include "Time.h"

Time::Time(int secs) : seconds(secs), minutes(0), hours(0) {
}

void Time::convertToSec() {
    int totalSeconds = this->hours * 3600 + this->minutes * 60 + this->seconds;
    this->hours = 0;
    this->minutes = 0;
    this->seconds = totalSeconds;
}

void Time::convertToMin() {
    int totalMinutes = this->hours * 60 + this->minutes + this->seconds / 60;
    this->hours = 0;
    this->minutes = totalMinutes;
    this->seconds %= 60;
}

void Time::convertToHour() {
    int totalHours = this->hours + (this->minutes + this->seconds / 60) / 60;
    this->hours = totalHours;
    this->minutes = (this->minutes + this->seconds / 60) % 60;
    this->seconds %= 60;
}

void Time::setSecs(const int& s) {
    seconds = s;
}

void Time::setMins(const int& m) {
    minutes = m;
}

void Time::setHours(const int& h) {
    hours = h;
}

Time Time::operator+(const Time& rhs) const {
    return Time(seconds + rhs.seconds);
}

Time Time::operator-(const Time& rhs) const {
    return Time(seconds - rhs.seconds);
}

Time Time::operator*(const int& scalar) const {
    return Time(scalar * this->seconds);
}

std::ostream& operator<<(std::ostream& str, const Time& rhs) {
    Time temp = rhs;  // Create a temporary copy to avoid modifying the original object
    temp.convertToHour();
    str << temp.hours << "h:" << temp.minutes << "m:" << temp.seconds << "s\n";
    return str;
}


std::istream& operator>>(std::istream& str, Time& rhs) {
    int hours, minutes, seconds;
    char colon1, colon2;

    // Read the input as "10h:8m:41s"
    str >> hours >> colon1 >> minutes >> colon2 >> seconds;

    if (str.fail() || colon1 != 'h' || colon2 != 'm') {
        // Handle input failure
        str.setstate(std::ios::failbit);
        return str;
    }

    // Check for the presence of the second colon and 's'
    if (str.get() != ':' || str.get() != 's') {
        // Handle input failure
        str.setstate(std::ios::failbit);
        return str;
    }

    rhs.setHours(hours);
    rhs.setMins(minutes);
    rhs.setSecs(seconds);

    return str;
}

Time::operator int() const {
    Time copy(*this);
    copy.convertToSec();
    return static_cast<int>(copy.seconds);
}