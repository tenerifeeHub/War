#include "WarPlayer.h"

WarPlayer::WarPlayer()
: cards()
{
}

WarPlayer::~WarPlayer()
{
}

void WarPlayer::AddCardToDeckBottom(const Card& card)
{
	cards.AddToBottom(card);
}