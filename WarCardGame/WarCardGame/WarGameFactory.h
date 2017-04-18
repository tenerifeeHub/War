#ifndef WarGameFactory_h
#define WarGameFactory_h

#include "PlayingCardsDeckFactory.h"

class WarGame;

class WarGameFactory
{
	PlayingCardsDeckFactory deckFactory;
public:
	WarGameFactory(const PlayingCardsDeckFactory& deckFactory);
	~WarGameFactory();

	WarGame CreateGame(int playersCount) const;
};

#endif