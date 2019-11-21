#include"../Headers/RightFire.h"
RightFire::RightFire()
{
}
RightFire::RightFire(int x, int y, sf::Image imgFire) : Fire(x, y, imgFire)
{
	textFire.loadFromImage(imgFire);
	sprFire.setTexture(textFire);
	sprFire.setTextureRect(sf::IntRect(146 + 66, 125, 66, 66));
	sprFire.setScale(sf::Vector2f(0.61f, 0.61f));
	setPos(x, y, sprFire);
}
bool RightFire::isFireBurning()
{
	if (time.getElapsedTime().asMilliseconds() >= 1200)
	{
		return false;
	}
	else return true;
}
RightFire::~RightFire()
{
}