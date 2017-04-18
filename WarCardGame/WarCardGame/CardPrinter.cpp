#include "CardPrinter.h"
#include "Card.h"
#include<iostream>
#include<assert.h>

#define RED_CARD_WINNING FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE
#define BLACK_CARD_WINNING FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE
#define RED_CARD FOREGROUND_RED | FOREGROUND_INTENSITY
#define BLACK_CARD FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define RESET_COLOR FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY

CardPrinter::CardPrinter(HANDLE console)
: console(console)
, suitColors()
{
	suitColors[0][Suit::Diamonds] = RED_CARD;
	suitColors[0][Suit::Clubs] = BLACK_CARD;
	suitColors[0][Suit::Hearts] = RED_CARD;
	suitColors[0][Suit::Spades] = BLACK_CARD;
	suitColors[1][Suit::Diamonds] = RED_CARD_WINNING;
	suitColors[1][Suit::Clubs] = BLACK_CARD_WINNING;
	suitColors[1][Suit::Hearts] = RED_CARD_WINNING;
	suitColors[1][Suit::Spades] = BLACK_CARD_WINNING;

	numberKeys[11] = 'J';
	numberKeys[12] = 'Q';
	numberKeys[13] = 'K';
	numberKeys[14] = 'A';

	suitUnicodes[Suit::Diamonds] = L"\u2666";
	suitUnicodes[Suit::Clubs] = L"\u2663";
	suitUnicodes[Suit::Hearts] = L"\u2665";
	suitUnicodes[Suit::Spades] = L"\u2660";
}

CardPrinter::~CardPrinter()
{
}

void CardPrinter::PrintNumber(int number)
{
	if (numberKeys.find(number) == numberKeys.end())
	{
		std::cout << number;
	}
	else
	{
		std::cout << numberKeys[number];
	}
}

void CardPrinter::PrintSuit(Suit suit)
{
	DWORD n;
	WriteConsoleW(console, suitUnicodes[suit], 1, &n, nullptr);
}

void CardPrinter::PrintCard(const Card& card, bool isWinning)
{
	assert(card.GetSuit() < Suit::Count && card.GetSuit() > -1);
	SetConsoleTextAttribute(console, suitColors[isWinning][card.GetSuit()]);

	PrintNumber(card.GetNumber());
	PrintSuit(card.GetSuit());

	SetConsoleTextAttribute(console, RESET_COLOR);
}

void CardPrinter::Ident()
{
	std::cout << "\t";
}

void CardPrinter::NewLine()
{
	std::cout << std::endl;
}