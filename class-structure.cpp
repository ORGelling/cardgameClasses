//Trying to wrap all of this in classes now. WIP.

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iterator>
#include <ctime>
using namespace std;

struct Card {
	string rank;
	string suit;
	int points; // Points for blackjack
	int sort;
};

class Deck {

private:

	int numDecks;
	int totalCards;
	int deckSize;
	Card* deck;

public:

	Card* createDeck(int numDecks = 1) {
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
	};

	Deck(int numDecks = 1) : numDecks(numDecks), totalCards(52 * numDecks), deckSize(52 * numDecks) {
		deck = createDeck(numDecks);
	}

	~Deck() {
		delete[] deck; // Clean up memory
	}

	Card* getDeck() {
		return deck;
	}

	int getTotalCards() const {
		return totalCards;
	}

};

/////////////////////////////////////////////////////////////////////////////////

class Hand {

private:

	Card* hand;
	int handSize;

public:

	Hand(int size) : handSize(size) {
		hand = drawHand(handSize); // Initialize hand with the specified size
	}

	~Hand() {
		delete[] hand; // Clean up memory
	}

	Card* drawHand(Card** currentDeck, int& deckSize, int handSize) {

		Card* hand = new Card[handSize]; // Initialize hand with the specified size

		for (int i = 0; i < handSize; i++) {
			int cardPick = rand() % deckSize; // Randomly pick a card from the deck
			hand[i] = (*currentDeck)[cardPick]; // Add the picked card to the hand

			Card* newDeck = new Card[deckSize - 1]; // Create a new deck without the picked card
			for (int j = 0, k = 0; j < deckSize; j++) {
				if (j != cardPick) { // Skip the picked card
					newDeck[k++] = (*currentDeck)[j]; // Copy the remaining cards to the new deck
				}
			}
			delete[] * currentDeck; // Clean up memory for the old deck
			*currentDeck = newDeck; // Update the deck to the new deck without the picked card
			deckSize--; // Decrease deck size after picking a card
		}
		sortHand(hand, handSize); // Sort the hand after drawing cards
		return hand;
	}

	void show() const {
		for (int i = 0; i < handSize; i++) {
			cout << hand[i].rank << hand[i].suit << " ";
		}
		cout << endl;
	}

	int getScore() const {
		int score = 0;
		for (int i = 0; i < handSize; i++) {
			score += hand[i].points; // Sum the points of each card in the hand
		}
		return score;
	}

	int getHandSize() const {
		return handSize; // Return the size of the hand
	}

	bool isBusted() const {
		return getScore() > 21; // Check if the hand is busted
	}

};