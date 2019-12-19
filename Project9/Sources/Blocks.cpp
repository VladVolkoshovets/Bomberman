#include"../Headers/Blocks.h"
Blocks::Blocks() {
	spriteBlocks = new sf::Sprite;
}
Blocks::~Blocks()
{
}
sf::Sprite Blocks::getSprite()
{
	return *spriteBlocks;
}
sf::FloatRect Blocks::getBound()
{
	return blockBounds;
}