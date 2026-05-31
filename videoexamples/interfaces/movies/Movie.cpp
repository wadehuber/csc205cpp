#include "Movie.h"

Movie::Movie(std::string title, std::string director, int releaseDate,
             std::string rating, int rottenTomatoes, int imdb) {
    this->title = title;
    this->director = director;
    this->releaseDate = releaseDate;
    this->rating = rating;
    this->rottenTomatoes = rottenTomatoes;
    this->imdb = imdb;
}

std::string Movie::getTitle() const {
    return title;
}

std::string Movie::getDirector() const {
    return director;
}

int Movie::getReleaseDate() const {
    return releaseDate;
}

std::string Movie::getMPAARating() const {
    return rating;
}

int Movie::getRottenTomatoes() const {
    return rottenTomatoes;
}

void Movie::setRottenTomatoes(int rottenTomatoes) {
    this->rottenTomatoes = rottenTomatoes;
}

int Movie::getImdb() const {
    return imdb;
}

void Movie::setImdb(int imdb) {
    this->imdb = imdb;
}

int Movie::compareTo(const Movie& o) const {
    // Compare movies based on IMDB rating, break ties with RT
    int result = 0;

    if (this->imdb < o.getImdb()) {
        result = -1;
    }
    else if (this->imdb > o.getImdb()) {
        result = 1;
    }
    else {
        result = this->rottenTomatoes - o.getRottenTomatoes();
    }
    return result;
}

std::string Movie::toString() const {
    return title + " (" + std::to_string(releaseDate) + "), directed by " + director
           + " (rated " + rating + ")";
}
