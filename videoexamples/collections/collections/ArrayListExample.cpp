// ArrayListExample.cpp
// C++ version of ArrayListExample.java.
//
// Java's ArrayList / List  ->  C++ std::vector.
// A few method mappings used below:
//   list.add(x)        -> v.push_back(x)
//   list.get(i)        -> v[i]   (or v.at(i))
//   list.size()        -> v.size()
//   list.indexOf(x)    -> we write a small indexOf() helper
//   for-each / iterator -> C++ range-based for, or begin()/end() iterators
//
// std::vector does not print itself, so we write printList() helpers to get
// Java's  [a, b, c]  style.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Print a vector in Java's list style: [a, b, c]
template <typename T>
std::string listToString(const std::vector<T>& v) {
    std::string out = "[";
    for (std::size_t i = 0; i < v.size(); i++) {
        // Build each element's text via a stringstream so any T works.
        std::ostringstream piece;
        piece << v[i];
        out += piece.str();
        if (i + 1 < v.size()) {
            out += ", ";
        }
    }
    out += "]";
    return out;
}

// Java's List.indexOf(): returns the index of x, or -1 if not found.
template <typename T>
int indexOf(const std::vector<T>& v, const T& x) {
    for (std::size_t i = 0; i < v.size(); i++) {
        if (v[i] == x) {
            return (int) i;
        }
    }
    return -1;
}

int main() {
    std::vector<int> numbers;
    std::vector<std::string> names;
    std::vector<std::vector<int>> matrix;   // a "list of lists"

    for (int ii = 0; ii < 10; ii++) {
        numbers.push_back(ii);
    }
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(4);

    names.push_back("Billy");
    names.push_back("Suzy");
    names.push_back("Voltron");
    names.push_back("Oprah");

    // Add elements to the matrix.
    std::vector<int> row1;
    row1.push_back(1);
    row1.push_back(2);
    // Create a row from an initializer list (like Java's Arrays.asList(3,4)).
    std::vector<int> row2 = {3, 4};
    matrix.push_back(row1);
    matrix.push_back(row2);

    std::cout << "numbers: " << listToString(numbers) << std::endl;
    std::cout << "names: " << listToString(names) << std::endl;

    // For the matrix, print each row as a list too.
    std::string matrixStr = "[";
    for (std::size_t i = 0; i < matrix.size(); i++) {
        matrixStr += listToString(matrix[i]);
        if (i + 1 < matrix.size()) {
            matrixStr += ", ";
        }
    }
    matrixStr += "]";
    std::cout << "matrix: " << matrixStr << std::endl;
    std::cout << std::endl;

    // Accessing elements -- using an iterator (Java-style begin()/end()).
    std::cout << "numbers (iterator):  ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using a range-based for loop (Java's for-each).
    std::cout << "names (for-each):  ";
    for (const std::string& name : names) {
        std::cout << name << " ";
    }

    // Using get() -- in C++ that is just indexing.
    std::cout << std::endl;
    std::cout << "numbers:  first=" << numbers[0]
              << "  last=" << numbers[numbers.size() - 1] << std::endl;
    std::cout << "names: first = " << names[0] << "  3rd=" << names[2] << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "I have " << names.size() << " names and "
              << numbers.size() << " numbers and "
              << matrix.size() << " rows in the matrix" << std::endl;

    std::cout << std::endl;
    std::cout << "20 is stored in index " << indexOf(numbers, 20) << std::endl;
    std::cout << "Voltron is stored in index "
              << indexOf(names, std::string("Voltron")) << std::endl;

    return 0;
}
