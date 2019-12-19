#pragma once

#include"Monster.h"

class SimpleMonster : public Monster
{
public:
	SimpleMonster(Blocks *, unsigned short, std::vector<Blocks*>, sf::Image);
	virtual ~SimpleMonster();

	void move(Blocks *, unsigned short, std::vector<Blocks*>, float, std::vector<Bomb*>, Wall &);

private:
	sf::Texture texture;
	float currentFrame;
	bool movePossibility;
	int moveSide;
};

