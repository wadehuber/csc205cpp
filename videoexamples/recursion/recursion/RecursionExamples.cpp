// RecursionExamples.cpp
//
// Examples of simple recursive functions.  Keep in mind these are just
// examples - most of these specific problems can be solved more efficiently
// (though not always more clearly) without recursion.
//
// Java had overloaded methods (sum_up_tail(n) and sum_up_tail(n, x)).
// C++ supports overloading the same way, so the structure is identical.

#include <iostream>
#include <string>
#include <vector>

// Sum up to N
int sum_up(int n) {
    // Base case
    if (n <= 0) {
        return 0;
    }
    // Recursive case
    return n + sum_up(n - 1);
}

// Tail-recursive sum up to N
int sum_up_tail(int n, int x) {
    if (n < 1) {
        return x;
    }
    else {
        return sum_up_tail(n - 1, x + n);
    }
}
int sum_up_tail(int n) {
    return sum_up_tail(n, 0);
}

// Print up to N
void print_up_to(int n) {
    if (n > 1) {
        print_up_to(n - 1);
    }
    std::cout << std::to_string(n) + " ";
}

// Factorial
int fact(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * fact(n - 1);
    }
}

// Tail-recursive factorial
int fact_tail(int n, int f) {
    if (n <= 1) {
        return f;
    }
    else {
        return (fact_tail(n - 1, f * n));
    }
}
int fact_tail(int n) {
    return fact_tail(n, 1);
}

int main() {
    std::vector<int> testValues = {1, 5, 10, 20};

    std::cout << "Recursion examples" << std::endl;

    std::cout << "sum_up: ";
    for (int ii : testValues) {
        std::cout << "[" << ii << "]: " << sum_up(ii) << "   ";
    }
    std::cout << "\n" << std::endl;

    std::cout << "sum_up (tail-recursive): ";
    for (int ii : testValues) {
        std::cout << "[" << ii << "]: " << sum_up_tail(ii) << "   ";
    }
    std::cout << "\n" << std::endl;

    std::cout << "print_up_to: ";
    for (int ii : testValues) {
        std::cout << "[" << ii << "]: ";
        print_up_to(ii);
        std::cout << std::endl;
    }
    std::cout << "\n" << std::endl;

    std::cout << "fact: ";
    for (int ii : testValues) {
        std::cout << "[" << ii << "]: " << fact(ii) << "   ";
    }
    std::cout << "\n" << std::endl;

    std::cout << "fact (tail-recursive): ";
    for (int ii : testValues) {
        std::cout << "[" << ii << "]: " << fact_tail(ii) << "   ";
    }
    std::cout << "\n" << std::endl;

    return 0;
}
