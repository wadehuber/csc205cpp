#include <iostream>
#include "train.hpp"

int main() {
    Train chooChoo;
    std::cout << chooChoo.toString() << std::endl;

    chooChoo.addCar("Passenger");
    std::cout << chooChoo.toString() << std::endl;

    chooChoo.addCar("Boxcar");
    std::cout << chooChoo.toString() << std::endl;

    chooChoo.addCar("Dining");
    std::cout << chooChoo.toString() << std::endl;

    std::cout << "\nThe train has " << chooChoo.length() << " cars." << std::endl;

    return 0;
}
