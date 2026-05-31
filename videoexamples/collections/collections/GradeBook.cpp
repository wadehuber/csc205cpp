// GradeBook.cpp
// C++ version of GradeBook.java.
//
// A Map whose values are Lists:  name -> list of grades.
//   Java:  Map<String, List<Integer>>  (a HashMap)
//   C++ :  std::map<std::string, std::vector<int>>
//
// NOTE ABOUT ORDER:
// Java used a HashMap, whose order is unpredictable. Here we use std::map,
// which keeps the keys in SORTED order. That means this program prints names
// alphabetically (Clasy, Drew, Judy), while the Java HashMap printed them in
// its own hash order. The averages are the same either way. (If you wanted
// the same unordered behavior as Java, you would use std::unordered_map.)

#include <iostream>
#include <string>
#include <vector>
#include <map>

// Java's average(List<Integer>). Uses integer division, just like Java.
int average(const std::vector<int>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return sum / (int) grades.size();
}

// Helper to print a vector of grades Java-style: [45, 78, 52]
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
    std::map<std::string, std::vector<int>> grades;

    grades["Drew"]  = {45, 78, 52};
    grades["Judy"]  = {95, 98, 92};
    grades["Clasy"] = {60, 88, 74, 93};

    // Print the whole map Java-style: {name=[...], name=[...]}
    std::string mapStr = "{";
    bool first = true;
    for (const auto& entry : grades) {
        if (!first) {
            mapStr += ", ";
        }
        mapStr += entry.first + "=" + listToString(entry.second);
        first = false;
    }
    mapStr += "}";
    std::cout << mapStr << std::endl;

    std::cout << std::endl;
    std::cout << "Final Grades:" << std::endl;
    for (const auto& entry : grades) {
        std::cout << "  " << entry.first << ": " << average(entry.second) << std::endl;
    }

    return 0;
}
