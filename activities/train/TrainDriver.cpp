#include <iostream>
#include "Train.h"

int main() {
    // Instantiate new Train
    Train chooChoo;
    std::cout << chooChoo.toString() << std::endl;

    // Add additional cars to the train
    chooChoo.addCar("Passenger");
    std::cout << chooChoo.toString() << std::endl;
    chooChoo.addCar("Boxcar");
    std::cout << chooChoo.toString() << std::endl;
    chooChoo.addCar("Dining");
    std::cout << chooChoo.toString() << std::endl;

    std::cout << std::endl;
    std::cout << "The train has " << chooChoo.length() << " cars." << std::endl;

    return 0;
}
