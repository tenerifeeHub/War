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
	
	PlayingCardsDeckFactory deckFactory(2, 15);
	auto deck = deckFactory.CreateDeck();
	deck.Shuffle();
	while (deck.CanDraw())
	{
		printer.PrintCard(deck.Draw());
		printer.NewLine();
	}
}