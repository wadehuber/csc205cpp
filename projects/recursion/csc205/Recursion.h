#ifndef RECURSION_H
#define RECURSION_H

#include <string>
#include <vector>

// Starter code: each method is a stub for you to implement recursively.
// (Java had these as "public static" methods; in C++ we keep them as
// static methods so the driver can call them as Recursion::fib(...),
// mirroring Java's Recursion.fib(...).)
class Recursion {
public:
    static int fib(int n);

    static int ackermann(int m, int n);

    static int balance(int x, int y);

    static double pi_approximation(int n);

    // Java: isPalindrome(String) -> here a std::string
    static bool isPalindrome(const std::string& s);

    // Java: monotonicallyIncreasing(Integer[]) -> here a std::vector<int>
    static bool monotonicallyIncreasing(const std::vector<int>& a);
};

#endif
