#include "PlayingCardsDeckFactory.h"

#include<list>
#include "Card.h"
#include "Deck.h"

PlayingCardsDeckFactory::PlayingCardsDeckFactory(int minNumber, int numberLimit)
: minNumber(minNumber)
, numberLimit(numberLimit)
{
}


PlayingCardsDeckFactory::~PlayingCardsDeckFactory()
{
}

Deck PlayingCardsDeckFactory::CreateDeck() const
{
	std::list<Card> cards;

	for (auto i = minNumber; i < numberLimit; ++i)
	{
		for (auto j = 0; j < Suit::Count; ++j)
		{
			cards.push_back(Card(i, (Suit)j));
		}
	}

	return Deck(cards);
}