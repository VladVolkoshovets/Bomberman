#include"../Headers/Blocks.h"
Blocks::Blocks() {
	spriteBlocks = new sf::Sprite;
}
sf::Sprite Blocks::getSprite()
{
	return *spriteBlocks;
}
sf::FloatRect Blocks::getBound()
{
	return blockBounds;
}