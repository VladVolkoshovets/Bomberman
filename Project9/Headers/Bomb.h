#pragma once
#include<SFML\Graphics.hpp>
class Bomb
{
public:
	Bomb(int x, int y, sf::Image);
	~Bomb();
	bool isBombAlive(float time);
	void setpos(int x, int y);
	void setTime(float seconds);
	sf::Sprite getSprite();
	sf::Sprite getInvSprite();
	sf::FloatRect getBounds();
	sf::FloatRect getInvBounds();
	void setWentOut(bool wentOut);
	bool getWentOut();
	void setInvWentOut(bool wenInvOut);
	bool getInvWentOut();
	static unsigned short getCountBomb();
private:
	
	sf::Texture textureBomb;
	sf::Sprite spriteBomb;
	sf::Sprite inviseBomb;
	static unsigned short countBomb;
	bool wentOut;
	bool wentInvOut;
	sf::FloatRect bombBounds;
	sf::FloatRect bombInvBounds;
	sf::Clock superTime;
	float currentFrame;
	float lifeTimeSeconds;
};