#include"../Headers/Door.h"
Door::Door(int x, int y)
{
	doorTxt = new sf::Texture;
	doorTxt->loadFromFile("blocks.png");
	doorSpr = new sf::Sprite;
	invSpr = new sf::Sprite;
	doorSpr->setTexture(*doorTxt);
	doorSpr->setTextureRect(sf::IntRect(171, 0, 66, 66));
	doorSpr->setScale(0.61f, 0.61f);
	doorSpr->setPosition(x, y);
	invSpr->setTextureRect(sf::IntRect(0, 0, 20, 20));
	invSpr->setPosition(x + 10, y + 10);
}

Door::~Door()
{
}
sf::Sprite Door::getSprite()
{
	return *doorSpr;
}
sf::FloatRect Door::getBound()
{
	return invSpr->getGlobalBounds();
}