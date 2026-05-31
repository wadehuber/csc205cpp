// Card class
// Constructor creates a joker, deal() method sets a rank & suit.

#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <string>
#include <vector>

class PlayingCard {
public:
    // Java had `public final static String suits[]` / `ranks[]`.
    // In C++ these are static class members; the data is defined in the .cpp.
    static const std::vector<std::string> suits;
    static const std::vector<std::string> ranks;

    // Default constructor makes the card a Joker initially
    PlayingCard();

    // Construct from rank/suit names, e.g. ("3", "H")
    PlayingCard(const std::string& rank, const std::string& suit);

    // Construct from rank/suit numbers
    PlayingCard(int rank, int suit);

    // Getters & Setters
    int getRank() const;
    void setRank(int rank);
    void setRank(const std::string& rank);

    int getValue() const;

    int getSuit() const;
    void setSuit(int suit);
    void setSuit(const std::string& suit);

    // Allow card to be printed nicely
    std::string toString() const;

private:
    int rank;
    int suit;

    static int find_entry(const std::string& value, const std::vector<std::string>& values);
};

#endif // PLAYINGCARD_H
