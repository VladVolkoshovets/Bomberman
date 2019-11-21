#pragma once
#include"SFML\Graphics.hpp"
class DeathHero
{
public:
	DeathHero(int, int, sf::Image);
	~DeathHero();
	bool bitterDeath();
	sf::Sprite getSprite();
private:
	
	sf::Texture textureDeath;
	sf::Sprite spriteDeath;
	sf::Clock time;
};
