// Wrapper.cpp
// C++ version of Wrapper.java
//
// Java review topic: wrapper classes (Integer, Character, Double) and autoboxing.
//
// BIG DIFFERENCE: C++ has NO wrapper classes and NO autoboxing. An int is just
// an int; there is no separate "Integer" object type. You can put a primitive
// directly into a std::vector<int> -- no boxing required. So the Java idea of
// "primitive vs wrapper" simply does not exist in C++; this file keeps the same
// structure but shows the C++ equivalents:
//   - Integer.parseInt(s)      -> std::stoi(s)
//   - Double.parseDouble(s)    -> std::stod(s)
//   - Integer.toString(n)      -> std::to_string(n)
//   - Integer.MIN/MAX_VALUE    -> std::numeric_limits<int>::min()/max()
//   - Integer.min/max          -> std::min/std::max
//   - Integer.toBinary/Octal/HexString -> stream manipulators / a helper

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <bitset>
#include <sstream>

// Helper to produce a binary string with no leading zeros, like Java's
// Integer.toBinaryString (C++ has no built-in for this).
std::string toBinaryString(unsigned int n) {
    if (n == 0) return "0";
    std::string s = std::bitset<32>(n).to_string();
    return s.substr(s.find('1'));  // drop leading zeros
}

// Helper to format an int in a given base (octal=8, hex=16) without leading 0x.
std::string toBase(int n, int base) {
    std::ostringstream oss;
    if (base == 8) oss << std::oct << n;
    else if (base == 16) oss << std::hex << n;
    else oss << n;
    return oss.str();
}

// Java: addTen(Integer x). In C++ there is no Integer; just take an int.
int addTen(int x) {
    return x + 10;
}

int main() {
    // In Java, num1 was an int (primitive) and num2 was an Integer (wrapper
    // object). In C++ they are BOTH just int -- there is no wrapper version.
    int num1 = 10;
    int num2 = 20;

    char char1 = 'A';
    char char2 = 'B';

    double float1 = 3.14;
    double float2 = 12.34;

    std::string str1 = "42";
    std::string str2 = "6.022";

    // Java used ArrayList<Integer> (autoboxing each int into an Integer).
    // C++ stores plain ints directly in a std::vector<int> -- no boxing.
    std::vector<int> intArr;
    intArr.push_back(7);    // Java: intArr.add(7);
    intArr.push_back(10);

    std::cout << "Primitive Type\tWrapper Class" << std::endl;
    std::cout << "--------------\t-------------" << std::endl;
    std::cout << "num1=" << num1 << "\t\tnum2=" << num2 << std::endl;
    std::cout << "char1=" << char1 << "\t\tchar2=" << char2 << std::endl;
    std::cout << "float1=" << float1 << "\tfloat2=" << float2 << std::endl;

    std::cout << std::endl;
    // Integer.MIN_VALUE / MAX_VALUE -> std::numeric_limits<int>
    std::cout << "Integer range: " << std::numeric_limits<int>::min()
              << " - " << std::numeric_limits<int>::max() << std::endl;
    // Integer.parseInt -> std::stoi ; Double.parseDouble -> std::stod
    std::cout << "Integer.parseInt(str1) = " << std::stoi(str1) << std::endl;
    std::cout << "Double.parseDouble(str2) = " << std::stod(str2) << std::endl;
    std::cout << "Integer.min(10, 20) = " << std::min(10, 20) << std::endl;
    std::cout << "Integer.max(10, 20) = " << std::max(10, 20) << std::endl;

    std::cout << std::endl;
    std::cout << "num1=" << num1 << std::endl;
    std::cout << "\tnum1=" << toBinaryString(num1) << " (binary)" << std::endl;
    std::cout << "\tnum1=" << toBase(num1, 8) << " (octal)" << std::endl;
    std::cout << "\tnum1=" << toBase(num1, 16) << " (hexidecimal)" << std::endl;
    std::cout << "573845" << std::endl;
    std::cout << "\t573845=" << toBinaryString(573845) << " (binary)" << std::endl;
    std::cout << "\t573845=" << toBase(573845, 8) << " (octal)" << std::endl;
    std::cout << "\t573845=" << toBase(573845, 16) << " (hexidecimal)" << std::endl;

    std::cout << std::endl;
    // No autoboxing needed: every argument below is already a plain int.
    std::cout << "addTen(1)=" << addTen(1) << std::endl;
    std::cout << "addTen(num1)=" << addTen(num1) << std::endl;
    std::cout << "addTen(num2)=" << addTen(num2) << std::endl;

    return 0;
}
