// ObjectWriter.cpp
//
// Java used ObjectOutputStream.writeObject(student) to serialize a Student
// to "students.dat" automatically.
//
// C++ has no automatic serialization, so we open a plain text std::ofstream
// and call our own Student::save(), which writes each field as text.

#include <iostream>
#include <fstream>
#include "Student.h"

int main() {
    std::ofstream out("students.dat");
    if (!out) {
        std::cerr << "Could not open students.dat for writing" << std::endl;
        return 1;
    }

    Student student("Anne Elliot", 1815);
    student.save(out);   // manual "serialization" (writes each field as text)

    return 0;
}
