#include<iostream>

#include<time.h>
#include<windows.h>
#include "Card.h"
#include "Deck.h"
#include "GameTurn.h"
#include "WarGameFactory.h"
#include "WarGame.h"
#include "PlayingCardsDeckFactory.h"
#include "CardPrinter.h"
#include "WarGameManager.h"


void SetRandomSeed()
{
	srand(time(nullptr));
}

void PrintRandomSeed()
{
	auto seed = time(nullptr);
	srand(seed);
	std::cout << "Random seed: " << seed << std::endl;
}

void main()
{
	SetRandomSeed();

	WarGameFactory warGameFactory(PlayingCardsDeckFactory(2, 15));
	auto warGame = warGameFactory.CreateGame(12);
	CardPrinter printer(GetStdHandle(STD_OUTPUT_HANDLE));
	WarGameManager gameManager(warGame, printer);

	gameManager.Play();
}