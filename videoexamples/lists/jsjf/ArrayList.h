#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <string>
#include <sstream>
#include <vector>

#include "ListADT.h"
#include "exceptions/EmptyCollectionException.h"
#include "exceptions/ElementNotFoundException.h"

/**
 * ArrayList represents an array implementation of a list. The front of
 * the list is kept at array index 0. This class will be extended
 * to create a specific kind of list.
 *
 * IMPLEMENTATION NOTE: Java used a raw "T[] list" plus an int "rear" count and
 * an expandCapacity() that doubled the backing array. To keep this safe and
 * simple in C++ we back the list with a std::vector<T> whose SIZE plays the
 * role of Java's "list.length" (the capacity), while "rear" is still the number
 * of elements actually in use. The algorithms (shifting, expandCapacity,
 * find, etc.) are preserved exactly.
 *
 * @author Java Foundations
 * @version 4.0
 */
template <typename T>
class ArrayList : public virtual ListADT<T> {
private:
    static const int DEFAULT_CAPACITY = 100;
    static const int NOT_FOUND = -1;

protected:
    int rear;
    std::vector<T> list;   // list.size() mirrors Java's "list.length" (capacity)
    int modCount;

public:
    /** Creates an empty list using the default capacity. */
    ArrayList()
        : ArrayList(DEFAULT_CAPACITY) {}

    /** Creates an empty list using the specified capacity. */
    ArrayList(int initialCapacity)
        : rear(0), list(initialCapacity), modCount(0) {}

    virtual ~ArrayList() = default;

protected:
    /**
     * Creates a new array to store the contents of this list with
     * twice the capacity of the old one. Called by descendant classes
     * that add elements to the list.
     */
    void expandCapacity() {
        std::vector<T> newList(list.size() * 2);
        for (std::size_t ii = 0; ii < list.size(); ii++) {
            newList[ii] = list[ii];
        }
        list = newList;
    }

public:
    /** Removes and returns the last element in this list. */
    T removeLast() override {
        if (isEmpty()) {
            throw EmptyCollectionException("ArrayList");
        }

        rear--;
        T ret = list[rear];
        list[rear] = T();   // Java set the slot to null; T() is the C++ analogue
        modCount++;

        return ret;
    }

    /** Removes and returns the first element in this list. */
    T removeFirst() override {
        if (isEmpty()) {
            throw EmptyCollectionException("ArrayList");
        }

        T ret = list[0];

        // shift elements forward
        rear--;
        for (int scan = 0; scan < rear; scan++) {
            list[scan] = list[scan + 1];
        }
        list[rear] = T();

        modCount++;
        return ret;
    }

    /** Removes and returns the specified element. */
    T remove(T element) override {
        T result;
        int index = find(element);

        if (index == NOT_FOUND) {
            throw ElementNotFoundException("ArrayList");
        }

        result = list[index];
        rear--;

        // shift the appropriate elements
        for (int scan = index; scan < rear; scan++) {
            list[scan] = list[scan + 1];
        }

        list[rear] = T();

        modCount++;
        return result;
    }

    /** Returns a reference to the element at the front of this list. */
    T first() override {
        if (isEmpty()) {
            throw EmptyCollectionException("ArrayList");
        }

        return list[0];
    }

    /** Returns a reference to the element at the rear of this list. */
    T last() override {
        if (isEmpty()) {
            throw EmptyCollectionException("ArrayList");
        }

        return list[rear - 1];
    }

    /** Returns true if this list contains the specified element. */
    bool contains(T target) override {
        return (find(target) != NOT_FOUND);
    }

private:
    /**
     * Returns the array index of the specified element, or the
     * constant NOT_FOUND if it is not found.
     */
    int find(T target) {
        int scan = 0;
        int result = NOT_FOUND;

        if (!isEmpty()) {
            while (result == NOT_FOUND && scan < rear) {
                if (target == list[scan]) {   // Java used target.equals(list[scan])
                    result = scan;
                }
                else {
                    scan++;
                }
            }
        }

        return result;
    }

public:
    /** Returns true if this list is empty and false otherwise. */
    bool isEmpty() override {
        return (rear == 0);
    }

    /** Returns the number of elements currently in this list. */
    int size() override {
        return rear;
    }

    /** Returns a string representation of this list. */
    std::string toString() override {
        std::ostringstream ret;

        for (int ii = 0; ii < rear; ii++) {
            ret << list[ii] << " ";   // Java used "ret += list[ii] + \" \""
        }

        return ret.str();
    }
};

#endif
