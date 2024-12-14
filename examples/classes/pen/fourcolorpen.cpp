#include "fourcolorpen.hpp"
#include <algorithm>
#include <iostream>

// Initialize static member
const std::array<std::string, 5> FourColorPen::colors = {"NONE", "BLACK", "BLUE", "GREEN", "RED"};

FourColorPen::FourColorPen() : color(0) {}

void FourColorPen::click(const std::string& c) {
    color = getColorIndex(c);
}

int FourColorPen::getColorIndex(const std::string& c) const {
    // Convert input to uppercase for comparison
    std::string upperC = c;
    std::transform(upperC.begin(), upperC.end(), upperC.begin(), ::toupper);
    
    // Find matching color
    for (size_t i = 0; i < colors.size(); i++) {
        if (upperC == colors[i]) {
            return static_cast<int>(i);
        }
    }
    return 0;
}

void FourColorPen::write(const std::string& msg) const {
    if (color != getColorIndex("NONE")) {
        std::cout << "<" << colors[color] << ">" << msg << "<" << colors[color] << ">" << std::endl;
    }
}

std::string FourColorPen::toString() const {
    return "FourColorPen [color=" + colors[color] + "]";
}
