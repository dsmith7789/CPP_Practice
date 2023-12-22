#include <vector>

#include "Hand.h"

Hand::Hand() : _cards{} {}
Hand::Hand(std::vector<Card> cards) {
    for (auto c : cards) {
        this->_cards.push_back(c);
    }
}

void Hand::addCard(Card card) {
    this->_cards.push_back(card);
}
        
Card Hand::removeCard(Card::Rank rank, Card::Suit suit) {
    Card removed;
    int removeIndex = 0;
    bool found = false;
    for (auto c : this->_cards) {
        if ( c.getSuit() == std::to_string(suit) && c.getRank() == std::to_string(rank) ) {
            removed.setSuit(suit);
            removed.setRank(rank);
            found = true;
            break;
        } else {
            removeIndex++;
        }
    }
    if (found) {
        this->_cards.erase(this->_cards.begin() + removeIndex);
    }
    return removed;
}
        
std::string Hand::display() const {
    std::string hand = "[";
    for (auto c : this->_cards) {
        hand += c.display();
        hand += ", ";
    }
    hand += "]";
    return hand;
}

int Hand::numCards() {
    return this->_cards.size();
}