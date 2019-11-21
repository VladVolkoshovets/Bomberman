#pragma once
#include"DeathMonster.h"
class DeathSimpleMomster : public DeathMonster
{
public:
	DeathSimpleMomster(int, int, sf::Image);
	~DeathSimpleMomster();
	bool deathAnimation();
	sf::Sprite getSprite();
private:

};