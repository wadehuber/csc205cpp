#ifndef STACKQUEUEUTIL_H
#define STACKQUEUEUTIL_H

#include <string>

/**
 * Utility class with static stack/queue exercises.
 *
 * These methods are left as stubs in the Java starter code (the project asks
 * the student to implement them). We preserve the stubs EXACTLY so the
 * assignment is unchanged.
 *
 * Java's "public static" methods become C++ "static" member functions.
 */
class StackQueueUtil {
public:
    static bool isPalindrome(const std::string& s);

    static std::string reverseWords(const std::string& s);

    // In Java the arrays were "int arr1[]". In C++ an array parameter decays
    // to a pointer, so we receive them as "int arr1[]" (same as "int* arr1").
    static bool checkArrays(int min, int max, int arr1[], int arr2[]);
};

#endif
