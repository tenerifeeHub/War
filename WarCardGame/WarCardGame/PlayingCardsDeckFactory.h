#ifndef PlayingCardsDeckFactory_h
#define PlayingCardsDeckFactory_h

#include<list>

class Card;

class PlayingCardsDeckFactory
{
private:
	int minNumber;
	int numberLimit;

public:
	PlayingCardsDeckFactory(int minNumber, int numberLimit);
	~PlayingCardsDeckFactory();

	std::list<Card> CreateDeck() const;
};

#endif