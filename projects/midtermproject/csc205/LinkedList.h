#ifndef CSC205_LINKEDLIST_H
#define CSC205_LINKEDLIST_H

#include <string>
#include <sstream>
#include <stdexcept>

/**
 * A singly linked list with head and tail references, written for CSC205.
 *
 * This is the Java generic class LinkedList<T>. In C++ a generic class becomes
 * a TEMPLATE, and templates are header-only (everything lives in this .h; there
 * is no .cpp).
 *
 * MEMORY NOTE: Java created nodes with "new" and let the garbage collector
 * reclaim them. C++ has no GC, so we mirror Java with RAW pointers
 * (new / nullptr) and add a DESTRUCTOR that walks the chain deleting every
 * node. removeFirst/removeLast also "delete" the node they unlink (Java only
 * cleared the references and let GC do the rest).
 *
 * Java's "NoSuchElementException" is mapped to C++ std::out_of_range with the
 * same message (a standard exception that carries a message via what()).
 */
template <typename T>
class LinkedList {
private:
    // Java had a private inner class ListNode<E>. In C++ we make it a private
    // nested struct.
    struct ListNode {
        T element;
        ListNode* next;

        ListNode(T element, ListNode* next)
            : element(element), next(next) {}
    };

    ListNode* head;
    ListNode* tail;

protected:
    int size_;   // "size" is also a method name, so the field is "size_"

public:
    LinkedList()
        : head(nullptr), tail(nullptr), size_(0) {}

    /** Destructor: walk the chain and delete every node (Java used GC). */
    ~LinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }

    void addToFront(T elementToAdd) {
        // Create a new node that has the old head as its next
        ListNode* newNode = new ListNode(elementToAdd, head);

        // The head should now refer to the new node (the new head)
        head = newNode;

        // If the list was empty, this is the only node so it is also the tail!
        if (isEmpty()) {
            tail = newNode;
        }
        size_++;
    }

    void addToRear(T elementToAdd) {
        if (isEmpty()) {
            addToFront(elementToAdd);
        }
        else {
            // Create a new node with a null next
            ListNode* newNode = new ListNode(elementToAdd, nullptr);

            // The new node will follow the existing tail
            tail->next = newNode;

            // Set the tail to the new node
            tail = newNode;

            size_++;
        }
    }

    T removeFirst() {
        // Check if the list is empty
        if (isEmpty()) {
            throw std::out_of_range("Empty Linkedlist");
        }

        // Get the element from the head node
        T ret = head->element;

        // Set the head to the old head's next
        ListNode* oldHead = head;
        head = head->next;   // Set the new head

        // Clear the reference in the old head node, then free it.
        // (Java just nulled the fields and let GC reclaim the node; C++ must
        //  delete it to avoid a leak.)
        oldHead->next = nullptr;
        delete oldHead;

        size_--;

        if (isEmpty()) {
            tail = nullptr;   // The tail should be null if the list is empty
        }
        return ret;
    }

    T removeLast() {
        // Check if the list is empty
        if (isEmpty()) {
            throw std::out_of_range("Empty Linkedlist");
        }

        // Get the element from the tail node
        T ret = tail->element;

        if (size_ == 1) {
            ret = removeFirst();
        }
        else {
            // Traverse the list to find the next-to-last node which will
            //  become the new tail.  The next-to-last node will have
            //  next = tail
            ListNode* newTail = head;  // Start looking at the head
            while (newTail->next != tail) {
                newTail = newTail->next;
            }
            // At this point, newTail is referring to the next-to-last node

            // Clear the old tail (and free it -- Java let GC do that)
            ListNode* oldTail = tail;
            oldTail->next = nullptr;
            delete oldTail;

            // Set the tail to the new tail
            tail = newTail;
            tail->next = nullptr;  // This was pointing to the old tail
            size_--;
        }
        return ret;
    }

    bool contains(T value) {
        bool found = false;

        // Traverse the list, checking each node
        ListNode* current = head;
        while ((current != nullptr) && !(found)) {
            // Check if the current node holds the element
            found = (current->element == value);   // Java used .equals(value)
            current = current->next;
        }
        return found;
    }

    int indexOf(T value) {
        int ret = -1;
        int index = 0;

        // Traverse the list, checking each node
        ListNode* current = head;
        while (current != nullptr) {
            if (current->element == value) {   // Java used .equals(value)
                ret = index;
                break;
            }
            current = current->next;
            index++;
        }
        return ret;
    }

    bool isEmpty() {
        return (size_ == 0);
    }

    int size() {
        return size_;
    }

    T first() {
        // Check if the list is empty
        if (isEmpty()) {
            throw std::out_of_range("Empty LinkedList");
        }
        return head->element;
    }

    T last() {
        // Check if the list is empty
        if (isEmpty()) {
            throw std::out_of_range("Empty LinkedList");
        }
        return tail->element;
    }

    std::string toString() const {
        std::ostringstream ret;

        // Traverse the list
        ListNode* current = head;    // First element in the list
        while (current != nullptr) {
            ret << current->element << " ";   // Java: ret += current.element + " "
            current = current->next;   // Moves to the next node
        }
        return ret.str();
    }

    // ----- Iterator support -----
    // Java exposed iterator() returning an Iterator<T>, which let you write
    // "for (T ele : list)". The C++ equivalent is a range-based for loop, which
    // needs begin()/end() returning an iterator with operator*, operator++, and
    // operator!=. The traversal logic matches the Java LinkedListIterator.
    class iterator {
    private:
        ListNode* current;
    public:
        iterator(ListNode* current) : current(current) {}

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }

        T& operator*() const {
            return current->element;
        }

        iterator& operator++() {
            current = current->next;
            return *this;
        }
    };

    iterator begin() const {
        return iterator(head);
    }

    iterator end() const {
        return iterator(nullptr);
    }
};

#endif
