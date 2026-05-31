// EvenNumbers.h
// C++ version of EvenNumbers.java.
//
// Java's EvenNumbers implemented the Iterator<Integer> interface, which means
// it provided  hasNext()  and  next() . C++ has no Iterator interface, but we
// follow the course convention: provide BOTH styles.
//   1. Java-style:  hasNext() / next()  (used by the driver below)
//   2. C++-style:   begin() / end()     (so a range-based for loop works)
//
// This class is small and self-contained, so we keep it header-only.

#ifndef EVENNUMBERS_H
#define EVENNUMBERS_H

#include <limits>   // std::numeric_limits

class EvenNumbers {
private:
    int num;
    int max;

public:
    // Default: count up to the largest int (like Java's Integer.MAX_VALUE).
    EvenNumbers() : num(0), max(std::numeric_limits<int>::max()) {}

    EvenNumbers(int max) : num(0), max(max) {}

    // ----- Style 1: Java-style iterator -----
    bool hasNext() const {
        return num <= max;
    }

    int next() {
        int ret = 0;
        if (hasNext()) {
            ret = num;
            num = num + 2;
        }
        return ret;
    }

    // ----- Style 2: support C++ range-based for -----
    // for (int x : EvenNumbers(10)) { ... }
    // The iterator yields 0, 2, 4, ... up to max.
    class RangeIterator {
    private:
        int value;
        int max;
        bool atEnd;
    public:
        RangeIterator(int value, int max, bool atEnd)
            : value(value), max(max), atEnd(atEnd) {}

        bool operator!=(const RangeIterator& other) const {
            return atEnd != other.atEnd;
        }
        int operator*() const {
            return value;
        }
        RangeIterator& operator++() {
            value += 2;
            if (value > max) {
                atEnd = true;
            }
            return *this;
        }
    };

    RangeIterator begin() const {
        return RangeIterator(0, max, 0 > max);
    }
    RangeIterator end() const {
        return RangeIterator(0, max, true);
    }
};

#endif
