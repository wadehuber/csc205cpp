#ifndef ARRAYUNORDEREDLIST_H
#define ARRAYUNORDEREDLIST_H

#include "ArrayList.h"
#include "UnorderedListADT.h"
#include "exceptions/ElementNotFoundException.h"

/**
 * ArrayUnorderedList represents an array implementation of an unordered list.
 *
 * @author Java Foundations
 * @version 4.0
 */
template <typename T>
class ArrayUnorderedList : public ArrayList<T>, public UnorderedListADT<T> {
public:
    /** Creates an empty list using the default capacity. */
    ArrayUnorderedList()
        : ArrayList<T>() {}

    /** Creates an empty list using the specified capacity. */
    ArrayUnorderedList(int initialCapacity)
        : ArrayList<T>(initialCapacity) {}

    /** Adds the specified element to the front of this list. */
    void addToFront(T element) override {
        if (this->size() == (int)this->list.size())
            this->expandCapacity();

        // shift elements up one
        for (int scan = this->rear; scan > 0; scan--) {
            this->list[scan] = this->list[scan - 1];
        }

        this->list[0] = element;
        this->rear++;
        this->modCount++;
    }

    /** Adds the specified element to the rear of this list. */
    void addToRear(T element) override {
        if (this->size() == (int)this->list.size())
            this->expandCapacity();

        this->list[this->rear] = element;
        this->rear++;
        this->modCount++;
    }

    /** Adds the specified element after the specified target element. */
    void addAfter(T element, T target) override {
        if (this->size() == (int)this->list.size())
            this->expandCapacity();

        int scan = 0;

        // find the insertion point
        while (scan < this->rear && !(target == this->list[scan])) {
            scan++;
        }

        if (scan == this->rear)
            throw ElementNotFoundException("UnorderedList");

        scan++;

        // shift elements up one
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
