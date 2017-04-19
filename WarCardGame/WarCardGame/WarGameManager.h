#ifndef WarGameManager_h
#define WarGameManager_h

#include "WarGame.h"
#include "CardPrinter.h"

class WarGameManager
{
private:
	WarGame game;
	CardPrinter printer;

	int GetWinnerIndex() const;
	void PrintTurn();
public:
	WarGameManager(const WarGame& game, const CardPrinter& printer);
	~WarGameManager();

	void Play();
};

#endif