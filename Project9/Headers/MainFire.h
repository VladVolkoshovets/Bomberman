#pragma once
#include"Fire.h"

class MainFire : public Fire
{
public:
	MainFire();
	MainFire(int, int, sf::Image imgFire);
	bool isFireBurning();
	~MainFire();

private:

};