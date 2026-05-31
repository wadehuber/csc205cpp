// Task.h
// C++ version of Task.java (header).
//
// A Task "implements" the Priority interface -> in C++ it inherits from the
// Priority abstract base class and overrides its methods.

#ifndef TASK_H
#define TASK_H

#include <string>
#include <ostream>
#include "Priority.h"

class Task : public Priority {
private:
    int priority;
    std::string name;

public:
    Task(int priority, std::string name);

    void setPriority(int p) override;
    int getPriority() override;

    // Java's toString().
    std::string toString() const;
};

// So a Task can be printed with std::cout << task (Java got this from
// toString(); in C++ we wire it up with operator<<).
std::ostream& operator<<(std::ostream& os, const Task& task);

#endif
