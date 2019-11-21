#include"../Headers/Bomb.h"
Bomb::Bomb(int x, int y, sf::Image imageBomb)
{
	textureBomb.loadFromImage(imageBomb);
	spriteBomb.setTexture(textureBomb);
	spriteBomb.setTextureRect(sf::IntRect(0, 0, 66, 66));
	spriteBomb.setScale(sf::Vector2f(0.6f, 0.6f));
	
	invisibleBomb.setTextureRect(sf::IntRect(0, 0, 27, 27));
	invisibleBomb.setScale(sf::Vector2f(0.6f, 0.6f));
	countBomb++;
	setPos(x, y);
	bombBounds = spriteBomb.getGlobalBounds();
	bombInvisibleBounds = invisibleBomb.getGlobalBounds();
	isTimeWentOut = false, wentInvisibleOut = false, currentFrame = false, lifeTimeSeconds = false;
}
Bomb::~Bomb()
{
	countBomb--;
}

bool Bomb::bombAnimation(float time)
{
	if (int(lifeTimeSeconds) >= 2.3)
	{
		return false;
	}
	lifeTimeSeconds = clock.getElapsedTime().asSeconds();

	// Animation
	currentFrame += 0.03*time;
	if (currentFrame >= 4)
	{
		currentFrame = 0;
	}
	switch ((int)currentFrame)
	{
	case 0:
		spriteBomb.setTextureRect(sf::IntRect(0, 0, 66, 66));
		break;
	case 1:
		spriteBomb.setTextureRect(sf::IntRect(98, 0, 66, 66));
		break;
	case 2:
		spriteBomb.setTextureRect(sf::IntRect(200, 0, 66, 66));
		break;
	case 3:
		spriteBomb.setTextureRect(sf::IntRect(98, 0, 66, 66));
		break;
	default:
		break;
	}
	return true;
}
void Bomb::setPos(int x, int y)
{
	if ((x % 40) < 20)
	{
		x = x - (x % 40);
	}
	else
	{
		x = (x - (x % 40)) + 40;
	}
	if ((y % 40) < 20)
	{
		y = y - (y % 40);
	}
	else
	{
		y = (y - (y % 40)) + 40;
	}
	spriteBomb.setPosition(x, y);
	invisibleBomb.setPosition(x + 12, y + 12);
}
void Bomb::setTime(float seconds)
{
	this->lifeTimeSeconds = seconds;
}
sf::Sprite Bomb::getSprite()
{
	return spriteBomb;
}
sf::Sprite Bomb::getInvSprite()
{
	return invisibleBomb;
}
sf::FloatRect Bomb::getBounds()
{
	return bombBounds;

}
sf::FloatRect Bomb::getInvBounds()
{
	return bombInvisibleBounds;
}
void Bomb::setIsTimeWentOut(bool isTimeWentOut)
{
	this->isTimeWentOut = isTimeWentOut;
}
bool Bomb::getIsTimeWentOut()
{
	return isTimeWentOut;
}
void Bomb::setInvisibleWentOut(bool wenInvOut)
{
	this->wentInvisibleOut = wenInvOut;
}
bool Bomb::getInvisibleWentOut()
{
	return wentInvisibleOut;
}
unsigned short Bomb::getCountBomb()
{
	return countBomb;
}
unsigned short Bomb::countBomb = 0;