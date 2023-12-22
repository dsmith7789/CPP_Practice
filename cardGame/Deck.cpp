#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

#include "Deck.h"
#include "Card.h"

Deck::Deck() {
    for (int rank = Card::Rank::ACE; rank < Card::Rank::EMPTY_RANK; rank++) {
        for (int suit = Card::Suit::SPADES; suit < Card::Suit::EMPTY_SUIT; suit++) {
            Card c(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
            this->_cards.push_back(c);
        }
    }
}

std::string Deck::display() {
    std::string deck = "[";
    for (auto card : this->_cards) {
        deck += card.display();
        deck += ",";
    }
    deck += "]";
    return deck;
}

int Deck::numCards() {
    return this->_cards.size();
}

Card Deck::deal() {
    if (this->_cards.size() > 0) {
        Card c = (this->_cards).back();
        this->_cards.pop_back();
        return c;
    } else {
        std::cout << "Deck is empty." << std::endl;
        return Card();
    }
}

void Deck::shuffle() {
    std::random_device rand_device;
    std::mt19937 rand_gen(rand_device());
    std::shuffle(this->_cards.begin(), this->_cards.end(), rand_gen);
}

void Deck::addCard(Card card) {
    this->_cards.push_back(card);
    this->shuffle();
}