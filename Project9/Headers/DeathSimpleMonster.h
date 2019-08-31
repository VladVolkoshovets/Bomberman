#pragma once
#include"DeathMonster.h"
class DeathSimpleMomster : public DeathMonster
{
public:
	DeathSimpleMomster(int, int);
	~DeathSimpleMomster();
	bool sweetDeath();
	sf::Sprite getSprite();
private:

};