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

int WarGameManager::GetWinnerIndex() const
{
	for (auto i = 0; i < game.GetPlayersCount(); ++i)
	{
		if (game.GetPlayer(i).IsActive())
		{
			return i;
		}
	}
	assert(false && "Winner player index not found");
	return -1;
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
		std::cout << "Final Winner is player " << GetWinnerIndex() + 1 << std::endl;
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