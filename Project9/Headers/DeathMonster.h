#pragma once
#include"SFML\Graphics.hpp"
#include"Global.h"
#include<iostream>
class DeathMonster
{
public:
	DeathMonster();
	~DeathMonster();
	// Return false when animation is done 
	virtual bool deathAnimation() = 0;
	virtual sf::Sprite getSprite() = 0;
protected:
	sf::Texture textureDeath;
	sf::Sprite spriteDeath;
	sf::Clock time;
};
