#pragma once
#include"SFML\Graphics.hpp"
class Door
{
public:
	Door(int, int, sf::Image);
	~Door();
	sf::Sprite getSprite() const;
	sf::FloatRect getBound() const;

private:
	sf::Texture *doorTxt;
	sf::Sprite *doorSpr;
	sf::Sprite *invSpr;
};