#include <cstdio>   // for printf, which works much like Java's printf

// NOTE: the function names below match the Java originals. (The "fib"
// functions actually compute a factorial-style product, not the classic
// Fibonacci sequence -- we keep the same names and behavior on purpose.)

int fibIterative(int n) {
    int ret = 1;
    for (int ii = 1; ii <= n; ii++) {
        ret *= ii;
    }
    return ret;
}

int fibRecursive(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return (n * fibRecursive(n - 1));
    }
}

// Recursive mathematical function
//  f(1) = 2
//  f(x) = 2 * f(x-1) - 1
int func1(int n) {
    // base case
    if (n <= 1) {
        return 2;
    } else {
        return (2 * func1(n - 1) - 1);
    }
}

// Recursive sum 1...n
int sumIt(int n) {
    if (n <= 1) {
        return n;   // Will be 1 if n == 1
    } else {
        return n + sumIt(n - 1);
    }
}

int main() {

    // Non recursive Fibonacci
    printf("Iterative Fibonacci\n");
    for (int ii = 1; ii <= 10; ii++) {
        printf("fibIterative(%2d) = %d\n", ii, fibIterative(ii));
    }
    printf("\n");

    printf("Recursive Fibonacci\n");
    for (int ii = 1; ii <= 10; ii++) {
        printf("fibRecursive(%2d) = %d\n", ii, fibRecursive(ii));
    }
    printf("\n");

    printf("Recursive Function of Unknown Origin\n");
    for (int ii = 1; ii <= 10; ii++) {
        printf("func1(%2d) = %d\n", ii, func1(ii));
    }
    printf("\n");

    printf("Recursive sum up to\n");
    for (int ii = 1; ii <= 10; ii++) {
        printf("sumIt(%2d) = %d\n", ii, sumIt(ii));
    }

    return 0;
}
