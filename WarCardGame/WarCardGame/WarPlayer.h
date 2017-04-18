#ifndef WarPlayer_h
#define WarPlayer_h

#include "Deck.h"

class Card;

class WarPlayer
{
private:
	Deck cards;

public:
	WarPlayer();
	~WarPlayer();

	void AddCardToDeckBottom(const Card& card);
};

#endif