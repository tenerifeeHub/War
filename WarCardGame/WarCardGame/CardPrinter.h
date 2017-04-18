#ifndef CardPrinter_h
#define CardPrinter_h

#include <windows.h>
#include "Suit.h"

class Card;

class CardPrinter
{
private:
	HANDLE console;
	const wchar_t* suitUnicodes[Suit::Count];
	WORD suitColors[Suit::Count];

private:
	void PrintSuit(Suit suit);

public:
	CardPrinter(HANDLE console);
	~CardPrinter();

	void PrintCard(const Card& card);
	void NewLine();
};

#endif