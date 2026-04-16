#ifndef HAND_OF_CARDS_H
#define HAND_OF_CARDS_H

#include "PlayingCard.h"

// Abstract base class (interface equivalent)
class HandOfCards {
public:
    virtual ~HandOfCards() = default;

    virtual void addCard(const PlayingCard& c) = 0;
    virtual void printHand() = 0;
};

#endif
