// Student.cpp

#include "Student.h"
#include <sstream>

Student::Student(const std::string& name, int id)
    : name(name), id(id) {
}

std::string Student::toString() const {
    std::ostringstream sb;
    sb << "Student[name=" << name << ", id=" << id << "]";
    return sb.str();
}

// Write each field on its own line. The name goes first, then the id.
// Putting the name on its own line lets us read it back with getline even
// if the name contains spaces.
void Student::save(std::ofstream& out) const {
    out << name << "\n";
    out << id << "\n";
}

// Read the fields back in the SAME order they were written.
Student Student::load(std::ifstream& in) {
    std::string name;
    int id;
    std::getline(in, name);   // read the whole name line (may contain spaces)
    in >> id;                 // read the id
    return Student(name, id);
}
