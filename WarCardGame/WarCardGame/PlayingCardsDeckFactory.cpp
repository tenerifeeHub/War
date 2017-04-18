#include "PlayingCardsDeckFactory.h"

#include "Card.h"

PlayingCardsDeckFactory::PlayingCardsDeckFactory(int minNumber, int numberLimit)
: minNumber(minNumber)
, numberLimit(numberLimit)
{
}


PlayingCardsDeckFactory::~PlayingCardsDeckFactory()
{
}

std::list<Card> PlayingCardsDeckFactory::CreateDeck() const
{
	std::list<Card> cards;

	for (auto i = minNumber; i < numberLimit; ++i)
	{
		for (auto j = 0; j < Suit::Count; ++j)
		{
			cards.push_back(Card(i, (Suit)j));
		}
	}

	return cards;
}