#include "Deck.h"
#include<vector>

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

bool Deck::Draw(Card& card)
{
	if (CanDraw())
	{
		card = cards.front();
		cards.pop_front();
		return true;
	}
	return false;
}