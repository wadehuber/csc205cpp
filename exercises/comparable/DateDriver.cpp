#include <iostream>
#include "Date.h"

int main() {
    Date day1("September", 3, 2011);
    Date day2(8, 17, 2013);
    Date day3(1, 1, 1999);

    // Java printed the Date objects directly (using their default toString).
    // In C++ we call toString() explicitly.
    std::cout << "Day 1: " << day1.toString() << std::endl;
    std::cout << "Day 2: " << day2.toString() << std::endl;
    std::cout << "Day 3: " << day3.toString() << std::endl;

    return 0;
}
