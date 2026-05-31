#ifndef UNORDEREDLISTADT_H
#define UNORDEREDLISTADT_H

#include "ListADT.h"

// UnorderedListADT defines the interface to an unordered list collection.
// Elements are stored in any order the user desires.
//
// In Java this was "interface UnorderedListADT<T> extends ListADT<T>".
template <typename T>
class UnorderedListADT : public virtual ListADT<T> {   // virtual: shared base in the diamond
public:
    virtual ~UnorderedListADT() = default;

    // Adds the specified element to the front of this list.
    virtual void addToFront(T element) = 0;

    // Adds the specified element to the rear of this list.
    virtual void addToRear(T element) = 0;

    // Adds the specified element after the specified target.
    virtual void addAfter(T element, T target) = 0;
};

#endif
