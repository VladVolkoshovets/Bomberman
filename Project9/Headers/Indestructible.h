#pragma once
#include "Blocks.h"
class Indestructible : public Blocks
{
private:
	void setPos(int i);
public:
	Indestructible();
	Indestructible(int counter, sf::Texture *textureBlocks)
	{
		spriteBlocks->setTexture(*textureBlocks);
		spriteBlocks->setTextureRect(sf::IntRect(0, 0, 66, 66));
		spriteBlocks->setScale(sf::Vector2f(0.61f, 0.61f));
		setPos(counter);
		blockBounds = spriteBlocks->getGlobalBounds();
	}
};