#include <iostream>
#include "deck.h"
#include "hand.h"

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    int numDecks = 1; // Number of decks to use
    Deck deck(numDecks); // Create a deck instance
    Hand playerHand(5); // Create a hand instance for the player with 5 cards

    // Display the player's hand
    std::cout << "Player's Hand: ";
    playerHand.show();

    // Display the score of the player's hand
    std::cout << "Player's Score: " << playerHand.getScore() << std::endl;

    // Check if the player is busted
    if (playerHand.isBusted()) {
        std::cout << "Player is busted!" << std::endl;
    } else {
        std::cout << "Player is safe." << std::endl;
    }

    return 0;
}