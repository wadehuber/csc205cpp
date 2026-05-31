// HashMapExample.cpp
// C++ version of HashMapExample.java.
//
// A Map stores key-value pairs:  "Tortilla Flat" -> 6
// Java's HashMap  ->  C++ std::unordered_map  (also unordered, hash-based).
//
// IMPORTANT NOTE ABOUT ORDER:
// Java's HashMap and C++'s std::unordered_map BOTH store entries in an
// unpredictable, hash-based order -- so neither prints in the order you
// inserted. The exact order is implementation-specific, so this C++ program's
// line order will NOT match the Java program's line order (the numbers are
// the same, just listed in a different sequence). If you want a predictable,
// sorted order, use std::map instead (see GradeBook.cpp for that choice).
//
// Method mappings:
//   map.put(k, v)  -> map[k] = v
//   map.get(k)     -> map[k]  (or map.at(k))
//   map.keySet()   -> just iterate the map; each entry is a (key, value) pair

#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> population;

    population["Tortilla Flat"] = 6;
    population["New York City"] = 8336817;
    population["Los Angeles"] = 3979576;
    population["Chicago"] = 2693976;
    population["Phoenix"] = 1680992;
    population["San Antonio"] = 1547253;

    std::cout << std::endl;
    std::cout << "Populations:" << std::endl;

    // Iterate the keys (and values). Each entry is a std::pair; .first is the
    // key, .second is the value.
    for (const auto& entry : population) {
        std::cout << "  The population of " << entry.first
                  << " is " << entry.second << std::endl;
    }

    // Update population.
    population["San Antonio"] = 1547254;
    population["Phoenix"] = population["Phoenix"] + 10;

    std::cout << "Populations after update:" << std::endl;
    for (const auto& entry : population) {
        std::cout << "  The population of " << entry.first
                  << " is " << entry.second << std::endl;
    }

    return 0;
}
