#ifndef WarGame_h
#define WarGame_h

#include<vector>
#include "WarPlayer.h"

class WarGame
{
private:
	std::vector<WarPlayer> players;

public:
	WarGame(std::vector<WarPlayer> players);
	~WarGame();

	int GetPlayersCount() const;
	const WarPlayer& GetPlayer(int index) const;

	void PlayTurn();
};

#endif