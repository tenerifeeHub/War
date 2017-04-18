#ifndef PlayingCardsDeckFactory_h
#define PlayingCardsDeckFactory_h

class Card;
class Deck;	

class PlayingCardsDeckFactory
{
private:
	int minNumber;
	int numberLimit;

public:
	PlayingCardsDeckFactory(int minNumber, int numberLimit);
	~PlayingCardsDeckFactory();

	Deck CreateDeck() const;
};

#endif