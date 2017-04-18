#include "WarGameFactory.h"

#include<vector>
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
	std::vector<WarPlayer> players(playersCount);

	auto deck = deckFactory.CreateDeck();
	deck.Shuffle();

	int playerIndex = 0;
	Card card;
	while (deck.Draw(card))
	{
		players[playerIndex].AddCardToDeckBottom(card);
		playerIndex = (playerIndex + 1) % playersCount;
	}

	return WarGame(players);
}
