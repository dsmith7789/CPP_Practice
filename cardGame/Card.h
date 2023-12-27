#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card {
    public:
        enum Suit {SPADES, CLUBS, HEARTS, DIAMONDS, EMPTY_SUIT};
        enum Rank {
            ACE = 1,
            TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10,
            JACK = 11, QUEEN = 12, KING = 13, 
            EMPTY_RANK = 14
        };

        Card();
        Card(Rank rank, Suit suit);
        std::string getSuit() const;
        std::string getRank() const;
        void setSuit(Suit suit);
        void setRank(Rank rank);
        std::string display() const;
        bool sameSuit(Card card);
        bool sameRank(Card card);
    private:
        Suit _suit;
        Rank _rank;
};

#endif // CARD_H