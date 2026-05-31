#ifndef ARRAYUNORDEREDLIST_H
#define ARRAYUNORDEREDLIST_H

#include "ArrayList.h"
#include "UnorderedListADT.h"
#include "exceptions/ElementNotFoundException.h"

// ArrayUnorderedList represents an array implementation of an unordered list.
//
// HEADER-ONLY TEMPLATE (mirrors the Java generic class).
//
// Java was "extends ArrayList<T> implements UnorderedListADT<T>". In C++ we
// inherit ArrayList<T> (the implementation) and UnorderedListADT<T> (the extra
// interface). ArrayList<T> already supplies ListADT<T>.
//
// IMPORTANT FIDELITY NOTE: in the PROJECT Java source addToFront() and
// addToRear() are left as "To be completed as a Programming Project" stubs --
// they do nothing. We reproduce those stubs faithfully so the output matches
// the Java starter program. (addAfter() IS implemented in the Java source.)
//
// NOTE: members of the templated base (rear, list, modCount, size(),
// expandCapacity()) must be qualified with this-> in C++ -- the compiler does
// not look them up automatically in a dependent base class.
template <typename T>
class ArrayUnorderedList : public ArrayList<T>, public UnorderedListADT<T> {
public:
    // Creates an empty list using the default capacity.
    ArrayUnorderedList() : ArrayList<T>() {}

    // Creates an empty list using the specified capacity.
    ArrayUnorderedList(int initialCapacity) : ArrayList<T>(initialCapacity) {}

    // Java stub: "To be completed as a Programming Project" -- does nothing.
    void addToFront(T element) override {
        // To be completed as a Programming Project
        (void) element;
    }

    // Java stub: "To be completed as a Programming Project" -- does nothing.
    void addToRear(T element) override {
        // To be completed as a Programming Project
        (void) element;
    }

    // Adds the specified element after the specified target element.
    void addAfter(T element, T target) override {
        if (this->size() == (int) this->list.size())
            this->expandCapacity();

        int scan = 0;

        // find the insertion point
        while (scan < this->rear && !(target == this->list[scan]))  // Java: !target.equals(...)
            scan++;

        if (scan == this->rear)
            throw ElementNotFoundException("UnorderedList");

        scan++;

        // shift elements up one
        for (int shift = this->rear; shift > scan; shift--)
            this->list[shift] = this->list[shift - 1];

        // insert element
        this->list[scan] = element;
        this->rear++;
        this->modCount++;
    }
};

#endif
