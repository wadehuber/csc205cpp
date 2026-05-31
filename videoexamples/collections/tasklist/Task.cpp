// Task.cpp
// C++ version of Task.java (implementation).

#include "Task.h"

Task::Task(int priority, std::string name) : priority(priority), name(name) {}

void Task::setPriority(int p) {
    priority = p;
}

int Task::getPriority() {
    return priority;
}

std::string Task::toString() const {
    return "Task [priority=" + std::to_string(priority) + ", name=" + name + "]";
}

std::ostream& operator<<(std::ostream& os, const Task& task) {
    os << task.toString();
    return os;
}
