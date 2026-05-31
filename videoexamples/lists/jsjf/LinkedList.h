#ifndef JSJF_LINKEDLIST_H
#define JSJF_LINKEDLIST_H

#include <string>

#include "ListADT.h"
#include "LinearNode.h"
#include "exceptions/EmptyCollectionException.h"
#include "exceptions/ElementNotFoundException.h"

/**
 * LinkedList represents a linked implementation of a list.
 *
 * This is an ABSTRACT base (it implements ListADT but leaves add* operations
 * to the ordered/unordered subclasses). In the Java Foundations book most
 * methods here are left as a "Programming Project" -- they return placeholder
 * values. We preserve that EXACTLY so the lesson is unchanged; only remove()
 * and the iterator-related bits are fully implemented in the original.
 *
 * MEMORY NOTE: Java relied on garbage collection. In C++ we use raw pointers
 * (new / nullptr) to mirror Java, and add a DESTRUCTOR that walks the chain
 * and deletes every node so there are no leaks.
 *
 * @author Java Foundations
 * @version 4.0
 */
template <typename T>
class LinkedList : public virtual ListADT<T> {
protected:
    int count;
    LinearNode<T>* head;
    LinearNode<T>* tail;
    int modCount;

public:
    /** Creates an empty list. */
    LinkedList()
        : count(0), head(nullptr), tail(nullptr), modCount(0) {}

    /**
     * Destructor (no Java equivalent -- Java's GC freed the nodes).
     * Walks the chain deleting each node so there are no leaks.
     */
    virtual ~LinkedList() {
        LinearNode<T>* current = head;
        while (current != nullptr) {
            LinearNode<T>* next = current->getNext();
            delete current;
            current = next;
        }
    }

    /**
     * Removes the first element in this list and returns a reference to it.
     */
    T removeFirst() override {
        // To be completed as a Programming Project

        return T();  // temp
    }

    /**
     * Removes the last element in this list and returns a reference to it.
     */
    T removeLast() override {
        // To be completed as a Programming Project

        return T();  // temp
    }

    /**
     * Removes the first instance of the specified element from this list and
     * returns a reference to it. Throws an EmptyCollectionException if the list
     * is empty. Throws an ElementNotFoundException if the element is not found.
     */
    T remove(T targetElement) override {
        if (isEmpty())
            throw EmptyCollectionException("LinkedList");

        bool found = false;
        LinearNode<T>* previous = nullptr;
        LinearNode<T>* current = head;

        while (current != nullptr && !found)
            if (targetElement == current->getElement())
                found = true;
            else {
                previous = current;
                current = current->getNext();
            }

        if (!found)
            throw ElementNotFoundException("LinkedList");

        if (size() == 1)  // only one element in the list
            head = tail = nullptr;
        else if (current == head)  // target is at the head
            head = current->getNext();
        else if (current == tail) {  // target is at the tail
            tail = previous;
            tail->setNext(nullptr);
        }
        else  // target is in the middle
            previous->setNext(current->getNext());

        count--;
        modCount++;

        // Grab the element before freeing the node (Java's GC did this for us).
        T result = current->getElement();
        delete current;
        return result;
    }

    /** Returns the first element in this list without removing it. */
    T first() override {
        // To be completed as a Programming Project

        return T();  // temp
    }

    /** Returns the last element in this list without removing it. */
    T last() override {
        // To be completed as a Programming Project

        return T();  // temp
    }

    /** Returns true if the specified element is found in this list. */
    bool contains(T targetElement) override {
        // To be completed as a Programming Project
        (void)targetElement;

        return true;  // temp
    }

    /** Returns true if this list is empty and false otherwise. */
    bool isEmpty() override {
        // To be completed as a Programming Project

        return true;  // temp
    }

    /** Returns the number of elements in this list. */
    int size() override {
        // To be completed as a Programming Project

        return 0;  // temp
    }

    /** Returns a string representation of this list. */
    std::string toString() override {
        // To be completed as a Programming Project

        return "";  // temp
    }
};

#endif
