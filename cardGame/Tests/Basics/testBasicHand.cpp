#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>

#include "testBasicHand.h"

Hand testBasicHand::test_createEmptyHand() {
    std::cout << "Testing creation of empty hand" << std::endl;
    Hand emptyHand;
    std::cout << "Success" << std::endl;
    return emptyHand;
}

Hand testBasicHand::test_createFullHand() {
    std::cout << "Testing creation of full hand" << std::endl;
    std::vector<Card> cards{Card(Card::ACE, Card::CLUBS), Card(Card::FOUR, Card::DIAMONDS)};
    Hand fullHand(cards);
    std::cout << "Success" << std::endl;
    return fullHand;
}

bool testBasicHand::test_addCards(Hand hand) {
    std::cout << "Testing adding cards" << std::endl;
    int prevCards = hand.numCards();
    hand.addCard(Card(Card::FIVE, Card::SPADES));
    std::cout << "Success" << std::endl;
    return (prevCards + 1) == hand.numCards();
}

bool testBasicHand::test_nonExistentRemoval(Hand hand) {
    std::cout << "Testing removal of non-existent cards" << std::endl;
    int prevCards = hand.numCards();
    hand.removeCard(Card::FIVE, Card::SPADES);
    std::cout << "Success" << std::endl;
    return prevCards == hand.numCards();  
}

bool testBasicHand::test_validRemoval(Hand hand) {
    std::cout << "Testing removal of a valid card" << std::endl;
    std::cout << "Previous Hand: " << hand.display() << std::endl;
    int prevCards = hand.numCards();
    hand.removeCard(Card::FIVE, Card::SPADES);
    std::cout << "After removal: " << hand.display() << std::endl;
    std::cout << "Success" << std::endl;
    return (prevCards - 1) == hand.numCards();
}

void testBasicHand::run() {
    std::cout << "BEGIN BASIC HAND TESTS" << std::endl;

    Hand emptyHand = test_createEmptyHand();
    Hand fullHand = test_createFullHand();
    assert(test_addCards(emptyHand));
    assert(test_addCards(fullHand));
    assert(test_nonExistentRemoval(emptyHand));
    assert(test_nonExistentRemoval(fullHand));
    assert(test_validRemoval(emptyHand));
    assert(test_validRemoval(fullHand));

    std::cout << "ALL BASIC HAND TESTS PASSED" << std::endl;
}