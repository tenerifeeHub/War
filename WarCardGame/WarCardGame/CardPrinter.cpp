#include "CardPrinter.h"
#include "Card.h"
#include<iostream>

#define RED_CARD FOREGROUND_RED | FOREGROUND_INTENSITY
#define BLACK_CARD FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define RESET_COLOR FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY

CardPrinter::CardPrinter(HANDLE console)
	: console(console)
	, suitColors()
{
	suitColors[Suit::Diamonds] = RED_CARD;
	suitColors[Suit::Clubs] = BLACK_CARD;
	suitColors[Suit::Hearts] = RED_CARD;
	suitColors[Suit::Spades] = BLACK_CARD;

	suitUnicodes[Suit::Diamonds] = L"\u2666";
	suitUnicodes[Suit::Clubs] = L"\u2663";
	suitUnicodes[Suit::Hearts] = L"\u2665";
	suitUnicodes[Suit::Spades] = L"\u2660";
}


CardPrinter::~CardPrinter()
{
}

void CardPrinter::PrintSuit(Suit suit)
{
	DWORD n;
	WriteConsoleW(console, suitUnicodes[suit], 1, &n, nullptr);
}

void CardPrinter::PrintCard(const Card& card)
{
	SetConsoleTextAttribute(console, suitColors[card.GetSuit()]);

	std::cout << card.GetNumber();
	PrintSuit(card.GetSuit());

	SetConsoleTextAttribute(console, RESET_COLOR);
}

void CardPrinter::NewLine()
{
	std::cout << std::endl;
}