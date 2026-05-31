#ifndef DECK_H
#define DECK_H

#include <string>
#include <vector>
#include <random>

#include "PlayingCard.h"

class Deck {
public:
    Deck(int n);

    PlayingCard dealOne();
    void shuffle();

    std::string toString() const;

private:
    // Java used an ArrayList<PlayingCard>; the C++ equivalent is std::vector.
    std::vector<PlayingCard> cards;

    // Java used java.util.Random. In C++ we use the <random> library.
    // Seeded once (nondeterministically) like Java's `new Random()`.
    std::mt19937 rand;
};

#endif // DECK_H
