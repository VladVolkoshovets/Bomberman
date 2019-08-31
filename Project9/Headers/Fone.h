#pragma once
#include"SFML\Graphics.hpp"
#include"Global.h"
class Fone
{
public:
	Fone();
	~Fone();
	sf::Sprite getSprite();
private:
	sf::Image imageFone;
	sf::Texture textureFone;
	sf::Sprite spriteFone;
};

