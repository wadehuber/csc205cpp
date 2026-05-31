#ifndef LISTADT_H
#define LISTADT_H

#include <string>

// ListADT defines the interface to a general list collection.
//
// In Java this was "interface ListADT<T> extends Iterable<T>". The Java
// version also declared iterator(); in C++ we provide range-based iteration
// directly on ArrayList (begin()/end()) instead of a universal Iterator type,
// so the iterator() method is omitted from this interface.
template <typename T>
class ListADT {
public:
    virtual ~ListADT() = default;

    // Removes and returns the first element from this list.
    virtual T removeFirst() = 0;

    // Removes and returns the last element from this list.
    virtual T removeLast() = 0;

    // Removes and returns the specified element from this list.
    virtual T remove(T element) = 0;

    // Returns a reference to the first element in this list.
    virtual T first() = 0;

    // Returns a reference to the last element in this list.
    virtual T last() = 0;

    // Returns true if this list contains the specified target element.
    virtual bool contains(T target) = 0;

    // Returns true if this list contains no elements.
    virtual bool isEmpty() = 0;

    // Returns the number of elements in this list.
    virtual int size() = 0;

    // Returns a string representation of this list.
    virtual std::string toString() = 0;
};

#endif
