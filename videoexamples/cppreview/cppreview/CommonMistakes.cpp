// CommonMistakes.cpp
// C++ version of CommonMistakes.java
//
// Java review topic: common beginner mistakes. Most map directly to C++.
// Where a Java mistake behaves differently in C++, a comment explains it.

#include <iostream>
#include <string>

// Compares using == . NOTE the big difference from Java:
//   In Java, == on String objects compares REFERENCES (are they the same
//   object?). In C++, == on std::string compares the CONTENTS (the
//   characters). So in C++ this is effectively the same test as the
//   testEquals function below.
void testDoubleEqual(const std::string& s1, const std::string& s2) {
    if (s1 == s2) {
        std::cout << "    The strings are the same according to ==" << std::endl;
    }
    else {
        std::cout << "    The strings are NOT the same according to ==" << std::endl;
    }
}

// In Java this used s1.equals(s2). std::string has no .equals method; the
// idiomatic value comparison in C++ is simply == (shown above), so here we
// use == as well -- both functions now agree.
void testEquals(const std::string& s1, const std::string& s2) {
    if (s1 == s2) {
        std::cout << "    The strings are the same according to equals()" << std::endl;
    }
    else {
        std::cout << "    The strings are NOT the same according to equals()" << std::endl;
    }
}

int main() {
    int x;
    // Mistake 1: Not using arrays and loops when appropriate

    int num1 = 8;
    int num2 = 3;
    int num3 = 19;
    int num4 = 34;
    int num5 = 13;

    std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;
    std::cout << "num3 = " << num3 << std::endl;
    std::cout << "num4 = " << num4 << std::endl;
    std::cout << "num5 = " << num5 << std::endl;

    // = vs ==   (same trap in C++: = assigns, == compares)
    // (x = 3) evaluates to 3; (x == 3) is a bool. C++ prints bools as 1/0 by
    // default, whereas Java printed "true"/"false". We use std::boolalpha so
    // the output reads like Java.
    std::cout << "x = 3 : " << (x = 3) << std::endl;
    std::cout << std::boolalpha << "x == 3 : " << (x == 3) << std::noboolalpha << std::endl;

    // Working with values: integer vs floating-point division -- identical to Java.
    std::cout << "3 / 2 = " << (3 / 2) << std::endl;
    std::cout << "3 / 2.0 = " << (3 / 2.0) << std::endl;
    std::cout << "3.0 / 2 = " << (3.0 / 2) << std::endl;

    int total = 793;
    int count = 7;
    double avg = (double) total / count;   // cast before dividing, just like Java
    (void) avg;  // (declared but unused in the Java original too)

    // Comparing values
    // Java had: str1="...", str2 = new String("..."), str3="..."
    // In C++ there is no "new String" / interned-literal distinction; every
    // std::string holds its own copy of the characters, and == compares those
    // characters. So all three strings below compare EQUAL with == in C++,
    // whereas in Java str1==str2 was false (different objects).
    std::string str1 = "TestString";
    std::string str2 = std::string("TestString");
    std::string str3 = "TestString";

    std::cout << "Strings:" << std::endl;
    std::cout << "  str1=" << str1 << std::endl;
    std::cout << "  str2=" << str2 << std::endl;
    std::cout << "  str3=" << str3 << std::endl;

    std::cout << "Comparing str1 & str2 using ==:" << std::endl;
    testDoubleEqual(str1, str2);
    std::cout << "Comparing str1 2 str3 using ==:" << std::endl;
    testDoubleEqual(str2, str3);
    std::cout << "Comparing str1 & str3 using ==:" << std::endl;
    testDoubleEqual(str1, str3);

    std::cout << std::endl;
    std::cout << "Comparing str1 & str2 using equals():" << std::endl;
    testEquals(str1, str2);
    std::cout << "Comparing str1 2 str3 using equals():" << std::endl;
    testEquals(str2, str3);
    std::cout << "Comparing str1 & str3 using equals():" << std::endl;
    testEquals(str1, str3);

    return 0;
}
