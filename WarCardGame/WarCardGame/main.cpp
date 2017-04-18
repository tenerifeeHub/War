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
	auto warGame = warGameFactory.CreateGame(12);
	CardPrinter printer(GetStdHandle(STD_OUTPUT_HANDLE));
	
	for (auto k = 0; k < 10; ++k)
	{
		warGame.PlayTurn();
		for (auto i = 0; i < warGame.GetPlayersCount(); ++i)
		{
			if (warGame.GetPlayer(i).IsActive())
			{
				printer.PrintCard(warGame.GetPlayer(i).GetTopPlayedCard());
			}
			printer.Ident();
		}
		if (warGame.GetCurrentTurn() == GameTurn::TakeCards)
		{
			printer.NewLine();
			warGame.PlayTurn();
		}
		printer.NewLine();
	}
}