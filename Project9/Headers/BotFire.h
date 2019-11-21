#pragma once
#include"Fire.h"
class BotFire : public Fire
{
public:
	BotFire();
	~BotFire();
	BotFire(int, int, sf::Image imgFire);
	bool isFireBurning();
private:

};