#include <vector>
#include <string>
#include <iostream>

#include "Card.h"
#include "Hand.h"
#include "Deck.h"

using namespace std;

int main() {
    Deck deck;
    deck.shuffle();
    Hand myHand;
    for (int i = 0; i < 2; i++) {
        Card card = deck.deal();
        myHand.addCard(card);
    }
    cout << myHand.display() << endl;
}