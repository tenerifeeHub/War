#include "WarGame.h"
#include<algorithm>

WarGame::WarGame(std::vector<WarPlayer> players)
: players(players)
, currentTurn(GameTurn::PlayTopCard)
{
}


WarGame::~WarGame()
{
}

GameTurn WarGame::GetCurrentTurn() const
{
	return currentTurn;
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
	if (player.IsActive() && player.CanPlayCard())
	{
		player.PlayCard();
	}
}

void WarGame::PlayCards(int amount)
{
	for (auto i = 0; i < amount; ++i)
	{
		std::for_each(players.begin(), players.end(), PlayCard);
	}
	currentTurn = GameTurn::EvaluatePlayedCards;
}

int WarGame::MaxPlayedCardNumber() const
{
	int maxValue = -1;
	for (const auto& player : players)
	{
		if (player.IsActive() && player.GetTopPlayedCard().GetNumber() > maxValue)
		{
			maxValue = player.GetTopPlayedCard().GetNumber();
		}
	}
	return maxValue;
}

bool IsActivePlayer(const WarPlayer& player)
{
	return player.IsActive();
}

int WarGame::GetActivePlayersCount() const
{
	return std::count_if(players.begin(), players.end(), IsActivePlayer);
}

void WarGame::DeactivatePlayersWithLosingCards()
{
	int maxNumber = MaxPlayedCardNumber();
	for (auto& player : players)
	{
		player.SetActiveStatus(player.IsActive() && player.GetTopPlayedCard().GetNumber() == maxNumber);
	}

	currentTurn = (GetActivePlayersCount() > 1 ? GameTurn::War : GameTurn::TakeCards);
}

void WarGame::GiveCardsToWinner()
{
	auto& winner = *std::find_if(players.begin(), players.end(), IsActivePlayer);
	for (auto& player : players)
	{
		winner.AddCardsToDeckBottom(player.GetPlayedCards());
	}
}

void ActivatePlayerWithRemainingCards(WarPlayer& player)
{
	player.SetActiveStatus(player.CanPlayCard());
}

void WarGame::ReactivatePlayers()
{
	std::for_each(players.begin(), players.end(), ActivatePlayerWithRemainingCards);
	currentTurn = (GetActivePlayersCount() > 1 ? GameTurn::PlayTopCard : GameTurn::Finished);
}

void WarGame::PlayTurn()
{
	switch (currentTurn)
	{
	case GameTurn::PlayTopCard:
		PlayCards(1);
		break;
	
	case GameTurn::EvaluatePlayedCards:
		DeactivatePlayersWithLosingCards();
		break;

	case GameTurn::TakeCards:
		GiveCardsToWinner();
		ReactivatePlayers();
		break;
	
	case GameTurn::War:
		PlayCards(MaxPlayedCardNumber());
		break;
	
	default:
		break;
	}
}