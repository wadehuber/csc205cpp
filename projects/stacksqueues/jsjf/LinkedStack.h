#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <string>

#include "StackADT.h"
#include "LinearNode.h"
#include "exceptions/EmptyCollectionException.h"

/**
 * Represents a linked implementation of a stack.
 *
 * Several methods here are left as a "Programming Project" in the Java
 * starter code -- they return placeholder values. We preserve that EXACTLY
 * so the assignment is unchanged.
 *
 * MEMORY NOTE: Java relied on garbage collection. In C++ we use raw pointers
 * (new / nullptr) to mirror Java, and add a DESTRUCTOR that walks the chain
 * and deletes every node so there are no leaks.
 *
 * @author Java Foundations
 * @version 4.0
 */
template <typename T>
class LinkedStack : public StackADT<T> {
private:
    int count;
    LinearNode<T>* top;

public:
    /** Creates an empty stack. */
    LinkedStack()
        : count(0), top(nullptr) {}

    /**
     * Destructor (no Java equivalent -- Java's GC freed the nodes).
     * Walks the chain deleting each node so there are no leaks.
     */
    ~LinkedStack() {
        LinearNode<T>* current = top;
        while (current != nullptr) {
            LinearNode<T>* next = current->getNext();
            delete current;
            current = next;
        }
    }

    /** Adds the specified element to the top of this stack. */
    void push(T element) override {
        LinearNode<T>* temp = new LinearNode<T>(element);

        temp->setNext(top);
        top = temp;
        count++;
    }

    /**
     * Removes the element at the top of this stack and returns a
     * reference to it. Throws an EmptyCollectionException if empty.
     */
    T pop() override {
        if (isEmpty())
            throw EmptyCollectionException("stack");

        T result = top->getElement();
        top = top->getNext();
        count--;

        return result;
    }

    /**
     * Returns a reference to the element at the top of this stack.
     * The element is not removed from the stack.
     */
    T peek() override {
        // To be completed as a Programming Project

        return T();  // temp  (Java returned null)
    }

    /** Returns true if this stack is empty and false otherwise. */
    bool isEmpty() override {
        // To be completed as a Programming Project

        return true;  // temp
    }

    /** Returns the number of elements in this stack. */
    int size() override {
        // To be completed as a Programming Project

        return 0;  // temp
    }

    /** Returns a string representation of this stack. */
    std::string toString() override {
        // To be completed as a Programming Project

        return "";  // temp
    }
};

#endif
