#include"../Headers/Fone.h"
Fone::Fone()
{
	imageFone.loadFromFile("fone2.png");
	textureFone.loadFromImage(imageFone);
	spriteFone.setTexture(textureFone);
	spriteFone.setTextureRect(sf::IntRect(0, 0, 520, 300));
	spriteFone.setScale(sf::Vector2f(1, 520. / 300. + 0.00001));
	spriteFone.setPosition(unitSize, unitSize);
}

Fone::~Fone()
{
}

sf::Sprite Fone::getSprite()
{
	return spriteFone;
}
