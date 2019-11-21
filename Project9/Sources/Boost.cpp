#include "../Headers/Boost.h"
Boost::Boost(int x, int y, sf::Image boostImg)
{
	boostTxt = new sf::Texture;
	boostTxt->loadFromImage (boostImg);
	boostSpr = new sf::Sprite;
	InvisibleSpr = new sf::Sprite;
	boostSpr->setTexture(*boostTxt);
	boostSpr->setTextureRect(sf::IntRect(30, 30, 165, 165));
	boostSpr->setScale(0.234f, 0.234f);
	boostSpr->setPosition(x, y);
	InvisibleSpr->setTextureRect(sf::IntRect(0, 0, 20, 20));
	InvisibleSpr->setPosition(x + 10, y + 10);
}
Boost::~Boost()
{
	delete boostTxt;
	delete boostSpr;
	delete InvisibleSpr;
}
sf::Sprite Boost::getSprite() const
{
	return *boostSpr;
}
sf::FloatRect Boost::getBound() const
{
	return InvisibleSpr->getGlobalBounds();
}
