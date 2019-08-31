#pragma once
#include<SFML\Graphics.hpp>
class Blocks
{
protected:

	sf::Sprite *spriteBlocks;
	sf::FloatRect blockBounds;

public:
	Blocks();
	virtual void setPos(int) = 0;
	sf::FloatRect getBound();
	sf::Sprite getSprite();
};