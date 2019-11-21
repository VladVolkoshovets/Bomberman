#pragma once
#include"SFML\Graphics.hpp"
#include"Global.h"
#include"Blocks.h"
#include"Bomb.h"
#include"Wall.h"
#include<iostream>
class Monster
{
public:
	Monster();
	~Monster();
	static unsigned short monsterCount;
	virtual void move(Blocks * , unsigned short , std::vector<Blocks*> , float , std::vector<Bomb*> , Wall & ) = 0;
	sf::Sprite getSprite();
	sf::FloatRect getBounds();
protected:
	float moveSpeed;
	sf::Sprite spriteMonster;
	sf::Sprite invSprite;
	void setPosition(Blocks * , unsigned short , std::vector<Blocks*> );
	
};
