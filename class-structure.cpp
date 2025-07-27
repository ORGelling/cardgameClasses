// Trying to wrap all of this in classes now. WIP.

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

	Card drawCard() {
		if (deckSize == 0) throw std::runtime_error("Deck is empty!");
		int cardPick = rand() % deckSize; // Randomly pick a card from the deck
		Card pickedCard = deck[cardPick]; // Get the picked card

		Card* newDeck = new Card[deckSize - 1]; // Create a new deck without the picked card
		for (int j = 0, k = 0; j < deckSize; j++) {
			if (j != cardPick) { // Skip the picked card
				newDeck[k++] = (deck)[j]; // Copy the remaining cards to the new deck
			}
		}
		delete[] deck; // Clean up memory for the old deck
		deck = newDeck; // Update the deck to the new deck without the picked card
		deckSize--; // Decrease deck size after picking a card
		return pickedCard;
	}

	Deck(int numDecks = 1) : numDecks(numDecks), totalCards(52 * numDecks), deckSize(52 * numDecks) {
		deck = createDeck(numDecks);
	}

	~Deck() {
		delete[] deck; // Clean up memory
	}

	Card* getDeck() {
		return deck;
	}

	void setDeck(Card* newDeck) {
		deck = newDeck; // Set the deck to a new deck
	}

	void setDeckSize(int size) {
		deckSize = size; // Set the size of the deck
	}

	int getDeckSize() {
		return deckSize; // Return the size of the deck
	}

	int getTotalCards() {
		return totalCards;
	}

	void showDeck() const {
		for (int i = 0; i < deckSize; i++) {
			cout << deck[i].rank << deck[i].suit << " ";
		}
		cout << endl;
	}
	
	void showSize() const {
		cout << "Deck size: " << deckSize << endl; // Show the size of the deck
	}

};

/////////////////////////////////////////////////////////////////////////////////

class Hand {

private:

	Card* hand;
	int handSize;

public:

	int getHandSize() const {
		return handSize; // Return the size of the hand
	}

	void setHandSize(int size) {
		handSize = size; // Set the size of the hand
	}
	Card* getHand() const {
		return hand; // Return the hand
	}

	void sortHand() {
	//easy sort lmao
	sort(hand, hand + handSize, [](const Card& a, const Card& b) {
		return a.sort < b.sort;
		});
	}

	Hand(Deck& deck, int size) : handSize(size) {
		hand = new Card[handSize]; // Initialize hand with the specified size
		for (int i = 0; i < handSize; i++) {
			hand[i] = deck.drawCard(); // Draw a card from the deck
		}
		sortHand(); // Initialize hand with the specified size
	}

	~Hand() {
		delete[] hand; // Clean up memory
	}

	
	void show() const {
		for (int i = 0; i < handSize; i++) {
			cout << hand[i].rank << hand[i].suit << " ";
		}
		cout << endl;
	}

	void showSize() const {
		cout << "Hand size: " << handSize << endl; // Show the size of the deck
	}

	int getScore() const {
		int score = 0;
		for (int i = 0; i < handSize; i++) {
			score += hand[i].points; // Sum the points of each card in the hand
		}
		return score;
	}

	bool isBusted() const {
		return getScore() > 21; // Check if the hand is busted
	}

};

int main() {
	Deck deck(2); // Create a deck with 1 standard deck of cards
	//deck.showDeck();
	//int size = deck.getDeckSize(); // Get the size of the deck
	//cout << "Deck size: " << size << endl;
	//Card* currentDeck = deck.getDeck(); // Get the current deck of cards
	//for (int i = 0; i < size; i++) {
	//		cout << currentDeck[i].rank << currentDeck[i].suit << " ";
	//	}
	//	cout << endl;
	deck.showSize(); // Show the size of the deck
	Hand playerHand(deck, 12); // Draw a hand of 2 cards
	//playerHand.show(); // Show the player's hand
	playerHand.show(); // Sort the player's hand
	playerHand.showSize(); // Show the size of the player's hand
	//deck.showDeck(); // Show the remaining deck
	deck.showSize(); // Show the size of the deck
}