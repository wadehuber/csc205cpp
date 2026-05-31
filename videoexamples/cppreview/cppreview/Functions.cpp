// Functions.cpp
// C++ version of Functions.java
//
// Java review topic: functions/methods.
// In Java every method lives inside a class, and the ones here were "static"
// so they could be called without an object. In C++ we can write FREE
// functions that live directly in a file -- no class required.
//
// Parameter passing (a key Java vs C++ difference):
//   - C++ passes by VALUE by default (a copy is made).
//   - Use a reference (int&) to let a function modify the caller's variable.
//   - For containers like std::vector, pass by const reference (const ...&)
//     to avoid copying the whole vector.
// Java, by contrast, always passes primitives by value and objects by
// "reference value" (a copy of the reference) -- it has no true reference
// parameters like C++'s int&.

#include <iostream>
#include <vector>

// Print the numbers up to n. Returns nothing (void), takes n by value.
void print_numbers_up_to(int n) {
    for (int ii = 1; ii <= n; ii++) {
        std::cout << ii << " ";
    }
}

// Example of a function that returns a value.
// Java took an Integer[]; here we take a vector by const reference so we do
// not copy it, and the function cannot accidentally modify it.
int sumArray(const std::vector<int>& numbers) {
    int sum = 0;

    // numbers.size() is the equivalent of Java's numbers.length
    for (int ii = 0; ii < (int) numbers.size(); ii++) {
        sum = sum + numbers[ii];
    }

    return sum;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Print the numbers up to 10: ";
    print_numbers_up_to(10);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "The sum of the array nums is " << sumArray(nums) << std::endl;

    return 0;
}
