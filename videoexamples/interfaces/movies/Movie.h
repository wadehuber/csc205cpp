#ifndef MOVIE_H
#define MOVIE_H

#include <string>

// In Java this class "implements Comparable<Movie>". C++ has no built-in
// Comparable interface, so we provide a compareTo method that follows the same
// convention (negative/zero/positive). The idiomatic C++ approach would be to
// overload operator<, but we keep compareTo to match the Java lesson.
class Movie {
private:
    std::string title;
    std::string director;
    int releaseDate;
    std::string rating;
    int rottenTomatoes;
    int imdb;

public:
    Movie(std::string title, std::string director, int releaseDate,
          std::string rating, int rottenTomatoes, int imdb);

    std::string getTitle() const;
    std::string getDirector() const;
    int getReleaseDate() const;
    std::string getMPAARating() const;
    int getRottenTomatoes() const;
    void setRottenTomatoes(int rottenTomatoes);
    int getImdb() const;
    void setImdb(int imdb);

    // Compare movies based on IMDB rating, break ties with RT.
    int compareTo(const Movie& o) const;

    std::string toString() const;
};

#endif
