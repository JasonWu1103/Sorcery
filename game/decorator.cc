#include "decorator.h"

Decorator::Decorator(std::string cardName, int cost, Minion * component): 
	Card{cardName, cost}, component{component}{}

Minion * Decorator::getcomponent(){return component;}
void Decorator::setcomponent(Minion * ncomponent){component = ncomponent;}

void Decorator::playCard(Player * playedby, Player * opponent, int i, bool onme, int t){return;}
