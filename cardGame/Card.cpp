#include "Card.h"

Card::Card() : _rank(Card::Rank::EMPTY_RANK), _suit(Card::Suit::EMPTY_SUIT) {}
Card::Card(Rank rank, Suit suit) : _rank(rank), _suit(suit) {}

std::string Card::getSuit() const {
    switch (this->_suit) {
        case Card::Suit::SPADES:
            return "Spades";
        case Card::Suit::CLUBS:
            return "Clubs";
        case Card::Suit::HEARTS:
            return "Hearts";
        case Card::Suit::DIAMONDS:
            return "Diamonds";
        default:
            return "Invalid Suit";
    }
}

std::string Card::getRank() const {
    switch (this->_rank) {
        case Card::Rank::ACE:
            return "Ace";
        case Card::Rank::JACK:
            return "Jack";
        case Card::Rank::QUEEN:
            return "Queen";
        case Card::Rank::KING:
            return "King";
        default:
            return std::to_string(this->_rank);
    }
}

void Card::setSuit(Suit suit) {
    this->_suit = suit;
}

void Card::setRank(Rank rank) {
    this->_rank = rank;
}

std::string Card::display() const {
    return getRank() + " of " + getSuit();
}