#ifndef Deck_h
#define Deck_h

#include<list>
#include "Card.h"

class Deck
{
private:
	std::list<Card> cards;

public:
	Deck();
	Deck(std::list<Card> cards);
	~Deck();

	void Shuffle();

	bool CanDraw() const;
	Card Draw();

	void AddToTop(const Card& card);
	void AddToBottom(const Card& card);

	const Card& GetTopCard() const;
};

#endif