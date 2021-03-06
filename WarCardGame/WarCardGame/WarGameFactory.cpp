#include "WarGameFactory.h"

#include<vector>
#include<assert.h>
#include "WarGame.h"
#include "WarPlayer.h"

WarGameFactory::WarGameFactory(const PlayingCardsDeckFactory& deckFactory)
: deckFactory(deckFactory)
{
}


WarGameFactory::~WarGameFactory()
{
}

WarGame WarGameFactory::CreateGame(int playersCount) const
{
	assert(playersCount > 1);
	std::vector<WarPlayer> players(playersCount);

	auto deck = deckFactory.CreateDeck();
	deck.Shuffle();

	int playerIndex = 0;
	while (deck.CanDraw())
	{
		players[playerIndex].AddCardToDeckBottom(deck.Draw());
		playerIndex = (playerIndex + 1) % playersCount;
	}

	return WarGame(players);
}
