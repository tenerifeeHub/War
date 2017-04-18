#ifndef Deck_h
#define Deck_h

#include<list>
#include "Card.h"

class Deck
{
private:
	std::list<Card> cards;

public:
	Deck(std::list<Card> cards);
	~Deck();

	bool CanDraw() const;
	bool Draw(Card& card);
};

#endif