#include "Deck.h"


Deck::Deck(std::list<Card> cards)
	: cards(cards)
{
}


Deck::~Deck()
{
}

bool Deck::CanDraw() const
{
	return cards.size() > 0;
}

bool Deck::Draw(Card& card)
{
	if (CanDraw())
	{
		card = cards.front();
		cards.pop_front();
		return true;
	}
	return false;
}