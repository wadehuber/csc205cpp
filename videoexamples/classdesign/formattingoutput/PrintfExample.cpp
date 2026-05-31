// PrintfExample.cpp
// C++ version of PrintfExample.java
//
// Java's System.out.printf / System.out.format map almost 1-to-1 onto C's
// printf from <cstdio>, with the SAME format specifiers:
//   %s  a string        %d  an integer       %f  a double
//   %.2f rounds to 2 decimal places
//   %20s / %10d / %10.2f set a minimum field width (right-justified)
//
// One difference: printf's %s needs a C-style string, so we pass
// name.c_str() rather than the std::string itself. Also, C++ uses '\n' for a
// newline (Java does too here).

#include <cstdio>
#include <iostream>
#include <string>

int main() {
    std::string name = "Kendra Sorenson";
    int age = 13;
    double number = 1234.5678;

    // The plain concatenated line is easiest with cout in C++.
    std::cout << name << " is " << age << " years old, number=" << number
              << std::endl;

    // Same format string as Java; pass name.c_str() for %s.
    std::printf("%s is %d years old, number=%.2f\n", name.c_str(), age, number);

    std::printf("%20s is %10d years old, number=%10.2f\n", name.c_str(), age,
                number);

    return 0;
}
