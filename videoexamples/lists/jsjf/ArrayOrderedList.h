#ifndef ARRAYORDEREDLIST_H
#define ARRAYORDEREDLIST_H

#include "ArrayList.h"
#include "OrderedListADT.h"
#include "exceptions/NonComparableElementException.h"

/**
 * ArrayOrderedList represents an array implementation of an ordered list.
 *
 * COMPARABLE NOTE: Java required elements to "implement Comparable" and called
 * element.compareTo(list[scan]). In C++ this is duck-typed: the element type T
 * must provide operator<. The Java test "comparableElement.compareTo(b) > 0"
 * (i.e. element is greater than b) becomes "b < element".
 *
 * @author Java Foundations
 * @version 4.0
 */
template <typename T>
class ArrayOrderedList : public ArrayList<T>, public OrderedListADT<T> {
public:
    /** Creates an empty list using the default capacity. */
    ArrayOrderedList()
        : ArrayList<T>() {}

    /** Creates an empty list using the specified capacity. */
    ArrayOrderedList(int initialCapacity)
        : ArrayList<T>(initialCapacity) {}

    /**
     * Adds the specified Comparable element to this list, keeping
     * the elements in sorted order.
     */
    void add(T element) override {
        // In Java a runtime "instanceof Comparable" check threw
        // NonComparableElementException here. In C++ comparability is enforced
        // at compile time (T must define operator<), so the check is implicit.

        if (this->size() == (int)this->list.size()) {
            this->expandCapacity();
        }

        int scan = 0;

        // find the insertion location
        while (scan < this->rear && this->list[scan] < element) {
            scan++;
        }

        // shift existing elements up one
        for (int shift = this->rear; shift > scan; shift--) {
            this->list[shift] = this->list[shift - 1];
        }

        // insert element
        this->list[scan] = element;
        this->rear++;
        this->modCount++;
    }
};

#endif
