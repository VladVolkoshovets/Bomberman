#pragma once
#include "Blocks.h"
#include"Global.h"
class Destructible : public Blocks
{
public:
	Destructible::Destructible();
	Destructible(sf::Texture *, int);
	~Destructible();
private:
	void setPos(int);
};