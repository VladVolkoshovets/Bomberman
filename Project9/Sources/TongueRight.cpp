#include"../Headers/TongueRight.h"
TongueRight::TongueRight()
{
}
TongueRight::TongueRight(int x, int y) : Fire(x, y)
{
	imgFire.loadFromFile("fire.png");//146 125
	textFire.loadFromImage(imgFire);
	sprFire.setTexture(textFire);
	sprFire.setTextureRect(sf::IntRect(334 - 66, 125, 66, 66));
	sprFire.setScale(sf::Vector2f(0.61f, 0.61f));
	setPos(x, y, sprFire);
}
bool TongueRight::fireInTheHall()
{
	if (time.getElapsedTime().asMilliseconds() >= 1200)
	{

	}
	return false;
}
TongueRight::~TongueRight()
{
}