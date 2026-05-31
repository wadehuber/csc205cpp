// ToDoList.h
// C++ version of ToDoList.java.
//
// Java's  interface ToDoList extends Iterable<Task>  becomes a C++ abstract
// base class. The "extends Iterable<Task>" part means a ToDoList can be looped
// over; in C++ we express that by having the concrete class (GetItDone)
// provide begin()/end() and a Java-style iterator(). We keep this base class
// focused on the two task methods.

#ifndef TODOLIST_H
#define TODOLIST_H

#include "Task.h"

class ToDoList {
public:
    virtual ~ToDoList() {}            // virtual destructor for a base class
    virtual void addTask(Task p) = 0;
    virtual void printTasks() = 0;
};

#endif
