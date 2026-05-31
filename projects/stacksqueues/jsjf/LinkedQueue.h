#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <string>

#include "QueueADT.h"
#include "LinearNode.h"
#include "exceptions/EmptyCollectionException.h"

/**
 * LinkedQueue represents a linked implementation of a queue.
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
class LinkedQueue : public QueueADT<T> {
private:
    int count;
    LinearNode<T>* head;
    LinearNode<T>* tail;

public:
    /** Creates an empty queue. */
    LinkedQueue()
        : count(0), head(nullptr), tail(nullptr) {}

    /**
     * Destructor (no Java equivalent -- Java's GC freed the nodes).
     * Walks the chain deleting each node so there are no leaks.
     */
    ~LinkedQueue() {
        LinearNode<T>* current = head;
        while (current != nullptr) {
            LinearNode<T>* next = current->getNext();
            delete current;
            current = next;
        }
    }

    /** Adds the specified element to the tail of this queue. */
    void enqueue(T element) override {
        LinearNode<T>* node = new LinearNode<T>(element);

        if (isEmpty())
            head = node;
        else
            tail->setNext(node);

        tail = node;
        count++;
    }

    /**
     * Removes the element at the head of this queue and returns a
     * reference to it. Throws an EmptyCollectionException if empty.
     */
    T dequeue() override {
        if (isEmpty())
            throw EmptyCollectionException("queue");

        T result = head->getElement();
        head = head->getNext();
        count--;

        if (isEmpty())
            tail = nullptr;

        return result;
    }

    /**
     * Returns a reference to the element at the head of this queue.
     * The element is not removed from the queue.
     */
    T first() override {
        // To be completed as a Programming Project

        return T();  // temp  (Java returned null)
    }

    /** Returns true if this queue is empty and false otherwise. */
    bool isEmpty() override {
        // To be completed as a Programming Project

        return true;  // temp
    }

    /** Returns the number of elements currently in this queue. */
    int size() override {
        // To be completed as a Programming Project

        return 0;  // temp
    }

    /** Returns a string representation of this queue. */
    std::string toString() override {
        // To be completed as a Programming Project

        return "";  // temp
    }
};

#endif
