#include"../Headers/MainFire.h"
MainFire::MainFire()
{
}
MainFire::MainFire(int x, int y, sf::Image imgFire) : Fire(x, y,  imgFire)
{
	textFire.loadFromImage(imgFire);
	sprFire.setTexture(textFire);
	sprFire.setTextureRect(sf::IntRect(146, 125, 66, 66));
	sprFire.setScale(sf::Vector2f(0.61f, 0.61f));
	setPos(x, y, sprFire);
}
bool MainFire::isFireBurning()
{
	if (time.getElapsedTime().asMilliseconds() >= 1200)
	{
		return false;
	}
	else return true;
}
MainFire::~MainFire()
{
}