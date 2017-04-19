#ifndef WarGame_h
#define WarGame_h

#include<vector>
#include "WarPlayer.h"
#include "GameTurn.h"

class WarGame
{
private:
	GameTurn currentTurn;
	std::vector<WarPlayer> players;

	void PlayCards(int amount);
	int MaxPlayedCardNumber() const;

	void DeactivatePlayersWithLosingCards();
	void GiveCardsToWinner();
	void ReactivatePlayers();

	int GetActivePlayersCount() const;
	int GetActivePlayerWithCardsInDeckCount() const;

public:
	WarGame(std::vector<WarPlayer> players);
	~WarGame();

	GameTurn GetCurrentTurn() const;
	int GetPlayersCount() const;
	const WarPlayer& GetPlayer(int index) const;

	void PlayTurn();
};

#endif