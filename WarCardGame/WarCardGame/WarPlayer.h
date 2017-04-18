#ifndef WarPlayer_h
#define WarPlayer_h

#include "Deck.h"

class Card;

class WarPlayer
{
private:
	Deck drawPile;
	Deck playedCards;
	bool isActive;

public:
	WarPlayer();
	~WarPlayer();

	void AddCardToDeckBottom(const Card& card);
	bool CanPlayCard();
	void PlayCard();

	void SetActiveStatus(bool isActive);

	const Card& GetTopPlayedCard() const;
	bool IsActive() const;
};

#endif