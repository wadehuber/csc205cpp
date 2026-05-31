#ifndef PLACESIVEBEEN_H
#define PLACESIVEBEEN_H

#include <string>
#include <vector>

class PlacesIveBeen {
private:
    // std::vector<std::string> is C++'s version of Java's List<String>.
    std::vector<std::string> places;

public:
    void addPlace(std::string place);
    int howManyPlacesHaveIBeen() const;
    std::string toString() const;
};

#endif
