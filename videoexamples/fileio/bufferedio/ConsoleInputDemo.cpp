// ConsoleInputDemo.cpp
//
// Java used a Scanner(System.in) to read from the keyboard.
// In C++ we read from std::cin: std::getline for a whole line,
// and ">>" for a single value such as an int.

#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your name: ";
    std::string name;
    std::getline(std::cin, name);   // like Scanner.nextLine()

    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;                // like Scanner.nextInt()

    // Java used printf with %s and %d; here we just stream the values.
    std::cout << "Hello " << name << ", you are " << age << " years old." << std::endl;

    return 0;
}
