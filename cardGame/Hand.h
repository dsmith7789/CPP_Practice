#ifndef HAND_H
#define HAND_H

#include <string>
#include <iostream>
#include <vector>

#include "Card.h"

class Hand {
    private:
        std::vector<Card> _cards;
    public:
        Hand();
        Hand(std::vector<Card> cards);
        void addCard(Card card);
        Card removeCard(Card::Rank rank, Card::Suit suit);
        int numCards();
        std::string display() const;
};

#endif // HAND_H