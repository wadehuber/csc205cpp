#include "die.hpp"
#include <iostream>

int main() {
    const int ROLLS = 720;
    int count = 0;
    
    Die die1(6);
    Die die2(6);
    
    for (int roll = 1; roll <= ROLLS; roll++) {
        die1.roll();
        die2.roll();
        
        std::cout << die1.toString() << " " << die2.toString() << std::endl;
        
        if (die1.getFaceValue() == 1 && die2.getFaceValue() == 1) {
            count++;
        }
    }
    
    std::cout << "\nNumber of rolls: " << ROLLS << std::endl;
    std::cout << "Number of snake eyes: " << count << std::endl;
    std::cout << "Ratio: " << static_cast<float>(count) / ROLLS << std::endl;
    
    return 0;
}
