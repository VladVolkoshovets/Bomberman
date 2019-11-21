#include"../Headers/DeathHero.h"

DeathHero::DeathHero(int x, int y, sf::Image imgDeathHero)
{
	
	textureDeath.loadFromImage(imgDeathHero);
	spriteDeath.setTexture(textureDeath);
	spriteDeath.setTextureRect(sf::IntRect(118, 0, 20, 20));
	spriteDeath.setScale(2., 2.);
	spriteDeath.setPosition(x, y-6);
	time.restart();
}

DeathHero::~DeathHero()
{
}
bool DeathHero::bitterDeath()
{

		if (time.getElapsedTime().asMilliseconds() > 250 && time.getElapsedTime().asMilliseconds() < 500)
		{
			spriteDeath.setTextureRect(sf::IntRect(118, 0, 20, 20));
		}
		else if (time.getElapsedTime().asMilliseconds() < 750)
		{
			spriteDeath.setTextureRect(sf::IntRect(148, 0, 20, 20));
		}
		else if (time.getElapsedTime().asMilliseconds() < 1000)
		{
			spriteDeath.setTextureRect(sf::IntRect(178, 0, 20, 20));
		}
		else if (time.getElapsedTime().asMilliseconds() < 1250)
		{
			spriteDeath.setTextureRect(sf::IntRect(118, 30, 20, 20));
		}
		else if (time.getElapsedTime().asMilliseconds() < 1500)
		{
			spriteDeath.setTextureRect(sf::IntRect(148, 30, 20, 20));
		}
		else if (time.getElapsedTime().asMilliseconds() < 1750)
		{
			spriteDeath.setTextureRect(sf::IntRect(178, 30, 20, 20));
		}
		else if (time.getElapsedTime().asMilliseconds() < 2000)
		{
			spriteDeath.setTextureRect(sf::IntRect(118, 60, 20, 20));
		}
		else if (time.getElapsedTime().asMilliseconds() < 2400)
		{
			spriteDeath.setTextureRect(sf::IntRect(147, 60, 22, 20));
			spriteDeath.move(0, -1);
		}
		if (time.getElapsedTime().asMilliseconds() >= 2400)
		{
			return false;
		}
	
	return true;
}
sf::Sprite DeathHero::getSprite()
{
	return spriteDeath;
}