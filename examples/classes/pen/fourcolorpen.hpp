#ifndef FOUR_COLOR_PEN_HPP
#define FOUR_COLOR_PEN_HPP

#include <string>
#include <array>

class FourColorPen {
private:
    static const std::array<std::string, 5> colors;
    int color;
    
    // Private helper method
    int getColorIndex(const std::string& c) const;

public:
    // Constructor
    FourColorPen();
    
    // Public methods
    void click(const std::string& c);
    void write(const std::string& msg) const;
    std::string toString() const;
};

#endif // FOUR_COLOR_PEN_HPP
