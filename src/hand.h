// filepath: /cardgame/cardgame/src/hand.h
#ifndef HAND_H
#define HAND_H

#include "card.h"
#include "deck.h"
#include <algorithm>
#include <iostream>

class Hand {
private:
    Card* hand;
    int handSize;

public:
    Hand(int size);
    ~Hand();

    void sortHand();
    void drawHand(Deck& deck);
    void show() const;
    int getScore() const;
    int getHandSize() const;
    bool isBusted() const;
};

#endif // HAND_H