#include"../Headers/Fire.h"
Fire::Fire()
{
	
}
Fire::Fire(int x, int y, sf::Image imgFire)
{

}
Fire::~Fire()
{
}
void Fire::setPos(int x, int y, sf::Sprite &forSet)
{
	forSet.setPosition(x, y);
}
sf::Sprite Fire::getSprite()
{
	return sprFire;
}