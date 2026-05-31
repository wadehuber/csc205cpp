#ifndef FOURCOLORPEN_H
#define FOURCOLORPEN_H

#include <string>
#include <vector>

// C++ version of FourColorPen.java -- models a 4-color pen.
class FourColorPen {
private:
    // Java had a private static final String[] of color names. In C++ a
    // static data member is declared here and defined once in the .cpp file.
    static const std::vector<std::string> colors;

    int color;

    int getColorIndex(const std::string& c) const;

public:
    FourColorPen();

    void click(const std::string& c);
    void write(const std::string& msg) const;

    std::string toString() const;
};

#endif
