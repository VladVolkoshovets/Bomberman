#pragma once
#include"SFML\Graphics.hpp"
#include"Global.h"
class Ruined
{
public:
	Ruined();
	~Ruined();
	Ruined(int, int, sf::Image);
	bool destruction();
	sf::Sprite getSprite();
private:
	
	sf::Texture txtRuined;
	sf::Sprite sprRuined;
	sf::Clock time;
	unsigned short currentFrame;
	unsigned short animationSpeed;
};
