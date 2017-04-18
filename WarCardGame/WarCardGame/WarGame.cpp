#include "WarGame.h"


WarGame::WarGame(std::vector<WarPlayer> players)
: players(players)
{
}


WarGame::~WarGame()
{
}

int WarGame::GetPlayersCount() const
{
	return players.size();
}

const WarPlayer& WarGame::GetPlayer(int index) const
{
	return players[index];
}