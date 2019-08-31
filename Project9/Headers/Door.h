#pragma once
#include"SFML\Graphics.hpp"
class Door
{
public:
	Door(int, int);
	~Door();

	sf::Sprite getSprite();

	sf::FloatRect getBound();

private:
	sf::Image *dorsImg;
	sf::Texture *doorTxt;
	sf::Sprite *doorSpr;
	sf::Sprite *invSpr;
};