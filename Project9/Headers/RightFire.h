#pragma once
#include"Fire.h"
class RightFire : public Fire
{
public:
	RightFire();
	~RightFire();
	RightFire(int, int, sf::Image imgFire);
	bool isFireBurning();
private:

};
