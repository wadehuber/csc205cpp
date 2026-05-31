#ifndef STACKADT_H
#define STACKADT_H

#include <string>

// StackADT defines the interface to a stack collection.
//
// In Java this was "interface StackADT<T>". In C++ an interface becomes a
// class template made entirely of pure virtual methods (= 0) plus a virtual
// destructor.
//
// @author Java Foundations
// @version 4.0
template <typename T>
class StackADT {
public:
    virtual ~StackADT() = default;

    // Adds the specified element to the top of this stack.
    virtual void push(T element) = 0;

    // Removes and returns the top element from this stack.
    virtual T pop() = 0;

    // Returns without removing the top element of this stack.
    virtual T peek() = 0;

    // Returns true if this stack contains no elements.
    virtual bool isEmpty() = 0;

    // Returns the number of elements in this stack.
    virtual int size() = 0;

    // Returns a string representation of this stack.
    virtual std::string toString() = 0;
};

#endif
