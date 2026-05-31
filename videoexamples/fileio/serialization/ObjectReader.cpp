// ObjectReader.cpp
//
// Java used ObjectInputStream.readObject() to read a Student back from
// "students.dat" automatically.
//
// C++ has no automatic serialization, so we open a plain text std::ifstream
// and call our own Student::load(), which reads each field back as text.

#include <iostream>
#include <fstream>
#include "Student.h"

int main() {
    std::ifstream in("students.dat");
    if (!in) {
        std::cerr << "Could not open students.dat for reading" << std::endl;
        return 1;
    }

    Student student = Student::load(in);   // manual "deserialization"
    std::cout << student.toString() << std::endl;

    return 0;
}
