#pragma once
#include<SFML\Graphics.hpp>
class Fire
{
public:
	Fire();
	Fire(int, int, sf::Image);
	virtual ~Fire();
	void setPos(int, int, sf::Sprite&);
	virtual bool isFireBurning() = 0;
	sf::Sprite getSprite();
protected:
	
	sf::Texture textFire;
	sf::Sprite sprFire;
	sf::Clock time;
};
