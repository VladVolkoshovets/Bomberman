#pragma once
#include"Fire.h"
class LeftFire : public Fire
{
public:
	LeftFire();
	~LeftFire();
	LeftFire(int, int, sf::Image imgFire);
	bool isFireBurning();
private:

};
