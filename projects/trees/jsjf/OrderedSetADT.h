#ifndef ORDEREDSETADT_H
#define ORDEREDSETADT_H

#include <string>

// OrderedSetADT defines the interface to an ordered set collection.
//
// In Java this was a plain "interface OrderedSetADT<T>". In C++ an interface is
// a class template with only pure virtual functions (= 0) plus a virtual
// destructor.
//
// NOTE on iterators: the Java interface also declared iterator() returning a
// java.util.Iterator<T>. C++ has no single universal iterator type, so it is
// omitted here (the driver prints sets via toString(), not by iterating).
template <typename T>
class OrderedSetADT {
public:
    virtual ~OrderedSetADT() = default;

    // Adds the specified element to the proper location in this set.
    virtual void addElement(T element) = 0;

    // Removes and returns the specified element from this set.
    virtual T removeElement(T targetElement) = 0;

    // Returns the specified element from the set.
    virtual T find(T targetElement) = 0;

    // Returns the smallest element in this set without removing it.
    virtual T findMin() = 0;

    // Returns the largest element in this set without removing it.
    virtual T findMax() = 0;

    // Returns true if the set contains a matching element, false otherwise.
    virtual bool contains(T targetElement) = 0;

    // Returns the string representation of the elements in the set in order.
    virtual std::string toString() = 0;
};

#endif
