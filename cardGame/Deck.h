#ifndef DECK_H
#define DECK_H

#include <string>
#include <iostream>
#include <vector>

#include "Card.h"

class Deck {
    private:
        std::vector<Card> _cards;
    public:
        Deck();
        void shuffle();
        std::string display();
        int numCards();
        Card deal();
        void addCard(Card card);
};

#endif // DECK_H