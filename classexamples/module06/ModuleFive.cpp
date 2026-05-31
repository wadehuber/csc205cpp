#include <iostream>
#include <vector>
#include <string>

#include "PlacesIveBeen.h"
#include "MyCollection.h"

int main() {

    // A std::vector is C++'s resizable array -- like Java's ArrayList.
    std::vector<int> numbers;

    // add things to the vector
    for (int ii = 0; ii < 5; ii++) {
        numbers.push_back((ii + 1) * 2);
    }

    // Print the elements like Java prints an ArrayList: [2, 4, 6, 8, 10]
    std::cout << "ArrayList numbers: [";
    for (std::size_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
        if (i + 1 < numbers.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    // Print some elements using a range-based for loop (Java's for-each).
    std::cout << "Multiples of 4: ";
    for (int x : numbers) {
        if (x % 4 == 0) {
            std::cout << x << " ";
        }
    }
    std::cout << std::endl << std::endl;

    PlacesIveBeen trips;
    trips.addPlace("Flagstaff");
    trips.addPlace("Dallas");
    trips.addPlace("Los Angeles");
    trips.addPlace("Nashville");
    trips.addPlace("Chicago");
    trips.addPlace("Toronto");
    trips.addPlace("Juarez");
    trips.addPlace("Moon");

    std::cout << trips.toString() << std::endl;
    std::cout << std::endl;

    // Our own generic collection holding ints.
    MyCollection<int> values;

    for (int ii = 1; ii < 5; ii++) {
        values.add(ii * 2);
    }
    values.addSecret(7);
    values.addSecret(42);
    values.addSecret(13);

    std::cout << "Numbers in my collection (toString): " << values.toString() << std::endl;

    // Style 1: Java-style iterator with hasNext()/next().
    std::cout << "Numbers in my collection (iterator): ";
    MyCollection<int>::Iterator iter = values.iterator();
    while (iter.hasNext()) {
        std::cout << " " << iter.next();
    }
    std::cout << std::endl;

    // Style 2: range-based for loop (Java's for-each).
    std::cout << "Numbers in my collection (for-each): ";
    for (int x : values) {
        std::cout << " " << x;
    }
    std::cout << std::endl;

    std::cout << "Collection size: " << values.size() << std::endl;

    return 0;
}
