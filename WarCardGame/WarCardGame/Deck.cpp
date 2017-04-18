#include "Deck.h"
#include<vector>
#include<assert.h>

Deck::Deck()
: cards()
{
}

Deck::Deck(std::list<Card> cards)
	: cards(cards)
{
}


Deck::~Deck()
{
}

void MoveCardsToVector(std::vector<Card>& pile, std::list<Card>& cards)
{
	for (auto card : cards)
	{
		pile.push_back(card);
	}
	cards.clear();
}

Card TakeOutRandomCard(std::vector<Card>& pile)
{
	auto randomIndex = rand() % pile.size();
	auto card = pile[randomIndex];
	pile.erase(pile.begin() + randomIndex);
	return card;
}

void Deck::Shuffle()
{
	std::vector<Card> pile;
	MoveCardsToVector(pile, cards);

	while (pile.size() > 0)
	{
		cards.push_back(TakeOutRandomCard(pile));
	}
}

bool Deck::CanDraw() const
{
	return cards.size() > 0;
}

Card Deck::Draw()
{
	assert(cards.size() > 0);
	Card card = cards.front();
	cards.pop_front();
	return card;
}

void Deck::AddToTop(const Card& card)
{
	cards.push_front(card);
}

void Deck::AddToBottom(const Card& card)
{
	cards.push_back(card);
}

void Deck::AddToBottom(Deck& deckSource)
{
	while (deckSource.CanDraw())
	{
		AddToBottom(deckSource.Draw());
	}
}

const Card& Deck::GetTopCard() const
{
	return cards.front();
}

int Deck::Count() const
{
	return cards.size();
}