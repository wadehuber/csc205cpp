#include <iostream>
#include <vector>

#include "Movie.h"

int main() {
    // Java uses an array of Movie objects; in C++ we use a std::vector.
    std::vector<Movie> movies = {
        Movie("The Hurt Locker", "Kathryn Bigelow", 2008, "R", 97, 75),
        Movie("In the Heights", "John M. Chu", 2021, "PG-13", 94, 74),
        Movie("Aliens", "James Cameron", 1986, "R", 97, 83),
        Movie("Shadow of a Doubt", "Alfred Hitchcock", 1943, "PG", 100, 78),
        Movie("Toy Story", "John Lasseter", 1995, "G", 100, 83),
        Movie("Twelve Monkeys", "Terry Gilliam", 1995, "R", 89, 80)
    };

    // Print the movies
    std::cout << "Movie choices:" << std::endl;
    for (std::size_t ii = 0; ii < movies.size(); ii++) {
        std::cout << "   " << movies[ii].toString() << std::endl;
    }

    // Find the best movie in the list
    Movie watch = movies[0];
    for (std::size_t jj = 1; jj < movies.size(); jj++) {
        if (movies[jj].compareTo(watch) > 0) {
            watch = movies[jj];
        }
    }

    std::cout << std::endl;
    std::cout << "The best of these is " << watch.getTitle() << std::endl;

    return 0;
}
