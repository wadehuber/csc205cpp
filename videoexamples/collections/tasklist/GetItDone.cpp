// GetItDone.cpp
// C++ version of GetItDone.java (implementation).

#include "GetItDone.h"
#include <iostream>
#include <sstream>

void GetItDone::addTask(Task p) {
    tasks.push_back(p);
}

void GetItDone::printTasks() {
    std::cout << "Tasks:" << std::endl;
    // Range-based for (Java's for-each over the tasks).
    for (const Task& t : tasks) {
        std::cout << "  " << t.toString() << std::endl;
    }
}

std::string GetItDone::toString() const {
    // Build the "[Task [...], Task [...]]" list text like Java did.
    std::ostringstream out;
    out << "GetItDone [tasks=[";
    for (std::size_t i = 0; i < tasks.size(); i++) {
        out << tasks[i].toString();
        if (i + 1 < tasks.size()) {
            out << ", ";
        }
    }
    out << "]]";
    return out.str();
}
