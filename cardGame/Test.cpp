#include <vector>
#include <string>
#include <iostream>

#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Tests/myTestLibrary.h"

using namespace std;

int main() {
    testBasicHand handTest;
    handTest.run();
    // Card c(Card::JACK, Card::SPADES);
    // vector<Card> cards = {Card(Card::ACE, Card::CLUBS), Card(Card::FOUR, Card::DIAMONDS)};
    // Hand h(cards);
    // cout << "Hand: " << h.display() << endl;

    // Deck d;
    // cout << "Deck: " << d.display() << endl;
    // cout << "Deck has " << d.numCards() << " cards" << endl;

    // d.shuffle();
    // cout << "Shuffled Deck: " << d.display() << endl;
    // cout << "Shuffled Deck has " << d.numCards() << " cards" << endl;

    // Card firstCard = d.deal();
    // Card secondCard = d.deal();
    // cout << "After dealing 2 cards, the deck has " << d.numCards() << " cards" << endl;

    // d.addCard(firstCard);
    // cout << "After adding the first card back, the deck has " << d.numCards() << " cards" << endl;

    // d.addCard(secondCard);
    // cout << "After adding the second card back, the deck has " << d.numCards() << " cards" << endl;  

    // cout << "Adding the cards should have shuffled the deck: " << d.display() << endl;
    return 0;
}