#include "Deck.h"
#include <sstream>
#include <algorithm>

Deck::Deck(int n) {
    rand.seed(std::random_device{}());

    for (int suite = 1; suite <= 4; suite++) {
        for (int rank = 1; rank <= 13; rank++) {
            if ((suite - 1) * 13 + rank <= n) {
                cards.push_back(PlayingCard(rank, suite));
            }
        }
    }
}

PlayingCard Deck::dealOne() {
    std::uniform_int_distribution<> dis(0, cards.size() - 1);
    return cards[dis(rand)];
}

std::string Deck::toString() const {
    std::stringstream ss;
    for (const auto& card : cards) {
        ss << card.toString() << " ";
    }
    ss << "\n";
    return ss.str();
}

void Deck::shuffle() {
    std::shuffle(cards.begin(), cards.end(), rand);
}
