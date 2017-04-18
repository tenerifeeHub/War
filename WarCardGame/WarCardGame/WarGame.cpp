#include "WarGame.h"
#include<algorithm>

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

void PlayCard(WarPlayer& player)
{
	if (player.CanPlayCard())
	{
		player.PlayCard();
	}
}

bool BiggerPlayedCardNumberOfActivePlayer(const WarPlayer& a, const WarPlayer& b)
{
	if (a.IsActive() == b.IsActive())
	{
		return a.GetTopPlayedCard().GetNumber() < b.GetTopPlayedCard().GetNumber();
	}
	return b.IsActive();
}

void WarGame::PlayTurn()
{
	std::for_each(players.begin(), players.end(), PlayCard);
	int maxNumber = std::max_element(players.cbegin(), players.cend(), 
		BiggerPlayedCardNumberOfActivePlayer)->GetTopPlayedCard().GetNumber();

	for (auto& player : players)
	{
		player.SetActiveStatus(player.IsActive() && player.GetTopPlayedCard().GetNumber() == maxNumber);
	}
}