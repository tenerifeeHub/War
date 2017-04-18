#include "WarPlayer.h"
#include<assert.h>

WarPlayer::WarPlayer()
: drawPile()
, playedCards()
{
}

WarPlayer::~WarPlayer()
{
}

void WarPlayer::AddCardToDeckBottom(const Card& card)
{
	drawPile.AddToBottom(card);
}

void WarPlayer::PlayCard()
{
	assert(drawPile.CanDraw());
	playedCards.AddToTop(drawPile.Draw());
}