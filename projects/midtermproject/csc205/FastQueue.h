#ifndef CSC205_FASTQUEUE_H
#define CSC205_FASTQUEUE_H

#include <string>
#include <sstream>
#include "LinkedList.h"

/**
 * A queue (first-in, first-out) built on top of our LinkedList.
 *
 * This is the Java generic class FastQueue<T>. Like LinkedList, a generic class
 * becomes a C++ TEMPLATE, so this is header-only (no .cpp).
 *
 * The Java field was a LinkedList<T> object (by value, garbage-collected). We
 * keep it the same way: a LinkedList<T> member, which is automatically
 * destroyed (freeing its nodes) when the FastQueue is destroyed.
 */
template <typename T>
class FastQueue {
private:
    LinkedList<T> elements;

public:
    FastQueue() : elements() {}

    void enqueue(T element) {
        elements.addToRear(element);
    }

    T dequeue() {
        return elements.removeFirst();
    }

    T first() {
        return elements.first();
    }

    bool isEmpty() {
        return elements.isEmpty();
    }

    int size() {
        return elements.size();
    }

    std::string toString() const {
        std::ostringstream ret;
        ret << "front-> ";
        for (T ele : elements) {        // Java: for (T ele : elements)
            ret << ele << " ";
        }
        ret << " <- rear";
        return ret.str();
    }
};

#endif
