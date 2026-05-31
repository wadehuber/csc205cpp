#include "PlacesIveBeen.h"
#include <sstream>

void PlacesIveBeen::addPlace(std::string place) {
    places.push_back(place);
}

int PlacesIveBeen::howManyPlacesHaveIBeen() const {
    return (int) places.size();
}

std::string PlacesIveBeen::toString() const {
    // Build a string like Java prints a List: [Flagstaff, Dallas, ...]
    std::ostringstream out;
    out << "PlacesIveBeen: [";
    for (std::size_t i = 0; i < places.size(); i++) {
        out << places[i];
        if (i + 1 < places.size()) {
            out << ", ";
        }
    }
    out << "]";
    return out.str();
}
