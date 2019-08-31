#pragma once
#include<SFML\Graphics.hpp>
class Fire
{
public:
	Fire();
	Fire(int, int);
	~Fire();
	void setPos(int, int, sf::Sprite&);
	virtual bool fireInTheHall() = 0;
	sf::Sprite getSprite();
protected:
	sf::Image imgFire;
	sf::Texture textFire;
	sf::Sprite sprFire;
	sf::Clock time;
};
