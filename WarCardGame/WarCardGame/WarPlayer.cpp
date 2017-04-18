#include "WarPlayer.h"
#include<assert.h>

WarPlayer::WarPlayer()
: drawPile()
, playedCards()
, isActive(true)
{
}

WarPlayer::~WarPlayer()
{
}

void WarPlayer::AddCardToDeckBottom(const Card& card)
{
	drawPile.AddToBottom(card);
}

void WarPlayer::AddCardsToDeckBottom(Deck& deck)
{
	drawPile.AddToBottom(deck);
}

bool WarPlayer::CanPlayCard()
{
	return drawPile.CanDraw();
}

void WarPlayer::PlayCard()
{
	assert(CanPlayCard());
	playedCards.AddToTop(drawPile.Draw());
}

void WarPlayer::SetActiveStatus(bool isActive)
{
	this->isActive = isActive;
}

Deck& WarPlayer::GetPlayedCards()
{
	return playedCards;
}

const Card& WarPlayer::GetTopPlayedCard() const
{
	assert(playedCards.CanDraw());
	return playedCards.GetTopCard();
}

bool WarPlayer::IsActive() const
{
	return isActive;
}