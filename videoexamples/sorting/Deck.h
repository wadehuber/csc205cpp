#ifndef DECK_H
#define DECK_H

#include <vector>
#include <random>
#include "PlayingCard.h"

class Deck {
private:
    std::vector<PlayingCard> cards;
    std::mt19937 rand;

public:
    // Constructor - creates a deck with n cards
    Deck(int n);

    // Deal one random card from the deck
    PlayingCard dealOne();

    // Get string representation of all cards
    std::string toString() const;

    // Shuffle the deck
    void shuffle();
};

#endif
