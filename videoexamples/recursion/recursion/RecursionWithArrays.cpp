// RecursionWithArrays.cpp
//
// Examples of using helper functions so we can recursively work with arrays
// without changing the array itself.
//
// Java passed "Integer[]"; here we use std::vector<int>.  The vectors are
// passed by const reference (const std::vector<int>&) so they are not copied,
// matching Java's pass-by-reference for arrays.
//
// Java had overloaded sumArray / foldBalanced (one public, one helper with an
// extra index parameter).  C++ overloads the same way.

#include <iostream>
#include <string>
#include <vector>

// Recursion with arrays - summing an array
int sumArray(const std::vector<int>& nums, int index) {
    if (index >= (int)nums.size()) {
        return 0;
    }
    else {
        return (nums[index] + sumArray(nums, index + 1));
    }
}
int sumArray(const std::vector<int>& nums) {
    return sumArray(nums, 0);
}

// Double-ended array recursion
bool foldBalanced(const std::vector<int>& nums, int sum, int start, int end) {
    if (end < start) {
        return true;
    }
    else if (start == end) {
        return (nums[start] == sum);
    }
    else {
        return ((nums[start] + nums[end] == sum) &&
                foldBalanced(nums, sum, start + 1, end - 1));
    }
}
bool foldBalanced(const std::vector<int>& nums) {
    int sum = 0;

    if (nums.size() == 1) {
        sum = nums[0];
    }
    else {
        sum = nums[0] + nums[nums.size() - 1];
    }
    return foldBalanced(nums, sum, 0, (int)nums.size() - 1);
}

std::string arrayToString(const std::vector<int>& arr) {
    std::string ret = "";
    for (int x : arr) {
        ret += std::to_string(x) + " ";
    }
    return ret;
}

int main() {
    std::vector<std::vector<int>> arrays = {{1, 3, 2},
                                            {1, 2, 3, 4, 5, 6},
                                            {1, 2, 3, 10, 20, 30},
                                            {5, 4, 3, 2, 1, 6, 5, 4, 3, 2, 1},
                                            {1, 2, 3, 4, 5, 4, 3, 2, 1}};

    std::cout << "sumArray:" << std::endl;
    for (const std::vector<int>& a : arrays) {
        std::cout << "  Sum of array [ " << arrayToString(a) << "] = " << sumArray(a) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "foldBalanced:" << std::endl;
    for (const std::vector<int>& a : arrays) {
        // Java printed the boolean as "true"/"false"; std::boolalpha does the same.
        std::cout << "  Is array [ " << arrayToString(a) << "] foldBalanced? "
                  << std::boolalpha << foldBalanced(a) << std::endl;
    }

    return 0;
}
