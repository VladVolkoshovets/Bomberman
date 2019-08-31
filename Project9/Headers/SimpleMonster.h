#pragma once

#include"Monster.h"

class SimpleMonster : public Monster
{
public:
	SimpleMonster(Blocks * indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV);
	~SimpleMonster();

	void move(Blocks *, unsigned short, std::vector<Blocks*>, float, std::vector<Bomb*>, Wall &);

private:
	sf::Image image;
	sf::Texture texture;
	float currentFrame;
	bool movePossibility;
	int moveSide;
};

