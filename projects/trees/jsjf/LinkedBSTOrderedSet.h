#ifndef LINKEDBSTORDEREDSET_H
#define LINKEDBSTORDEREDSET_H

#include <string>
#include "OrderedSetADT.h"

// LinkedBSTOrderedSet implements the OrderedSetADT interface.
//
// HEADER-ONLY TEMPLATE (mirrors the Java generic class).
//
// *** PROGRAMMING-PROJECT STUBS ***
// This is the STUDENT-STARTER version: in the Java source every method is an
// auto-generated stub ("TODO Auto-generated method stub") that does nothing or
// returns null/false. We reproduce those stubs faithfully so the project
// behaves exactly like the unfinished Java starter code. DO NOT implement the
// set logic here.
//
// In the driver, an empty LinkedBSTOrderedSet is printed; toString() returns ""
// just as the Java default would (the Java starter never overrode toString, so
// the in-order contents were empty). We provide an empty-string toString() so
// the program compiles and the printed line matches.
template <typename T>
class LinkedBSTOrderedSet : public OrderedSetADT<T> {
public:
    LinkedBSTOrderedSet() {
    }

    virtual ~LinkedBSTOrderedSet() = default;

    void addElement(T element) override {
        // TODO Auto-generated method stub
        (void) element;
    }

    T removeElement(T targetElement) override {
        // TODO Auto-generated method stub
        // (Java returned null; in C++ we return a default-constructed T().)
        (void) targetElement;
        return T();
    }

    T find(T targetElement) override {
        // TODO Auto-generated method stub
        // (Java returned null; in C++ we return a default-constructed T().)
        (void) targetElement;
        return T();
    }

    T findMin() override {
        // TODO Auto-generated method stub
        // (Java returned null; in C++ we return a default-constructed T().)
        return T();
    }

    T findMax() override {
        // TODO Auto-generated method stub
        // (Java returned null; in C++ we return a default-constructed T().)
        return T();
    }

    bool contains(T targetElement) override {
        // TODO Auto-generated method stub
        (void) targetElement;
        return false;
    }

    // The Java starter never overrode toString(); an empty set prints as empty.
    std::string toString() override {
        return "";
    }
};

#endif
