#pragma once
#include"Fire.h"

class TopFire : public Fire
{
public:
	TopFire();
	~TopFire();
	TopFire(int, int, sf::Image imgFire);
	bool isFireBurning();
private:

};