#ifndef PLAYING_CARD_H
#define PLAYING_CARD_H

#include <string>
#include <vector>
#include <iostream>

class PlayingCard {
private:
    int rank;
    int suit;

    static int findEntry(const std::string& value, const std::vector<std::string>& values);

    static std::vector<std::string> ranks;
    static std::vector<std::string> suits;

public:
    // Default constructor - creates a Joker
    PlayingCard();

    // Constructor with string rank and suit
    PlayingCard(const std::string& rank, const std::string& suit);

    // Constructor with int rank and suit
    PlayingCard(int rank, int suit);

    // Getters
    int getRank() const;
    int getSuit() const;
    int getValue() const;

    // Setters
    void setRank(int rank);
    void setRank(const std::string& rank);
    void setSuit(int suit);
    void setSuit(const std::string& suit);

    // String representation
    std::string toString() const;

    // Comparison operators for sorting
    bool operator<(const PlayingCard& other) const;
    bool operator>(const PlayingCard& other) const;
    bool operator==(const PlayingCard& other) const;
};

#endif
