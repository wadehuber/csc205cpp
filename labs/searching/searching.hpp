#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>
#include <vector>
#include <optional>

class Searching {
private:
    static inline int counter = 0;

    static void resetCounter() {
        counter = 0;
    }

public:
    static int getCounter() {
        return counter;
    }

    static void setCounter(int value) {
        counter = value;
    }

    template <typename T>
    static std::optional<T> linearSearch(const std::vector<T>& data, T target) {
        return linearSearch(data, 0, static_cast<int>(data.size()) - 1, target);
    }

    template <typename T>
    static std::optional<T> linearSearch(const std::vector<T>& data, int min, int max, T target) {
        resetCounter();
        for (int current = min; current <= max; ++current) {
            counter++;
            if (data[current] == target) {
                return data[current];
            }
        }
        return std::nullopt;
    }

    template <typename T>
    static std::optional<T> binarySearch(const std::vector<T>& data, T target) {
        resetCounter();
        return binarySearch(data, 0, static_cast<int>(data.size()) - 1, target);
    }

    template <typename T>
    static std::optional<T> binarySearch(const std::vector<T>& data, int min, int max, T target) {
        if (min > max) return std::nullopt;

        int mid = min + ((max - min) / 2);
        counter++;
        if (data[mid] == target) {
            return data[mid];
        } else if (data[mid] > target) {
            return binarySearch(data, min, mid - 1, target);
        } else {
            return binarySearch(data, mid + 1, max, target);
        }
    }

    template <typename T>
    static std::optional<T> interpolationSearch(const std::vector<T>& data, T target) {
        // TODO: Implement interpolation search
        counter = 0;
        return std::nullopt;
    }
};

#endif
