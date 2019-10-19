#pragma once
#include"SFML\Graphics.hpp"
class Boost
{
public:
	Boost(int, int);
	~Boost();
	sf::Sprite getSprite() const;
	sf::FloatRect getBound() const;

private:
	sf::Image* boostImg;
	sf::Texture* boostTxt;
	sf::Sprite* boostSpr;
	sf::Sprite* invSpr;
};

