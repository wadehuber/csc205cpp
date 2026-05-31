// Student.h
//
// In Java, Student implemented Serializable, so Java could automatically
// write the whole object to a file with ObjectOutputStream and read it back
// with ObjectInputStream.
//
// C++ has NO built-in object serialization. Instead we do it MANUALLY: we
// write each field as text (one per line) with save(), and read the fields
// back with load(). This manual technique is what replaces Java's Serializable.

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <fstream>

class Student {
private:
    std::string name;
    int id;

public:
    Student(const std::string& name, int id);

    // Matches Java's toString().
    std::string toString() const;

    // Manual "serialization": write each field on its own line.
    void save(std::ofstream& out) const;

    // Manual "deserialization": read the fields back and build a Student.
    // (static so you call it as Student::load(in), with no existing object.)
    static Student load(std::ifstream& in);
};

#endif
