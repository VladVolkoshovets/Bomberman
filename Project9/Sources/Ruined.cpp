#include"../Headers/Ruined.h"
Ruined::Ruined()
{
}
Ruined::Ruined(int x, int y)
{
	imgRuined.loadFromFile("ruined.png");
	txtRuined.loadFromImage(imgRuined);
	sprRuined.setTexture(txtRuined);
	sprRuined.setTextureRect(sf::IntRect(8, 156, unitSize, unitSize));
	sprRuined.setPosition(x, y);
	currentFrame = 0;
}
bool Ruined::destruction()
{
	if (currentFrame == 7)
	{
		return false;
	}
	currentFrame = time.getElapsedTime().asMilliseconds() / 171, 4;
	sprRuined.setTextureRect(sf::IntRect(9 + 50 * currentFrame, 156, unitSize, unitSize));
	return true;
}
sf::Sprite Ruined::getSprite()
{
	return sprRuined;
}
Ruined::~Ruined()
{
}