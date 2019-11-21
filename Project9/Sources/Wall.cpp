#include"../Headers/Wall.h"
Wall::Wall()
{
	sizeWall = 600;
	sizeBlock = 40;
	
	wallUp.setTexture(textureWall);
	wallUp.setTextureRect(sf::IntRect(0, 0, 600, 40));
	wallUp.setPosition(0, 0);
	upBounds = wallUp.getGlobalBounds();

	wallLeft.setTexture(textureWall);
	wallLeft.setTextureRect(sf::IntRect(0, 40, 40, 520));
	wallLeft.setPosition(0, sizeBlock);
	leftBounds = wallLeft.getGlobalBounds();

	wallRight.setTexture(textureWall);
	wallRight.setTextureRect(sf::IntRect(560, 40, 40, 520));
	wallRight.setPosition(sizeWall - sizeBlock, sizeBlock);
	rightBounds = wallRight.getGlobalBounds();

	wallDown.setTexture(textureWall);
	wallDown.setTextureRect(sf::IntRect(0, 555, 600, 40));
	wallDown.setPosition(0, sizeWall - sizeBlock);
	downBounds = wallDown.getGlobalBounds();
}
void Wall::setTexture(sf::Image imageWall)
{
	textureWall.loadFromImage(imageWall);
}
sf::FloatRect Wall::getUpBound()
{
	return upBounds;
}

sf::FloatRect Wall::getLeftBound()
{
	return leftBounds;
}

sf::FloatRect Wall::getRightBound()
{
	return rightBounds;
}

sf::FloatRect Wall::getDownBound()
{
	return downBounds;
}

sf::Sprite Wall::getSpriteUp()
{
	return wallUp;
}

sf::Sprite Wall::getSpriteRight()
{
	return wallRight;
}

sf::Sprite Wall::getSpriteDown()
{
	return wallDown;
}

sf::Sprite Wall::getSpriteLeft()
{
	return wallLeft;
}
