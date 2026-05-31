#ifndef LINKEDORDEREDLIST_H
#define LINKEDORDEREDLIST_H

#include "LinkedList.h"
#include "OrderedListADT.h"

/**
 * LinkedOrderedList represents a singly linked implementation of an
 * ordered list.
 *
 * As in the Java Foundations book, add() is left as a "Programming Project";
 * we preserve that empty body exactly.
 *
 * @author Java Foundations
 * @version 4.0
 */
template <typename T>
class LinkedOrderedList : public LinkedList<T>, public OrderedListADT<T> {
public:
    /** Creates an empty list. */
    LinkedOrderedList()
        : LinkedList<T>() {}

    /**
     * Adds the specified element to this list at the location determined by
     * the element's natural ordering.
     */
    void add(T element) override {
        // To be completed as a Programming Project
        (void)element;
    }
};

#endif
