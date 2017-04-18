#ifndef CardPrinter_h
#define CardPrinter_h

#include <windows.h>
#include <map>
#include "Suit.h"

class Card;

class CardPrinter
{
private:
	HANDLE console;
	const wchar_t* suitUnicodes[Suit::Count];
	WORD suitColors[2][Suit::Count];
	std::map<int, char> numberKeys;

private:
	void PrintNumber(int number);
	void PrintSuit(Suit suit);

public:
	CardPrinter(HANDLE console);
	~CardPrinter();

	void PrintCard(const Card& card, bool isWinning = false);

	void Ident();
	void NewLine();
};

#endif