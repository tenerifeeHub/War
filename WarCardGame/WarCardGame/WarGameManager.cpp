#include "WarGameManager.h"
#include<iostream>
#include<assert.h>

WarGameManager::WarGameManager(const WarGame& game, const CardPrinter& printer)
: game(game)
, printer(printer)
{
}


WarGameManager::~WarGameManager()
{
}

std::vector<int> WarGameManager::GetWinnersIndices() const
{
	std::vector<int> winners;
	for (auto i = 0; i < game.GetPlayersCount(); ++i)
	{
		if (game.GetPlayer(i).IsActive())
		{
			winners.push_back(i);
		}
	}
	return winners;
}

int WarGameManager::GetWinnerIndex() const
{
	auto winners = GetWinnersIndices();
	assert(winners.size() > 0);
	return winners[0];
}

bool WarGameManager::HasOnlyOneWinner() const
{
	return GetWinnersIndices().size() == 1;
}

void WarGameManager::PrintTurn()
{
	switch (game.GetCurrentTurn())
	{
	case GameTurn::EvaluatePlayedCards:
		for (auto i = 0; i < game.GetPlayersCount(); ++i)
		{
			if (game.GetPlayer(i).IsActive())
			{
				printer.PrintCard(game.GetPlayer(i).GetTopPlayedCard());
				std::cout << "[" << game.GetPlayer(i).GetRemainingCardsInDeckCount() << "]";
			}
			std::cout << "\t";
		}
		std::cout << std::endl;
		break;
	case GameTurn::War:
		break;
	case GameTurn::PlayTopCard:
		break;
	case GameTurn::TakeCards:
		std::cout << "Round Winner is player " << GetWinnerIndex() + 1 << std::endl << std::endl;
		break;
	case GameTurn::Finished:
		if (HasOnlyOneWinner())
		{
			std::cout << "Final Winner is player " << GetWinnerIndex() + 1 << std::endl;
		}
		else
		{
			std::cout << "Tie between players ";
			auto winnerIndices = GetWinnersIndices();
			for (int i = 0; i < winnerIndices.size() - 1; ++i)
			{
				std::cout << winnerIndices[i] << ", ";
			}
			std::cout << winnerIndices[winnerIndices.size() - 1] << std::endl;
		}
		break;
	}
}

void WarGameManager::Play()
{
	while (game.GetCurrentTurn() != GameTurn::Finished)
	{
		game.PlayTurn();
		PrintTurn();
	}
}