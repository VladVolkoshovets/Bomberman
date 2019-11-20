#include"../Headers/Fone.h"
Fone::Fone()
{
	spriteFone.setTexture(textureFone);
	spriteFone.setTextureRect(sf::IntRect(0, 0, 520, 300));
	spriteFone.setScale(sf::Vector2f(1, 520. / 300. + 0.00001));
	spriteFone.setPosition(UNIT_SIZE, UNIT_SIZE);
}

Fone::~Fone()
{
}

void Fone::setTexture(sf::Image imageFone)
{
	textureFone.loadFromImage(imageFone);
}

sf::Sprite Fone::getSprite()
{
	return spriteFone;
}
