#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <vector>
#include <string>
#include "ListADT.h"
#include "ElementToString.h"
#include "exceptions/ElementNotFoundException.h"
#include "exceptions/EmptyCollectionException.h"

// ArrayList represents an array implementation of a list. The front of the
// list is kept at array index 0. This class is abstract (it is extended to
// create a specific kind of list, e.g. ArrayUnorderedList).
//
// HEADER-ONLY TEMPLATE: like the Java generic class, the whole thing lives in
// this header so the compiler can instantiate it for any element type.
//
// We store the backing array as a std::vector<T> sized to the capacity, which
// mirrors Java's "T[] list" of length DEFAULT_CAPACITY (list.length == 100).
// Java's "null" slot becomes a default-constructed T().
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

    // Creates a new array with twice the capacity of the old one. Called by
    // descendant classes that add elements to the list.
    void expandCapacity() {
        list.resize(list.size() * 2);   // Java: Arrays.copyOf(list, list.length*2)
    }

    // Removes and returns the last element in this list.
    T removeLast() override {
        if (isEmpty())
            throw EmptyCollectionException("ArrayList");

        T result;
        rear--;
        result = list[rear];
        list[rear] = T();   // Java: list[rear] = null;
        modCount++;

        return result;
    }

    // Removes and returns the first element in this list.
    T removeFirst() override {
        if (isEmpty())
            throw EmptyCollectionException("ArrayList");

        T result = list[0];
        rear--;
        // shift the elements
        for (int scan = 0; scan < rear; scan++)
            list[scan] = list[scan + 1];

        list[rear] = T();   // Java: list[rear] = null;
        modCount++;

        return result;
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

    // Returns a reference to the element at the front of this list.
    T first() override {
        if (isEmpty())
            throw EmptyCollectionException("ArrayList");

        return list[0];
    }

    // Returns a reference to the element at the rear of this list.
    T last() override {
        if (isEmpty())
            throw EmptyCollectionException("ArrayList");

        return list[rear - 1];
    }

    // Returns true if this list contains the specified element.
    bool contains(T target) override {
        return (find(target) != NOT_FOUND);
    }

    // Returns true if this list is empty and false otherwise.
    bool isEmpty() override {
        return (rear == 0);
    }

    // Returns the number of elements currently in this list.
    int size() override {
        return rear;
    }

    // Returns a string representation of this list.
    std::string toString() override {
        std::string result = "";

        for (int scan = 0; scan < rear; scan++)
            result = result + elementToString(list[scan]) + " ";   // Java: + list[scan] +

        return result;
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
