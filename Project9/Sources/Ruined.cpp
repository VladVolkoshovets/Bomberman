#include"../Headers/Ruined.h"
Ruined::Ruined(int x, int y, sf::Image imgRuined)
{
	txtRuined.loadFromImage(imgRuined);
	sprRuined.setTexture(txtRuined);
	sprRuined.setTextureRect(sf::IntRect(8, 156, UNIT_SIZE, UNIT_SIZE));
	sprRuined.setPosition(x, y);
	currentFrame = 0;
	animationSpeed = 171;
}
bool Ruined::destruction()
{
	if (currentFrame == 7)
	{
		return false;
	}
	currentFrame = time.getElapsedTime().asMilliseconds() / animationSpeed;
	sprRuined.setTextureRect(sf::IntRect(9 + 50 * currentFrame, 156, UNIT_SIZE, UNIT_SIZE));
	return true;
}
sf::Sprite Ruined::getSprite()
{
	return sprRuined;
}
Ruined::~Ruined()
{
}