#ifndef MYBAG_H
#define MYBAG_H

#include "Bag.h"

// Java: "class MyBag<T> implements Bag<T>".
//
// NOTE: template classes are written entirely in the header file -- there
// is no MyBag.cpp. (C++ needs to see the whole template to build it for a
// specific type like MyBag<int>.)
//
// This is STARTER CODE: the methods are intentional stubs that you will
// fill in. They keep the same stub behavior as the Java version.
template <typename T>
class MyBag : public Bag<T> {
public:
    // Java returned false here as a stub.
    bool isEmpty() override {
        return false;
    }

    // Java returned 0 here as a stub.
    int count() override {
        return 0;
    }

    // Java left this empty as a stub.
    void addToBag(T item) override {
    }

    // Java's iterator() returned null as a stub. Iteration (begin()/end())
    // is not provided yet -- add it when you implement the bag.
};

#endif
