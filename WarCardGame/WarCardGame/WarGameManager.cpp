#include "WarGameManager.h"
#include<iostream>

WarGameManager::WarGameManager(const WarGame& game, const CardPrinter& printer)
: game(game)
, printer(printer)
{
}


WarGameManager::~WarGameManager()
{
}

void WarGameManager::Play()
{
	while (game.GetCurrentTurn() != GameTurn::Finished)
	{
		game.PlayTurn();
		for (auto i = 0; i < game.GetPlayersCount(); ++i)
		{
			if (game.GetPlayer(i).IsActive())
			{
				printer.PrintCard(game.GetPlayer(i).GetTopPlayedCard());
				std::cout << "[" << game.GetPlayer(i).GetRemainingCardsInDeckCount() << "]";
			}
			std::cout << "\t";
		}
		if (game.GetCurrentTurn() == GameTurn::TakeCards)
		{
			std::cout << std::endl;
			game.PlayTurn();
		}
		std::cout << std::endl;
	}
	//switch (game.GetCurrentTurn())
	//{
	//case GameTurn::EvaluatePlayedCards:
	//	break;
	//case GameTurn::War:
	//	break;
	//case GameTurn::PlayTopCard:
	//	break;
	//case GameTurn::TakeCards:
	//	break;
	//case GameTurn::Finished:
	//	std::cout << "Winner is player %d";
	//	break;
	//}
}