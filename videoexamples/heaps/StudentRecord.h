#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

#include <string>
#include <sstream>

// StudentRecord is a small demo class we add to a heap.
//
// HEADER-ONLY demo data class.
//
// Java implemented Comparable<StudentRecord> (compareTo by Name) and
// overrode equals() (also by Name). C++ uses operator< and operator==.
//
// The static field nextNum assigns each record a unique studentNo starting at
// 1000, exactly like Java. In C++ a static data member is defined once; for a
// header-only class we use an inline static (C++17) so it lives in the header.
class StudentRecord {
private:
    std::string Name;
    int studentNo;
    double gpa;

    inline static int nextNum = 1000;   // C++17 inline static (Java: static int)

public:
    StudentRecord(const std::string& name, double gpa) {
        Name = name;
        this->studentNo = nextNum;
        nextNum++;
        this->gpa = gpa;
    }

    // Default constructor for generic slots (Java used null).
    StudentRecord() : Name(""), studentNo(0), gpa(0.0) {}

    std::string getName() const { return Name; }
    void setName(const std::string& name) { Name = name; }

    double getGpa() const { return gpa; }
    void setGpa(double gpa) { this->gpa = gpa; }

    std::string toString() const {
        std::ostringstream out;
        // Default double formatting matches Java's Double.toString for these
        // values (e.g. 3.1 prints as "3.1", not "3.100000").
        out << "[Name=" << Name << ", studentNo=" << studentNo
            << ", gpa=" << gpa << "]";
        return out.str();
    }

    // Java compareTo(): order by Name.
    bool operator<(const StudentRecord& that) const {
        return Name < that.Name;   // Java: this.Name.compareTo(that.Name) < 0
    }

    // Java equals(): equal by Name.
    bool operator==(const StudentRecord& that) const {
        return Name == that.Name;
    }
};

#endif
