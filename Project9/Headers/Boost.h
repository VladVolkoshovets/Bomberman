#pragma once
#include"SFML\Graphics.hpp"
class Boost
{
public:
	Boost(int, int, sf::Image boostImg);
	~Boost();
	sf::Sprite getSprite() const;
	sf::FloatRect getBound() const;

private:
	sf::Texture* boostTxt;
	sf::Sprite* boostSpr;
	sf::Sprite* invSpr;
};

