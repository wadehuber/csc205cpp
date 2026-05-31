#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <vector>
#include <string>
#include "ListADT.h"
#include "exceptions/ElementNotFoundException.h"
#include "exceptions/EmptyCollectionException.h"

// ArrayList represents an array implementation of a list. The front of the
// list is kept at array index 0. This class is abstract (it is extended to
// create a specific kind of list, e.g. ArrayUnorderedList).
//
// HEADER-ONLY TEMPLATE: like the Java generic class, the whole thing lives in
// this header so the compiler can instantiate it for any element type.
//
// IMPORTANT FIDELITY NOTE: in the Java source many methods of this class were
// left as "To be completed as a Programming Project" stubs -- e.g. size()
// returns 0, isEmpty() returns true, expandCapacity()/removeFirst()/etc. do
// nothing. The trees in this package rely on the *exact* stubbed behavior
// (addToRear uses 'rear' to position elements, and iteration uses 'rear', so
// it works even though size() always returns 0). We reproduce those stubs
// faithfully so the output matches the Java program.
//
// We store the backing array as a std::vector<T> sized to the capacity, which
// mirrors Java's "T[] list" of length DEFAULT_CAPACITY (list.length == 100).
template <typename T>
class ArrayList : public virtual ListADT<T> {   // virtual: shared base in the diamond
private:
    static const int DEFAULT_CAPACITY = 100;
    static const int NOT_FOUND = -1;

protected:
    int rear;
    std::vector<T> list;   // Java: T[] list; .size() here mirrors list.length
    int modCount;

private:
    // Returns the array index of target, or NOT_FOUND if absent.
    // (Private in the Java source.)
    int find(T target) {
        int scan = 0;
        int result = NOT_FOUND;

        if (!isEmpty()) {
            while (result == NOT_FOUND && scan < rear) {
                if (target == list[scan])   // Java: target.equals(list[scan])
                    result = scan;
                else
                    scan++;
            }
        }

        return result;
    }

public:
    // Creates an empty list using the default capacity.
    ArrayList() : ArrayList(DEFAULT_CAPACITY) {}

    // Creates an empty list using the specified capacity.
    ArrayList(int initialCapacity) {
        rear = 0;
        list.resize(initialCapacity);   // Java: new Object[initialCapacity]
        modCount = 0;
    }

    virtual ~ArrayList() = default;

    // Java stub: "To be completed as a Programming Project" -- does nothing.
    void expandCapacity() {
        // To be completed as a Programming Project
    }

    // Java stub: returns null (here a default-constructed T).
    T removeLast() override {
        // To be completed as a Programming Project
        return T();   // temp
    }

    // Java stub: returns null (here a default-constructed T).
    T removeFirst() override {
        // To be completed as a Programming Project
        return T();   // temp
    }

    // Removes and returns the specified element.
    T remove(T element) override {
        T result;
        int index = find(element);

        if (index == NOT_FOUND)
            throw ElementNotFoundException("ArrayList");

        result = list[index];
        rear--;

        // shift the appropriate elements
        for (int scan = index; scan < rear; scan++)
            list[scan] = list[scan + 1];

        list[rear] = T();   // Java: list[rear] = null;
        modCount++;

        return result;
    }

    // Java stub: returns null (here a default-constructed T).
    T first() override {
        // To be completed as a Programming Project
        return T();   // temp
    }

    // Java stub: returns null (here a default-constructed T).
    T last() override {
        // To be completed as a Programming Project
        return T();   // temp
    }

    // Returns true if this list contains the specified element.
    bool contains(T target) override {
        return (find(target) != NOT_FOUND);
    }

    // Java stub: always returns true.
    bool isEmpty() override {
        // To be completed as a Programming Project
        return true;   // temp
    }

    // Java stub: always returns 0.
    int size() override {
        // To be completed as a Programming Project
        return 0;   // temp
    }

    // Java stub: always returns "".
    std::string toString() override {
        // To be completed as a Programming Project
        return "";   // temp
    }

    // ----------------------------------------------------------------------
    // Range-based for support. Java exposed a java.util.Iterator via
    // iterator(); in C++ the idiomatic equivalent is begin()/end() so callers
    // can write  for (T element : tempList).  Iteration walks indices
    // [0, rear), matching the Java ArrayListIterator (current < rear).
    // ----------------------------------------------------------------------
    typename std::vector<T>::iterator begin() { return list.begin(); }
    typename std::vector<T>::iterator end()   { return list.begin() + rear; }
};

#endif
