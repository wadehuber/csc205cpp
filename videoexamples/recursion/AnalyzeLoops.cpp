// AnalyzeLoops.cpp
//
// Demonstrates methods with a variety of asymptotic complexities and times
// how long each takes to run on a small array.
//
// Java version: class of static methods + main.  In C++ that becomes free
// functions + main.  Timing uses <chrono> instead of System.nanoTime().

#include <cstdio>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>

// All these take the array by const reference so it is not copied.
// (Java arrays are passed by reference; const& gives the same "no copy"
//  behaviour while promising we won't modify it.)

// O(1) - constant time
int constantTimeMethod(const std::vector<int>& nums) {
    (void)nums;  // unused, but kept to match the Java signature
    return 1;
}

// O(log n) - logarithmic time
int logTimeMethod(const std::vector<int>& nums) {
    int counter = 0;
    // Calculate the log (base 2) of the length of the array
    int value = (int)std::round(std::log(nums.size()) / std::log(2));
    for (int ii = 0; ii < value; ii++) {
        counter++;
    }
    return counter;
}

// O(n) - linear time
int linearTimeMethod(const std::vector<int>& nums) {
    int counter = 0;
    for (std::size_t ii = 0; ii < nums.size(); ii++) {
        counter++;
    }
    return counter;
}

// O(n^2) - quadratic time
int quadraticTimeMethod(const std::vector<int>& nums) {
    int counter = 0;
    for (std::size_t ii = 0; ii < nums.size(); ii++) {
        for (std::size_t jj = 0; jj < nums.size(); jj++) {
            counter++;
        }
    }
    return counter;
}

// O(n^3) - cubic time
int cubicTimeMethod(const std::vector<int>& nums) {
    int counter = 0;
    for (std::size_t ii = 0; ii < nums.size(); ii++) {
        for (std::size_t jj = 0; jj < nums.size(); jj++) {
            for (std::size_t kk = 0; kk < nums.size(); kk++) {
                counter++;
            }
        }
    }
    return counter;
}

// O(n log n)
int loopMethod1(const std::vector<int>& nums) {
    int counter = 0;
    for (std::size_t ii = 0; ii < nums.size(); ii++) {
        counter += logTimeMethod(nums);
    }
    return counter;
}

// O(n^2 log n)
int loopMethod2(const std::vector<int>& nums) {
    int counter = 0;
    for (std::size_t ii = 0; ii < nums.size(); ii++) {
        for (std::size_t jj = 0; jj < nums.size(); jj++) {
            counter += logTimeMethod(nums);
        }
    }
    return counter;
}

// O(3n) = O(n) - linear time
int forLoopMethod(const std::vector<int>& nums) {
    int counter = 0;
    for (std::size_t ii = 0; ii < nums.size(); ii++) {
        counter++;
    }
    for (std::size_t jj = 0; jj < nums.size(); jj++) {
        counter++;
    }
    for (std::size_t kk = 0; kk < nums.size(); kk++) {
        counter++;
    }
    return counter;
}

int main() {
    std::vector<int> numbers(10);
    std::mt19937 rand(std::random_device{}());
    // nextInt(numbers.length) + 1  ->  1 .. numbers.size()
    std::uniform_int_distribution<int> dist(1, (int)numbers.size());

    std::cout << "Original array: ";
    for (std::size_t ii = 0; ii < numbers.size(); ii++) {
        numbers[ii] = dist(rand);
        std::cout << " " << numbers[ii];
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int result;
    std::chrono::high_resolution_clock::time_point start, end;
    auto nanos = [](std::chrono::high_resolution_clock::time_point s,
                    std::chrono::high_resolution_clock::time_point e) {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(e - s).count();
    };

    std::cout << "Results:" << std::endl;
    std::cout << "   Constant time: ";
    start = std::chrono::high_resolution_clock::now();
    result = constantTimeMethod(numbers);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "iterations=" << result << " (time:" << nanos(start, end) << ")" << std::endl;

    std::cout << "        Log time: ";
    start = std::chrono::high_resolution_clock::now();
    result = logTimeMethod(numbers);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "iterations=" << result << " (time:" << nanos(start, end) << ")" << std::endl;

    std::cout << "     Linear time: ";
    start = std::chrono::high_resolution_clock::now();
    result = linearTimeMethod(numbers);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "iterations=" << result << " (time:" << nanos(start, end) << ")" << std::endl;

    std::cout << "  Quadratic time: ";
    start = std::chrono::high_resolution_clock::now();
    result = quadraticTimeMethod(numbers);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "iterations=" << result << " (time:" << nanos(start, end) << ")" << std::endl;

    std::cout << "      Cubic time: ";
    start = std::chrono::high_resolution_clock::now();
    result = cubicTimeMethod(numbers);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "iterations=" << result << " (time:" << nanos(start, end) << ")" << std::endl;

    std::cout << "   Loop method 1: ";
    start = std::chrono::high_resolution_clock::now();
    result = loopMethod1(numbers);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "iterations=" << result << " (time:" << nanos(start, end) << ")" << std::endl;

    std::cout << "   Loop method 2: ";
    start = std::chrono::high_resolution_clock::now();
    result = loopMethod2(numbers);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "iterations=" << result << " (time:" << nanos(start, end) << ")" << std::endl;

    std::cout << "For Loop method: ";
    start = std::chrono::high_resolution_clock::now();
    result = forLoopMethod(numbers);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "iterations=" << result << " (time:" << nanos(start, end) << ")" << std::endl;

    return 0;
}
