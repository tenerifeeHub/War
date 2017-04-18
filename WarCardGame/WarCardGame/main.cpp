#include<iostream>

#include<time.h>
#include<windows.h>
#include "Card.h"
#include "Deck.h"

#include "WarGameFactory.h"
#include "WarGame.h"
#include "PlayingCardsDeckFactory.h"
#include "CardPrinter.h"

void main()
{
	srand(time(nullptr));

	WarGameFactory warGameFactory(PlayingCardsDeckFactory(2, 15));
	auto warGame = warGameFactory.CreateGame(3);
	CardPrinter printer(GetStdHandle(STD_OUTPUT_HANDLE));
	
	for (auto k = 0; k < 10; ++k)
	{
		warGame.PlayTurn();
		for (auto i = 0; i < warGame.GetPlayersCount(); ++i)
		{
			printer.PrintCard(warGame.GetPlayer(i).GetTopPlayedCard(), warGame.GetPlayer(i).IsActive());
			printer.Ident();
		}
		printer.NewLine();
	}
}