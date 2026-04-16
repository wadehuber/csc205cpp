#include "PlayingCard.h"
#include <algorithm>

// Initialize static members
std::vector<std::string> PlayingCard::ranks = {"Joker", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
std::vector<std::string> PlayingCard::suits = {"X", "H", "S", "D", "C"};

PlayingCard::PlayingCard() : rank(0), suit(0) {
}

PlayingCard::PlayingCard(const std::string& rankStr, const std::string& suitStr) {
    rank = findEntry(rankStr, ranks);
    suit = findEntry(suitStr, suits);
}

PlayingCard::PlayingCard(int r, int s) : rank(r), suit(s) {
}

int PlayingCard::findEntry(const std::string& value, const std::vector<std::string>& values) {
    int ret = 0;
    std::string upperValue = value;
    std::transform(upperValue.begin(), upperValue.end(), upperValue.begin(), ::toupper);

    for (int i = 0; i < values.size(); i++) {
        std::string upperVal = values[i];
        std::transform(upperVal.begin(), upperVal.end(), upperVal.begin(), ::toupper);
        if (upperValue == upperVal) {
            ret = i;
        }
    }
    return ret;
}

int PlayingCard::getRank() const {
    return rank;
}

void PlayingCard::setRank(int r) {
    rank = r;
}

void PlayingCard::setRank(const std::string& rankStr) {
    rank = findEntry(rankStr, ranks);
}

int PlayingCard::getValue() const {
    int ret = 0;
    if (rank == 1) {
        ret = 11;
    } else {
        ret = (rank < 10) ? rank : 10;
    }
    return ret;
}

int PlayingCard::getSuit() const {
    return suit;
}

void PlayingCard::setSuit(int s) {
    suit = s;
}

void PlayingCard::setSuit(const std::string& suitStr) {
    suit = findEntry(suitStr, suits);
}

std::string PlayingCard::toString() const {
    return ranks[rank] + suits[suit];
}

bool PlayingCard::operator<(const PlayingCard& other) const {
    return rank < other.rank;
}

bool PlayingCard::operator>(const PlayingCard& other) const {
    return rank > other.rank;
}

bool PlayingCard::operator==(const PlayingCard& other) const {
    return rank == other.rank && suit == other.suit;
}
