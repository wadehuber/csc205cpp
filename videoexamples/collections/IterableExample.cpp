// IterableExample.cpp
// C++ version of IterableExample.java.
//
// Demonstrates iterating two lists in parallel with Java-style iterators.
// Java's List<Integer> -> std::vector<int>.
//
// NOTE ON RANDOM NUMBERS:
// Java used java.util.Random. In C++ we use the <random> library, wrapped in a
// small helper below. Because both languages pick numbers randomly, the actual
// numbers this program prints will NOT match the Java program's numbers (and
// will differ from run to run). The PROGRAM STRUCTURE and logic are identical.
//
// NOTE ON std::vector ITERATORS:
// A std::vector already provides begin()/end() iterators. We use them here in
// the Java style: it != v.end()  is like  hasNext(), and  *it / ++it  is like
// next().

#include <iostream>
#include <vector>
#include <string>
#include <random>

// Java's  list.toString()  prints  [a, b, c]. std::vector does not, so here is
// a helper to print one that way.
std::string listToString(const std::vector<int>& v) {
    std::string out = "[";
    for (std::size_t i = 0; i < v.size(); i++) {
        out += std::to_string(v[i]);
        if (i + 1 < v.size()) {
            out += ", ";
        }
    }
    out += "]";
    return out;
}

int main() {
    std::vector<int> list1;
    std::vector<int> list2;
    std::vector<int> myCollection;   // stays empty, like the Java version

    // Set up the random number generator (Java's "Random rand = new Random()").
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000000);

    for (int ii = 0; ii < 40; ii++) {
        list1.push_back(dist(gen) % 100);
    }

    for (int jj = 0; jj < 30; jj++) {
        list2.push_back(dist(gen) % 100);
    }

    std::cout << "List1: " << listToString(list1) << std::endl;
    std::cout << "List2: " << listToString(list2) << std::endl;
    std::cout << std::endl;

    // Two iterators walked in parallel (Java's iter1.hasNext() && iter2...).
    auto iter1 = list1.begin();
    auto iter2 = list2.begin();

    int num1, num2;
    int counter = 0;
    while (iter1 != list1.end() && iter2 != list2.end()) {
        num1 = *iter1; ++iter1;
        num2 = *iter2; ++iter2;
        std::cout << "  " << num1 << " + " << num2 << " = " << (num1 + num2) << std::endl;
        counter++;
    }

    // myCollection is empty, so this sum stays 0 (same as Java).
    int sum = 0;
    for (int ii : myCollection) {
        sum += ii;
    }
    std::cout << sum << std::endl;

    // product starts at 0 and the collection is empty, so it stays 0 (same as
    // Java -- note multiplying into a 0 keeps it 0 anyway).
    int product = 0;
    for (auto vals = myCollection.begin(); vals != myCollection.end(); ++vals) {
        product *= *vals;
    }
    std::cout << product << std::endl;

    std::cout << "Added " << counter << " numbers" << std::endl;

    std::cout << "List1: " << listToString(list1) << std::endl;
    std::cout << "List2: " << listToString(list2) << std::endl;

    return 0;
}
