#include "Date.h"
#include <algorithm>   // std::equal
#include <cctype>      // std::tolower

// Case-insensitive string comparison (like Java's equalsIgnoreCase).
static bool equalsIgnoreCase(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (std::size_t i = 0; i < a.size(); i++) {
        if (std::tolower((unsigned char) a[i]) != std::tolower((unsigned char) b[i])) {
            return false;
        }
    }
    return true;
}

Date::Date() {
    this->month = 1;
    this->day = 1;
    this->year = 1;
}

// Allow the month to be an int
Date::Date(int month, int day, int year) {
    setMonth(month);
    setDay(day);
    setYear(year);
}

Date::Date(std::string month, int day, int year) {
    setMonth(monthToInt(month));
    setDay(day);
    setYear(year);
}

int Date::monthToInt(std::string m) const {
    int month = 1;

    if (equalsIgnoreCase(m, "January"))
        month = 1;
    else if (equalsIgnoreCase(m, "February"))
        month = 2;
    else if (equalsIgnoreCase(m, "March"))
        month = 3;
    else if (equalsIgnoreCase(m, "April"))
        month = 4;
    else if (equalsIgnoreCase(m, "May"))
        month = 5;
    else if (equalsIgnoreCase(m, "June"))
        month = 6;
    else if (equalsIgnoreCase(m, "July"))
        month = 7;
    else if (equalsIgnoreCase(m, "August"))
        month = 8;
    else if (equalsIgnoreCase(m, "September"))
        month = 9;
    else if (equalsIgnoreCase(m, "October"))
        month = 10;
    else if (equalsIgnoreCase(m, "November"))
        month = 11;
    else if (equalsIgnoreCase(m, "December"))
        month = 12;

    return month;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    if (month <= 12) {
        this->month = month;
    } else {
        this->month = 12;
    }
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    int max_date = -1;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            max_date = 31;
            break;
        case 2:
            max_date = 28;
            break;
        default:
            max_date = 30;
    }

    if (day <= max_date) {
        this->day = day;
    } else {
        this->day = max_date;
    }
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    if (year >= 0) {
        this->year = year;
    } else {
        this->year = 2000;
    }
}

std::string Date::toString() const {
    return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
}
