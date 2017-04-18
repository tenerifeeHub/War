#include "Card.h"

Card::Card()
: number(-1)
, suit(Suit::Count)
{
}

Card::Card(int number, Suit suit)
: number(number)
, suit(suit)
{
}


Card::~Card()
{
}

int Card::GetNumber() const
{
	return number;
}

Suit Card::GetSuit() const
{
	return suit;
}