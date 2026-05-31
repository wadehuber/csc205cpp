#include "FourColorPen.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

// Definition of the static color list (declared in the header).
const std::vector<std::string> FourColorPen::colors = {
    "NONE", "BLACK", "BLUE", "GREEN", "RED"};

// Small helper: returns an uppercase copy of a string.
// Java had String.toUpperCase(); C++ has no such method, so we uppercase
// each character with std::toupper.
static std::string toUpperCase(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char ch) { return std::toupper(ch); });
    return result;
}

FourColorPen::FourColorPen() {
    color = 0;
}

void FourColorPen::click(const std::string& c) {
    color = getColorIndex(c);
}

int FourColorPen::getColorIndex(const std::string& c) const {
    for (size_t ii = 0; ii < colors.size(); ii++) {
        if (toUpperCase(c) == colors[ii]) {
            return (int)ii;
        }
    }
    return 0;
}

void FourColorPen::write(const std::string& msg) const {
    if (color != getColorIndex("NONE")) {
        std::cout << "<" << colors[color] << ">" << msg << "<" << colors[color]
                  << ">" << std::endl;
    }
}

std::string FourColorPen::toString() const {
    return "FourColorPen [color=" + colors[color] + "]";
}
