#pragma once
#include<SFML\Graphics.hpp>
class Bomb
{
public:
	Bomb(int x, int y, sf::Image);
	~Bomb();
	// Return false when animation is done 
	bool bombAnimation(float time);
	void setPos(int x, int y);
	void setTime(float seconds);
	sf::Sprite getSprite();
	sf::Sprite getInvSprite();
	sf::FloatRect getBounds();
	sf::FloatRect getInvBounds();
	void setIsTimeWentOut(bool);
	bool getIsTimeWentOut();
	void setInvisibleWentOut(bool);
	bool getInvisibleWentOut();
	static unsigned short getCountBomb();
private:
	sf::Texture textureBomb;
	sf::Sprite spriteBomb;
	sf::Sprite invisibleBomb;
	static unsigned short countBomb;
	bool isTimeWentOut;
	bool wentInvisibleOut;
	sf::FloatRect bombBounds;
	sf::FloatRect bombInvisibleBounds;
	sf::Clock clock;
	float currentFrame;
	float lifeTimeSeconds;
};