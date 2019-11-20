#pragma once
#include"SFML\Graphics.hpp"
#include"Global.h"
class Fone
{
public:
	Fone();
	~Fone();
	void setTexture(sf::Image);
	sf::Sprite getSprite();
private:
	sf::Texture textureFone;
	sf::Sprite spriteFone;
};

