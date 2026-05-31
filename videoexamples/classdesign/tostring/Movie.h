#ifndef MOVIE_H
#define MOVIE_H

#include <string>

// C++ version of Movie.java -- a simple example class used to demonstrate
// writing a toString method.
class Movie {
private:
    std::string title;
    long long gross;        // Java's "long"; C++ "long long" is guaranteed 64-bit
    std::string releaseDate;
    int theaters;

public:
    // Constructor
    Movie(std::string title, long long gross, int theaters,
          std::string releaseDate);

    // Accessors & mutators
    std::string getTitle() const;
    std::string getReleaseDate() const;

    long long getGross() const;
    void setGross(long long gross);

    int getTheaters() const;
    void setTheaters(int theaters);

    std::string toString() const;
};

#endif
