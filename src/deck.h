// filepath: /cardgame/cardgame/src/deck.h
#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <algorithm>
#include <cstdlib>

class Deck {
private:
    int numDecks;
    int totalCards;
    std::vector<Card> deck;

public:
    Deck(int numDecks = 1);
    ~Deck();

    void createDeck();
    void shuffle();
    Card drawCard();
    int getDeckSize() const;
    const std::vector<Card>& getDeck() const;
};

#endif // DECK_H