#include<iostream>

#include<time.h>
#include<windows.h>
#include "Card.h"
#include "Deck.h"
#include "PlayingCardsDeckFactory.h"
#include "CardPrinter.h"

void main()
{
	srand(time(nullptr));

	PlayingCardsDeckFactory deckFactory(2, 15);
	auto deck = deckFactory.CreateDeck();
	CardPrinter printer(GetStdHandle(STD_OUTPUT_HANDLE));
	
	deck.Shuffle();
	Card card;
	while (deck.Draw(card))
	{
		printer.PrintCard(card);
		printer.NewLine();
	}
}