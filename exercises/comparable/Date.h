#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int month;
    int day;
    int year;

    // Allow the month to be given as a String (e.g. "September").
    int monthToInt(std::string m) const;

public:
    Date();
    Date(int month, int day, int year);
    Date(std::string month, int day, int year);

    int getMonth() const;
    void setMonth(int month);

    int getDay() const;
    void setDay(int day);

    int getYear() const;
    void setYear(int year);

    // The Java starter had NO toString() (printing a Date showed the default
    // object reference). C++ can't print an object without one, so we add a
    // simple toString() here so the driver compiles and prints something
    // readable.
    std::string toString() const;

    // EXERCISE: this is a "Comparable" exercise. In Java you would add
    //   "implements Comparable<Date>" and an "int compareTo(Date o)" method.
    // In C++ the equivalent is to add a compareTo method (returning a
    // negative / zero / positive int) and/or an "operator<". Add it here.
};

#endif
