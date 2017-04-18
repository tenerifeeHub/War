#include<iostream>

#include<windows.h>
#include "Card.h"
#include "PlayingCardsDeckFactory.h"
#include "CardPrinter.h"

void main()
{
	PlayingCardsDeckFactory deckFactory(2, 15);
	auto deck = deckFactory.CreateDeck();
	CardPrinter printer(GetStdHandle(STD_OUTPUT_HANDLE));
	
	while (deck.size() > 0)
	{
		printer.PrintCard(deck.front());
		printer.NewLine();
		deck.pop_front();
	}
}