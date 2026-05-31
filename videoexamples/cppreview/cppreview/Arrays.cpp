// Arrays.cpp
// C++ version of Arrays.java
//
// Java review topic: arrays.
// In Java an array knows its own length (arr.length). A C++ raw array does
// NOT store its length, so you must keep track of it yourself. The idiomatic
// modern C++ container is std::vector, which DOES know its size (.size()) and
// can grow -- it is the closest equivalent to Java's array/ArrayList.
//
// This file shows BOTH: a std::vector (recommended) and a raw array.

#include <iostream>
#include <vector>

int main() {
    // Java: Integer[] nums = new Integer[10];
    // C++ : a std::vector of 10 ints. Unlike a raw array, a vector knows its
    //       own size, just like a Java array knows its length.
    std::vector<int> nums(10);

    // Java: Integer[] moreNums = {10, 20, 30};
    // C++ : brace-initialize a vector. (A raw array would be: int moreNums[] = {10,20,30};)
    std::vector<int> moreNums = {10, 20, 30};

    std::cout << "Array Example" << std::endl;
    std::cout << std::endl;

    // add numbers to nums array
    // nums.size() is the C++ equivalent of Java's nums.length.
    for (int ii = 0; ii < (int) nums.size(); ii++) {
        nums[ii] = ii;
    }

    // Change the first element of the array (keep in mind the first index is 0)
    nums[0] = -10;

    // Change the 6th element of the array (index 5)
    nums[5] = 30;

    std::cout << "nums: " << std::endl;
    // print the nums array on one line separated by a space
    // When traversing, use .size() instead of a hard-coded value (like Java's .length).
    for (int ii = 0; ii < (int) nums.size(); ii++) {
        std::cout << nums[ii] << " ";   // << does not add a newline
    }
    std::cout << "\n" << std::endl;

    // print the moreNums array, one number per line
    std::cout << "moreNums:" << std::endl;
    for (int ii = 0; ii < (int) moreNums.size(); ii++) {
        std::cout << "  " << moreNums[ii] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
