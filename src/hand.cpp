#include "hand.h"
#include "deck.h"
#include <algorithm>
#include <iostream>

Hand::Hand(int size) : handSize(size) {
    hand = new Card[handSize]; // Initialize hand with the specified size
}

Hand::~Hand() {
    delete[] hand; // Clean up memory
}

void Hand::sortHand() {
    std::sort(hand, hand + handSize, [](const Card& a, const Card& b) {
        return a.sort < b.sort;
    });
}

Card* Hand::drawHand(Deck& deck, int handSize) {
    for (int i = 0; i < handSize; i++) {
        int cardPick = rand() % deck.getTotalCards(); // Randomly pick a card from the deck
        hand[i] = deck.getDeck()[cardPick]; // Add the picked card to the hand

        // Create a new deck without the picked card
        Card* newDeck = new Card[deck.getTotalCards() - 1];
        for (int j = 0, k = 0; j < deck.getTotalCards(); j++) {
            if (j != cardPick) { // Skip the picked card
                newDeck[k++] = deck.getDeck()[j]; // Copy the remaining cards to the new deck
            }
        }
        deck.updateDeck(newDeck, deck.getTotalCards() - 1); // Update the deck to the new deck without the picked card
    }
    sortHand(); // Sort the hand after drawing cards
    return hand;
}

void Hand::show() const {
    for (int i = 0; i < handSize; i++) {
        std::cout << hand[i].rank << hand[i].suit << " ";
    }
    std::cout << std::endl;
}

int Hand::getScore() const {
    int score = 0;
    for (int i = 0; i < handSize; i++) {
        score += hand[i].points; // Sum the points of each card in the hand
    }
    return score;
}

int Hand::getHandSize() const {
    return handSize; // Return the size of the hand
}

bool Hand::isBusted() const {
    return getScore() > 21; // Check if the hand is busted
}