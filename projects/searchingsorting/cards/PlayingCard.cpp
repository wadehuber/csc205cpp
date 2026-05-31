#include "PlayingCard.h"

#include <algorithm>   // std::min, std::transform
#include <cctype>      // std::toupper

// Definitions of the static arrays declared in the header.
const std::vector<std::string> PlayingCard::suits = {"X", "H", "S", "D", "C"};
const std::vector<std::string> PlayingCard::ranks = {"Joker", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                                                     "10", "J", "Q", "K"};

// Default constructor makes the card a Joker initially
PlayingCard::PlayingCard() {
    rank = 0;
    suit = 0;
}

PlayingCard::PlayingCard(const std::string& rank, const std::string& suit) {
    this->rank = find_entry(rank, ranks);
    this->suit = find_entry(suit, suits);
}

PlayingCard::PlayingCard(int rank, int suit) {
    this->rank = rank;
    this->suit = suit;
}

// Helper: uppercase a copy of a string so comparisons are case-insensitive.
// (Java called value.toUpperCase().)
static std::string toUpper(const std::string& s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return out;
}

int PlayingCard::find_entry(const std::string& value, const std::vector<std::string>& values) {
    int ret = 0;
    // Note: the Java original compared strings with == (reference equality),
    // which is a bug there. In C++ we compare the string contents with ==,
    // so this version actually works as intended.
    for (int ii = 0; ii < (int)values.size(); ii++) {
        if (toUpper(value) == toUpper(values[ii]))
            ret = ii;
    }
    return ret;
}

// Getters & Setters
int PlayingCard::getRank() const {
    return rank;
}

void PlayingCard::setRank(int rank) {
    this->rank = rank;
}

void PlayingCard::setRank(const std::string& rank) {
    this->rank = find_entry(rank, ranks);
}

int PlayingCard::getValue() const {
    int ret = 0;
    if (rank == 1)
        ret = 11;
    else
        ret = std::min(rank, 10);
    return ret;
}

int PlayingCard::getSuit() const {
    return suit;
}

void PlayingCard::setSuit(int suit) {
    this->suit = suit;
}

void PlayingCard::setSuit(const std::string& suit) {
    this->suit = find_entry(suit, suits);
}

// Allow card to be printed nicely
std::string PlayingCard::toString() const {
    return (ranks[rank] + suits[suit]);
}
