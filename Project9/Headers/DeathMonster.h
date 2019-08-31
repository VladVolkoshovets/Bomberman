#pragma once
#include"SFML\Graphics.hpp"
#include"Global.h"
#include<iostream>
class DeathMonster
{
public:
	DeathMonster();
	~DeathMonster();
	virtual bool sweetDeath() = 0;
	virtual sf::Sprite getSprite() = 0;
protected:
	sf::Image imageDeath;
	sf::Texture textureDeath;
	sf::Sprite spriteDeath;
	sf::Clock time;
};
