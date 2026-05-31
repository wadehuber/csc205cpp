#include "Movie.h"

Movie::Movie(std::string title, long long gross, int theaters,
             std::string releaseDate) {
    this->title = title;
    this->gross = gross;
    this->releaseDate = releaseDate;
    this->theaters = theaters;
}

std::string Movie::getTitle() const {
    return title;
}

std::string Movie::getReleaseDate() const {
    return releaseDate;
}

long long Movie::getGross() const {
    return gross;
}

void Movie::setGross(long long gross) {
    this->gross = gross;
}

int Movie::getTheaters() const {
    return theaters;
}

void Movie::setTheaters(int theaters) {
    this->theaters = theaters;
}

std::string Movie::toString() const {
    return title;
}
