#ifndef TESTBASICHAND_H
#define TESTBASICHAND_H

#include <vector>
#include <string>
#include <iostream>

#include "../../Card.h"
#include "../../Hand.h"
#include "../../Deck.h"

class testBasicHand {
    public:
        Hand test_createEmptyHand();
        Hand test_createFullHand();
        bool test_addCards(Hand hand);
        bool test_nonExistentRemoval(Hand hand);
        bool test_validRemoval(Hand hand);
        void run();
};

#endif // TESTBASICHAND_H