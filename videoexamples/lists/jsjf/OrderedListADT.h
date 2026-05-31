#ifndef ORDEREDLISTADT_H
#define ORDEREDLISTADT_H

#include "ListADT.h"

/**
 * OrderedListADT defines the interface to an ordered list collection. Only
 * Comparable elements are stored, kept in the order determined by
 * the inherent relationship among the elements.
 *
 * Java's "interface OrderedListADT<T> extends ListADT<T>" becomes a C++
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
class OrderedListADT : public virtual ListADT<T> {
public:
    /** Adds the specified element to this list at the proper location. */
    virtual void add(T element) = 0;
};

#endif
