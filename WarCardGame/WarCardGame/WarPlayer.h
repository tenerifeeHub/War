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
	void AddCardsToDeckBottom(Deck& deck);

	bool CanPlayCard();
	void PlayCard();

	void SetActiveStatus(bool isActive);

	Deck& GetPlayedCards();
	const Card& GetTopPlayedCard() const;
	bool IsActive() const;

	int GetRemainingCardsInDeckCount() const;
	int GetPlayedCardsCount() const;
};

#endif