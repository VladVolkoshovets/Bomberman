#pragma once
#include"SFML\Graphics.hpp"
class DeathHero
{
public:
	DeathHero(int, int);
	~DeathHero();
	bool bitterDeath();
	sf::Sprite getSprite();
private:
	sf::Image imageDeath;
	sf::Texture textureDeath;
	sf::Sprite spriteDeath;
	sf::Clock time;
};
