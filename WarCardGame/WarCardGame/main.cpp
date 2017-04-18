#include<iostream>

#include "Card.h"
#include "Suit.h"

void main()
{
	Card card(4, Suit::Diamonds);
	std::cout << card.GetNumber() << " " << card.GetSuit() << std::endl;
}