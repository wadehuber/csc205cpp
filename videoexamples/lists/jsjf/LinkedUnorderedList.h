#ifndef LINKEDUNORDEREDLIST_H
#define LINKEDUNORDEREDLIST_H

#include "LinkedList.h"
#include "UnorderedListADT.h"

/**
 * LinkedUnorderedList represents a singly linked implementation of an
 * unordered list.
 *
 * As in the Java Foundations book, the add* operations are left as a
 * "Programming Project"; we preserve those empty bodies exactly.
 *
 * @author Java Foundations
 * @version 4.0
 */
template <typename T>
class LinkedUnorderedList : public LinkedList<T>, public UnorderedListADT<T> {
public:
    /** Creates an empty list. */
    LinkedUnorderedList()
        : LinkedList<T>() {}

    /** Adds the specified element to the front of this list. */
    void addToFront(T element) override {
        // To be completed as a Programming Project
        (void)element;
    }

    /** Adds the specified element to the rear of this list. */
    void addToRear(T element) override {
        // To be completed as a Programming Project
        (void)element;
    }

    /** Adds the specified element to this list after the given target. */
    void addAfter(T element, T target) override {
        // To be completed as a Programming Project
        (void)element;
        (void)target;
    }
};

#endif
