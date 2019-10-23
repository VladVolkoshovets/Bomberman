#include"../Headers/BotFire.h"
BotFire::BotFire()
{
}

BotFire::~BotFire()
{
}
BotFire::BotFire(int x, int y) : Fire(x, y)
{
	imgFire.loadFromFile("fire.png");//
	textFire.loadFromImage(imgFire);
	sprFire.setTexture(textFire);
	sprFire.setTextureRect(sf::IntRect(146, 125 + 66, 66, 66));
	sprFire.setScale(sf::Vector2f(0.61f, 0.61f));
	setPos(x, y, sprFire);
}
bool BotFire::fireInTheHall()
{
	if (time.getElapsedTime().asMilliseconds() >= 1200)
	{
		return false;
	}
	else return true;
}