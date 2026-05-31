#ifndef RECURSIONLAB_H
#define RECURSIONLAB_H

// Starter code: each method is a stub for you to implement recursively.
// (Java had these as "public static" methods; in C++ we keep them as
// static methods so the driver can call them as RecursionLab::func1(...).)
class RecursionLab {
public:
    // Recursive function
    static int func1(int n);

    static long func2(int n);

    // -1 + 2 + -3 + 4 + -5 + 6 ...
    static int func3(int n);

    // Tribonacci numbers
    static int tribonacci(int n);

    static int add(int x, int y);

    // Print the numbers from n down to 1
    static void printDownFrom(int n);

    // Print the numbers from 1 up to n
    static void printUpTo(int n);

    // GCD of 2 numbers
    static int gcd(int x, int y);

    // collatz(int n)
    static void collatz(int n);
};

#endif
