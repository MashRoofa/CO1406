#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

const string faces[] = { "Deuce", "Three", "Four", "Five",
	"Six", "Seven", "Eight", "Nine", "Ten",
	"Jack", "Queen", "King", "Ace" };

/* initialize array of suits */
const string suits[] = { "Diamonds", "Clubs", "Hearts", "Spades" };

/* initialize array of colors */
const string colors[] = { "Red", "Black" };

typedef struct Card {
	unsigned char face;
	unsigned char suit;
	unsigned char color;
};

string getCard(Card& card) {
	return faces[card.face] + " of " + suits[card.suit] + " - " + colors[card.color];
}

void printCard(Card& card) {
	cout << faces[card.face] + " of " + suits[card.suit] + " - " + colors[card.color] << endl;
}

int main()
{
	Card c1 = { 1,2,0 };
	Card c2 = { 7,1,1 };
	Card c3 = { 1,0,0 };
	Card c4 = { 12,3,1 };

	printCard(c1);
	printCard(c2);
	printCard(c3);
	printCard(c4);

}
