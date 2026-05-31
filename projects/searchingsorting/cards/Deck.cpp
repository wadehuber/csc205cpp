#include "Deck.h"

#include <random>

Deck::Deck(int n) {
    // Java: rand = new Random();  -> seed a Mersenne Twister nondeterministically.
    std::random_device rd;
    rand.seed(rd());

    // Java reserved capacity n; std::vector grows automatically, so we just add.
    for (int suite = 1; suite <= 4; suite++)
        for (int rank = 1; rank <= 13; rank++) {
            if ((suite - 1) * 13 + rank <= n) {
                cards.push_back(PlayingCard(rank, suite));
            }
        }
}

PlayingCard Deck::dealOne() {
    // Java: cards.get(rand.nextInt(52)); -> a random index in [0, 52).
    std::uniform_int_distribution<int> dist(0, 51);
    return cards.at(dist(rand));
}

void Deck::shuffle() {
    // To be completed as part of Programming Project
    //
    // Note: this is a Project-7 stub, exactly like the Java starter code.
    // Because it does nothing, the deck order does NOT change after shuffle(),
    // and the output is the same run-to-run (no randomness happens here yet).
}

std::string Deck::toString() const {
    std::string ret = "";
    for (const PlayingCard& card : cards) {
        ret += card.toString() + " ";
    }
    return ret;
}
