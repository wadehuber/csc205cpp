#ifndef SEARCHING_H
#define SEARCHING_H

#include <vector>

// Searching is not generic itself, but its search methods are generic
// (Java used "<T extends Comparable<T>>" generic methods). In C++ we write
// them as function templates inside a class with static members.
//
// "Not found" is represented by returning a POINTER (const T*) that is
// nullptr -- this is how we mirror Java returning null. When found, the
// pointer points at the matching element in the array.
//
// NOTE: Java compared elements with compareTo(); here we use the C++
// comparison operators ==, < and > (which int, std::string, etc. provide).
class Searching {
private:
    // C++17 "inline static" lets us define the static counter right here.
    inline static int counter = 0;

    static void resetCounter() {
        setCounter(0);
    }

public:
    static int getCounter() {
        return counter;
    }

    static void setCounter(int c) {
        counter = c;
    }

    template <typename T>
    static const T* linearSearch(const std::vector<T>& data, const T& target) {
        return linearSearch(data, 0, (int) data.size() - 1, target);
    }

    template <typename T>
    static const T* linearSearch(const std::vector<T>& data, int min, int max, const T& target) {
        const T* ret = nullptr;
        int current = min;

        resetCounter();

        while (current <= max) {
            counter++;
            if (data[current] == target) {
                ret = &data[current];
                break;
            }
            current++;
        }
        return ret;
    }

    template <typename T>
    static const T* binarySearch(const std::vector<T>& data, const T& target) {
        resetCounter();
        return binarySearch(data, 0, (int) data.size() - 1, target);
    }

    template <typename T>
    static const T* binarySearch(const std::vector<T>& data, int min, int max, const T& target) {
        if (min > max) {
            return nullptr;
        }

        int mid = min + ((max - min) / 2);
        counter++;
        if (data[mid] == target) {
            return &data[mid];
        } else if (data[mid] > target) {
            return binarySearch(data, min, mid - 1, target);
        } else {
            return binarySearch(data, mid + 1, max, target);
        }
    }

    // Stub for the lab to implement.
    template <typename T>
    static const T* interpolationSearch(const std::vector<T>& data, const T& target) {
        (void) data;
        (void) target;
        counter = 0;
        return nullptr;
    }
};

#endif
