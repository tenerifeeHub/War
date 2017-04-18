#ifndef WarPlayer_h
#define WarPlayer_h

#include "Deck.h"

class Card;

class WarPlayer
{
private:
	Deck drawPile;
	Deck playedCards;

public:
	WarPlayer();
	~WarPlayer();

	void AddCardToDeckBottom(const Card& card);
	void PlayCard();
};

#endif