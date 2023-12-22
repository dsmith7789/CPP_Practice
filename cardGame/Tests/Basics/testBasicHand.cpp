#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>

#include "testBasicHand.h"

void testBasicHand::run() {
    // make sure we can create an empty hand
    Hand emptyHand;
    std::cout << "Empty Hand: " << emptyHand.display() << std::endl;

    // make sure we can create a hand with cards in it
    std::vector<Card> cards{Card(Card::ACE, Card::CLUBS), Card(Card::FOUR, Card::DIAMONDS)};
    Hand fullHand(cards);
    std::cout << "Full Hand: " << fullHand.display() << std::endl;

    int emptyHandCards = emptyHand.numCards();
    int fullHandCards = fullHand.numCards();

    // make sure that adding cards to a hand shows in the display
    std::cout << "Before, empty Hand has " << emptyHand.numCards() << " cards." << std::endl;
    std::cout << "Before, full Hand has " << fullHand.numCards() << " cards." << std::endl;
    emptyHand.addCard(Card(Card::FIVE, Card::SPADES));
    fullHand.addCard(Card(Card::SEVEN, Card::HEARTS));
    std::cout << "After, empty Hand has " << emptyHand.numCards() << " cards." << std::endl;
    std::cout << "After, full Hand has " << fullHand.numCards() << " cards." << std::endl;

    std::cout << "After, empty SHOULD have " << (emptyHandCards + 1) << " cards" << std::endl;
    std::cout << "After, full SHOULD have " << (fullHandCards + 1) << " cards" << std::endl;

    int x = 5;
    assert(x == 5);

    std::cout << "Empty check: " << std::boolalpha << (emptyHand.numCards() == (emptyHandCards + 1)) << std::endl;
    std::cout << "Full check: " << std::boolalpha << (fullHand.numCards() == (fullHandCards + 1)) << std::endl;

    int modified_emptyHandCards = emptyHand.numCards();
    int modified_fullHandCards = fullHand.numCards();

    assert(modified_emptyHandCards == (emptyHandCards + 1));
    assert(modified_fullHandCards == (fullHandCards + 1));

    std::cout << "Got here 1?" << std::endl;

    emptyHandCards = emptyHand.numCards();
    fullHandCards = fullHand.numCards();

    // make sure that we can't remove a card from a hand that isn't in the hand
    emptyHand.removeCard(Card::KING, Card::SPADES);
    fullHand.removeCard(Card::KING, Card::SPADES);
    modified_emptyHandCards = emptyHand.numCards();
    modified_fullHandCards = fullHand.numCards();
    assert(modified_emptyHandCards == emptyHandCards);
    assert(modified_fullHandCards == fullHandCards);

    std::cout << "Got here 2?" << std::endl;

    emptyHandCards = emptyHand.numCards();
    fullHandCards = fullHand.numCards();

    // make sure that removing cards shows in the display correctly
    emptyHand.removeCard(Card::FIVE, Card::SPADES);
    std::cout << "Empty Hand: " << emptyHand.display() << std::endl;
    fullHand.removeCard(Card::ACE, Card::CLUBS);
    std::cout << "Full Hand: " << fullHand.display() << std::endl;
    modified_emptyHandCards = emptyHand.numCards();
    modified_fullHandCards = fullHand.numCards();
    assert(modified_emptyHandCards == emptyHandCards - 1);
    assert(modified_fullHandCards == fullHandCards - 1);

    std::cout << "ALL BASIC HAND TESTS PASSED" << std::endl;
}