#pragma once
#include"SFML\Graphics.hpp"
class  Wall
{
public:
	Wall();
	void setTexture(sf::Image);
	sf::FloatRect getUpBound();
	sf::FloatRect getLeftBound();
	sf::FloatRect getRightBound();
	sf::FloatRect getDownBound();

	sf::Sprite getSpriteUp();
	sf::Sprite getSpriteRight();
	sf::Sprite getSpriteDown();
	sf::Sprite getSpriteLeft();
private:
	sf::Texture textureWall;
	sf::Sprite wallLeft;
	sf::Sprite wallUp;
	sf::Sprite wallRight;
	sf::Sprite wallDown;
	sf::FloatRect upBounds;
	sf::FloatRect leftBounds;
	sf::FloatRect rightBounds;
	sf::FloatRect downBounds;
	float sizeWall;
	float sizeBlock;
};