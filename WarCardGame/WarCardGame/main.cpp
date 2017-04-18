#include<iostream>

#include<time.h>
#include<windows.h>
#include "Card.h"
#include "Deck.h"
#include "GameTurn.h"
#include "WarGameFactory.h"
#include "WarGame.h"
#include "PlayingCardsDeckFactory.h"
#include "CardPrinter.h"

void main()
{
	srand(time(nullptr));

	WarGameFactory warGameFactory(PlayingCardsDeckFactory(2, 15));
	auto warGame = warGameFactory.CreateGame(6);
	CardPrinter printer(GetStdHandle(STD_OUTPUT_HANDLE));
	
	while (warGame.GetCurrentTurn() != GameTurn::Finished)
	{
		warGame.PlayTurn();
		for (auto i = 0; i < warGame.GetPlayersCount(); ++i)
		{
			if (warGame.GetPlayer(i).IsActive())
			{
				printer.PrintCard(warGame.GetPlayer(i).GetTopPlayedCard());
				std::cout << "[" << warGame.GetPlayer(i).GetRemainingCardsInDeckCount() << "]";
			}
			std::cout << "\t";
		}
		if (warGame.GetCurrentTurn() == GameTurn::TakeCards)
		{
			std::cout << std::endl;
			warGame.PlayTurn();
		}
		std::cout << std::endl;
	}
}