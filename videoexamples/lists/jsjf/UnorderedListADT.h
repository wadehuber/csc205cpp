#ifndef UNORDEREDLISTADT_H
#define UNORDEREDLISTADT_H

#include "ListADT.h"

/**
 * UnorderedListADT defines the interface to an unordered list collection.
 * Elements are stored in any order the user desires.
 *
 * Java's "interface UnorderedListADT<T> extends ListADT<T>" becomes a C++
 * class template that publicly inherits from ListADT<T>.
 *
 * We inherit VIRTUALLY from ListADT so that a concrete list which derives from
 * both a *List base (e.g. LinkedList) and this ADT shares a single ListADT
 * subobject -- this is the C++ way to model Java's multiple-interface
 * inheritance (the "diamond") without ambiguity.
 *
 * @author Java Foundations
 * @version 4.0
 */
template <typename T>
class UnorderedListADT : public virtual ListADT<T> {
public:
    /** Adds the specified element to the front of this list. */
    virtual void addToFront(T element) = 0;

    /** Adds the specified element to the rear of this list. */
    virtual void addToRear(T element) = 0;

    /** Adds the specified element after the specified target. */
    virtual void addAfter(T element, T target) = 0;
};

#endif
