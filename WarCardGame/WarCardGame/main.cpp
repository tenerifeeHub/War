#include<iostream>

#include<windows.h>
#include "Card.h"
#include "Suit.h"
#include "CardPrinter.h"

void main()
{
	Card card(4, Suit::Diamonds);
	CardPrinter printer(GetStdHandle(STD_OUTPUT_HANDLE));
	
	printer.PrintCard(card);
	printer.NewLine();
	printer.PrintCard(Card(5, Suit::Spades));
	printer.NewLine();
}