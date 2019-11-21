#pragma once
#include"DeathMonster.h"
class DeathSimpleMomster : public DeathMonster
{
public:
	DeathSimpleMomster(int, int, sf::Image);
	~DeathSimpleMomster();
	// Return false when animation is done 
	bool deathAnimation();
	sf::Sprite getSprite();
private:

};