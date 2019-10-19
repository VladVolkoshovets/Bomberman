#pragma once
#include"SFML\Graphics.hpp"
class Door
{
public:
	Door(int, int);
	~Door();

	sf::Sprite getSprite() const;

	sf::FloatRect getBound() const;

private:
	sf::Image *dorsImg;
	sf::Texture *doorTxt;
	sf::Sprite *doorSpr;
	sf::Sprite *invSpr;
};