#ifndef CSC205_FASTSTACK_H
#define CSC205_FASTSTACK_H

#include <string>
#include <sstream>
#include "LinkedList.h"

/**
 * A stack (last-in, first-out) built on top of our LinkedList.
 *
 * This is the Java generic class FastStack<T>. Like LinkedList, a generic class
 * becomes a C++ TEMPLATE, so this is header-only (no .cpp).
 *
 * The Java field was a LinkedList<T> object (by value, garbage-collected). We
 * keep it the same way: a LinkedList<T> member, which is automatically
 * destroyed (freeing its nodes) when the FastStack is destroyed.
 */
template <typename T>
class FastStack {
private:
    LinkedList<T> elements;

public:
    FastStack() : elements() {}

    void push(T element) {
        elements.addToFront(element);
    }

    T pop() {
        return elements.removeFirst();
    }

    T peek() {
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
        ret << "top-> ";
        for (T ele : elements) {        // Java: for (T ele : elements)
            ret << ele << " ";
        }
        return ret.str();
    }
};

#endif
