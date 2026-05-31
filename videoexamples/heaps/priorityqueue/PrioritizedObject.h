#ifndef PRIORITIZEDOBJECT_H
#define PRIORITIZEDOBJECT_H

#include <string>
#include <sstream>

// PrioritizedObject represents a node in a priority queue containing a
// comparable object, arrival order, and a priority value.
//
// HEADER-ONLY TEMPLATE (mirrors the Java generic class).
//
// Java implemented Comparable<PrioritizedObject<T>> via compareTo(), which
// returns 1 or -1 (never 0). C++ uses operator<, defined from that same logic.
template <typename T>
class PrioritizedObject {
private:
    inline static int nextOrder = 0;   // C++17 inline static (Java: static int)
    int priority;
    int arrivalOrder;
    T element;

public:
    // Creates a new PrioritizedObject with the specified data.
    PrioritizedObject(T element, int priority) {
        this->element = element;
        this->priority = priority;
        arrivalOrder = nextOrder;
        nextOrder++;
    }

    // Default constructor for generic heap slots (Java used null).
    PrioritizedObject() : priority(0), arrivalOrder(0), element() {}

    // Returns the element in this node.
    T getElement() const { return element; }

    // Returns the priority value for this node.
    int getPriority() const { return priority; }

    // Returns the arrival order for this node.
    int getArrivalOrder() const { return arrivalOrder; }

    // Returns a string representation for this node.
    std::string toString() const {
        std::ostringstream out;
        out << element << "  " << priority << "  " << arrivalOrder;
        return out.str();
    }

    // Java compareTo(): higher priority wins; ties broken by arrival order
    // (first come, first served). Returns 1 or -1, never 0.
    int compareTo(const PrioritizedObject<T>& obj) const {
        int result;

        // Give preference to PrioritizedObject with higher priority
        if (priority > obj.getPriority())
            result = 1;
        else if (priority < obj.getPriority())
            result = -1;
        // If the priorities are equal, first come first served
        else if (arrivalOrder > obj.getArrivalOrder())
            result = 1;
        else
            result = -1;

        return result;
    }

    // operator< drives the heap ordering (a minheap on this comparison).
    bool operator<(const PrioritizedObject<T>& obj) const {
        return compareTo(obj) < 0;
    }

    bool operator==(const PrioritizedObject<T>& obj) const {
        return compareTo(obj) == 0;   // never true given the 1/-1 contract
    }
};

#endif
