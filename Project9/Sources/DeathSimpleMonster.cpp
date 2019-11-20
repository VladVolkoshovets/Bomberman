#include"../Headers/DeathSimpleMonster.h"
DeathSimpleMomster::DeathSimpleMomster(int x, int y)
{
	imageDeath.loadFromFile("monster_death.png");
	textureDeath.loadFromImage(imageDeath);
	spriteDeath.setTexture(textureDeath);
	spriteDeath.setTextureRect(sf::IntRect(0, 0, 66, 66));
	spriteDeath.setScale(UNIT_SIZE / 66. + 0.00001, UNIT_SIZE / 66. + 0.00001);
	spriteDeath.setPosition(x, y);
	//time.restart();
}
bool DeathSimpleMomster::sweetDeath()
{
	if (time.getElapsedTime().asMilliseconds() > 1400)
	{
		if (time.getElapsedTime().asMilliseconds() < 1650)
		{
			spriteDeath.setTextureRect(sf::IntRect(113, 0, 66, 66));
		}
		else if (time.getElapsedTime().asMilliseconds() < 1900)
		{
			spriteDeath.setTextureRect(sf::IntRect(213, 0, 66, 66));
		}
		else if (time.getElapsedTime().asMilliseconds() < 2150)
		{
			spriteDeath.setTextureRect(sf::IntRect(296, 0, 66, 66));
		}
		else if (time.getElapsedTime().asMilliseconds() < 2400)
		{
			spriteDeath.setTextureRect(sf::IntRect(463, 0, 66, 66));
		}
		else if(time.getElapsedTime().asMilliseconds() >= 2400)
		{
			return false;
		}
	
	}
	return true;

}
sf::Sprite DeathSimpleMomster::getSprite()
{
	return spriteDeath;
}
DeathSimpleMomster::~DeathSimpleMomster()
{
}