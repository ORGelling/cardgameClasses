#include "deck.h"
#include <algorithm>
#include <random>

Deck::Deck(int numDecks) : numDecks(numDecks), totalCards(52 * numDecks), deckSize(52 * numDecks) {
    deck = createDeck(numDecks);
}

Deck::~Deck() {
    delete[] deck; // Clean up memory
}

Card* Deck::createDeck(int numDecks) {
    const char* ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    const char* suits[] = { "C", "D", "H", "S" };
    int points[] = { 2,3,4,5,6,7,8,9,10,10,10,10,10 }; // Points for blackjack

    int totalCards = 52 * numDecks;
    Card* newDeck = new Card[totalCards];

    int index = 0; // Index to fill the new deck
    for (int d = 0; d < numDecks; ++d) {
        int sortindex = 0;
        for (int s = 0; s < 4; ++s) {
            for (int p = 0; p < 13; ++p) {
                newDeck[index].rank = ranks[p];
                newDeck[index].suit = suits[s];
                newDeck[index].points = points[p];
                newDeck[index].sort = sortindex; // Assign sort value
                ++index;
                ++sortindex;
            }
        }
    }
    return newDeck;
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck, deck + deckSize, g);
}

Card* Deck::getDeck() const {
    return deck;
}

int Deck::getTotalCards() const {
    return totalCards;
}

int Deck::getDeckSize() const {
    return deckSize;
}