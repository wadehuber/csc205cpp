#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::string name = "Kendra Sorenson";
    int age = 13;
    double number = 1234.5678;
    
    // Using concatenation with cout (like the first Java println)
    std::cout << name << " is " << age << " years old, number=" << number << std::endl;
    
    // Using printf (like C printf)
    printf("%s is %d years old, number=%.2f\n", name.c_str(), age, number);
    
    // Using C++ stream manipulators (alternative to Java's format)
    std::cout << std::setw(20) << name 
              << " is " << std::setw(10) << age 
              << " years old, number=" 
              << std::fixed << std::setprecision(2) << std::setw(10) << number 
              << std::endl;
    
    // For completeness, here's also the C++ printf-style formatting using cout
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "%20s is %10d years old, number=%10.2f\n", 
             name.c_str(), age, number);
    std::cout << buffer;
    
    return 0;
}
