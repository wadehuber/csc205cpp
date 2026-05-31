// ToStringExample.cpp
// C++ version of ToStringExample.java.
// Creates an array of Movie objects then prints them out using toString.
#include <iostream>
#include <vector>

#include "Movie.h"

int main() {
    // Java used a Movie[] array; in C++ we use std::vector<Movie>.
    std::vector<Movie> top2022Movies = {
        Movie("Top Gun: Maverick", 691185348, 4751, "May 27"),
        Movie("Doctor Strange in the Multiverse of Madness", 411331607, 4534, "May 6"),
        Movie("Jurassic World Dominion", 374817385, 4697, "Jun 10"),
        Movie("The Batman", 369345583, 4417, "Mar 4"),
        Movie("Minions: The Rise of Gru", 354751145, 4427, "Jul 1"),
        Movie("Thor: Love and Thunder", 336514972, 4375, "Jul 8"),
        Movie("Spider-Man: No Way Home", 231808708, 4336, "Dec 17"),
        Movie("Sonic the Hedgehog 2", 190872904, 4258, "Apr 8"),
        Movie("Uncharted", 148649929, 4275, "Feb 18"),
        Movie("Elvis", 147347379, 3932, "Jun 24")};

    for (size_t ii = 0; ii < top2022Movies.size(); ii++) {
        // Java concatenated the Movie object, which called toString(). In C++
        // we call toString() explicitly.
        std::cout << "  " << ii << ": " << top2022Movies[ii].toString()
                  << " made $" << top2022Movies[ii].getGross() << std::endl;
    }

    return 0;
}
