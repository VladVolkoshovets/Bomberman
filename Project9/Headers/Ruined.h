#pragma once
#include"SFML\Graphics.hpp"
#include"Global.h"
class Ruined
{
public:
	Ruined();
	~Ruined();
	Ruined(int, int);
	bool destruction();
	sf::Sprite getSprite();
private:
	sf::Image imgRuined;
	sf::Texture txtRuined;
	sf::Sprite sprRuined;
	sf::Clock time;
	unsigned short currentFrame;
};
