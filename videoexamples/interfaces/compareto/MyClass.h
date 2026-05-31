#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>

// In Java this class is "implements Comparable<MyClass>", which requires an
// "int compareTo(MyClass o)" method. C++ has no built-in Comparable interface,
// so we simply provide a compareTo method that follows the same convention.
//
// The idiomatic C++ approach would be to overload operator< (so std::sort and
// friends work directly), but we keep compareTo here to match the Java lesson.
class MyClass {
public:
    int num;
    std::string name;

    MyClass(int num, std::string name);

    std::string toString() const;

    // Convention when comparing "this" to "o" (a.compareTo(b)):
    //   return 0 if a == b
    //   return a negative if a < b
    //   return a positive if a > b
    int compareTo(const MyClass& o) const;
};

#endif
