// lab02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

#define DECK_SIZE 52
#define MAX_NAME 30
#define NO_PLAYERS 2

/* Card structure definition  */
typedef struct Card {
	unsigned char face;  
	unsigned char suit;
	unsigned char color;
};

/* Deck structure definition (dynamic array of cards) */
typedef struct Deck {
	Card cards[DECK_SIZE];
};

/* Player structure definition */
typedef struct Player {
	string name;
	int points;
};

/* initialize array of faces */
const string faces[] = { "Deuce", "Three", "Four", "Five",
	"Six", "Seven", "Eight", "Nine", "Ten",
	"Jack", "Queen", "King", "Ace" };

/* initialize array of suits */
const string suits[] = { "Diamonds", "Clubs", "Hearts", "Spades" };

/* initialize array of colors */
const string colors[] = { "Red", "Black" };

void printCard(Card& card);
string getCard(Card& card);
void printDeck(Deck& deck);
void fillDeck(Deck* deck);
void shuffleDeck(Deck* deck);
void dealDeck(const Deck* deck, Player* players);
void playGame(Deck* deck, Player* players);

int main(int argc, char* argv[]) {
	srand(time(NULL));

	Deck deck;

	Player players[NO_PLAYERS];
	for(int i=0; i< NO_PLAYERS; i++){
		players[i].name = "Player " + to_string(i + 1);
		players[i].points = 0;
	};

	fillDeck(&deck);
	printDeck(deck);
	shuffleDeck(&deck);
	printDeck(deck);
	
	dealDeck(&deck, players);
	playGame(&deck, players);

}


/* print all players */
void printPlayers(Player* players) {
	for (int i = 0; i < NO_PLAYERS; i++) {
		cout<< "Player " << (i + 1) << " Name:" << players[i].name << " Points:" << players[i].points;
	}
	printf("\n");
}

string getCard(Card& card) {
	return faces[card.face] + " of " + suits[card.suit] + " - " + colors[card.color];
}

void printDeck(Deck& deck) {
	cout << "\n---Deck---\n";
	/* loop through deck->cards */
	for (int i = 0; i < DECK_SIZE; i++) {
		cout << getCard(deck.cards[i]) << "\n";
	}
	cout << "\n";
}

void printDeck(Deck* deck) {
	cout << "\n---Deck---\n";
	/* loop through deck->cards */
	for (int i = 0; i < DECK_SIZE; i++) {
		cout << faces[deck->cards[i].face] << " of " << suits[deck->cards[i].suit] << "\t";
	}
	cout << "\n";
}

void fillDeck(Deck* deck) {
	/* loop through deck->cards */
	for (int i = 0; i < DECK_SIZE; i++) {
		deck->cards[i].face = i % 13;
		deck->cards[i].suit = i % 4;
		deck->cards[i].color = i % 2;
	} 
}

/*
void fillDeck(Deck& deck) {
	for (int i = 0; i < DECK_SIZE; i++) {
		deck.cards[i].face = i % 13;
		deck.cards[i].suit = i / 13;
		deck.cards[i].color = i / 26;
	}
}
*/

void swap(Card& a, Card& b) {
	Card c = a;
	a = b;
	b = c;
}

void shuffleDeck(Deck* deck) {
	int j;     /* variable to hold random value between 0 - 51 */
	Card temp; /* define temporary structure for swapping Cards */

	/* loop through deck->cards randomly swapping Cards */
	for (int i = 0; i < DECK_SIZE; i++) {
		j = rand() % DECK_SIZE;
		//temp = deck->cards[i];
		//deck->cards[i] = deck->cards[j];
		//deck->cards[j] = temp;
		swap(deck->cards[i], deck->cards[j]);
	} 
}

/* deal cards */
void dealDeck(const Deck* deck, Player* players) {
	int remainingCards = DECK_SIZE % NO_PLAYERS;
	
	for (int i = 0; i < NO_PLAYERS; i++) {
		cout << players[i].name << "\t";
	}
	cout << "\n";

	/* loop through deck->cards */
	for (int i = 0; i < (DECK_SIZE - remainingCards); i++) {
		cout << getCard(deck->cards[i]) << ((i + 1) % NO_PLAYERS ? '\t' : '\n');
	} 
	cout << "\n";

}

/* play game */
void playGame(Deck* deck, Player* players) {
	
	int i, j, c = 0; /* counters */

	int rounds = DECK_SIZE / NO_PLAYERS;

	int roundWinner;
	Card* currentCard;
	cout<<"Start of the game!\n";
	for (i = 0; i < rounds; i++) {
		roundWinner = 0;
		currentCard = &(deck->cards[c]);
		cout << "Round " << i << "\n";
		for (j = 0; j < NO_PLAYERS; j++) {
			cout << players[j].name << " plays " << getCard(deck->cards[c]) << "\n";
			if ((currentCard->face < deck->cards[c].face) ||
				(currentCard->face == deck->cards[c].face && currentCard->suit < deck->cards[c].suit))
				roundWinner = j;
			c++;
		}
		players[roundWinner].points++;
		cout << "Round Winner ["<< players[roundWinner].name<<"]\tTotal:["<< players[roundWinner].points<<"]\n\n";
	}

	int gameWinner = 0;
	int winnerPoints = players[0].points;
	for (i = 1; i < NO_PLAYERS; i++) {
		if (players[i].points > winnerPoints) {
			winnerPoints = players[i].points;
			gameWinner = i;
		}
	}

	cout << "!!!...and the winner is " << players[gameWinner].name  << " with " << players[gameWinner].points << " points!!!\n";
	cout << "End of the game!\n\n";
}