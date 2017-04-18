#ifndef Card_h
#define Card_h

#include "Suit.h"

class Card
{
private:
	int number;
	Suit suit;

public:
	Card();
	Card(int number, Suit suit);
	~Card();

	int GetNumber() const;
	Suit GetSuit() const;
};

#endif