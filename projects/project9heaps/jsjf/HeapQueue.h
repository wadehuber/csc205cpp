#ifndef HEAPQUEUE_H
#define HEAPQUEUE_H

#include <string>
#include "QueueADT.h"
#include "exceptions/ElementNotFoundException.h"
#include "exceptions/EmptyCollectionException.h"
#include "exceptions/NonComparableElementException.h"

// HeapQueue<T> implements QueueADT<T> using a heap (Project 9).
//
// HEADER-ONLY TEMPLATE (mirrors the Java generic class).
//
// STUDENT STUB: every method below is an "Auto-generated method stub" in the
// Java starter code (enqueue does nothing; dequeue/first return null; isEmpty
// returns false; size returns 0). They are reproduced here EXACTLY so the
// starter program behaves the same as the Java version. Students complete
// these as the programming project.
//
// Java stub "return null" for an object becomes "return T()" (a default-
// constructed value, e.g. 0 for int). The (void) casts just silence unused-
// parameter warnings; they do not change behavior.
template <typename T>
class HeapQueue : public QueueADT<T> {
public:
    // TODO Auto-generated method stub
    void enqueue(T element) override {
        // TODO Auto-generated method stub
        (void) element;
    }

    // TODO Auto-generated method stub
    T dequeue() override {
        // TODO Auto-generated method stub
        return T();   // Java returned null
    }

    // TODO Auto-generated method stub
    T first() override {
        // TODO Auto-generated method stub
        return T();   // Java returned null
    }

    // TODO Auto-generated method stub
    bool isEmpty() override {
        // TODO Auto-generated method stub
        return false;
    }

    // TODO Auto-generated method stub
    int size() override {
        // TODO Auto-generated method stub
        return 0;
    }

    // The Java class inherited Object.toString(); QueueADT<T> declares it
    // pure-virtual in C++, so we supply a minimal stub to keep the class
    // instantiable. (Not used by the driver.)
    std::string toString() override {
        return "";
    }
};

#endif
