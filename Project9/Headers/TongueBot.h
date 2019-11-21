#pragma once
#include"Fire.h"
class TongueBot : public Fire
{
public:
	TongueBot();
	TongueBot(int x, int y, sf::Image imgFire);
	bool isFireBurning();
	~TongueBot();

private:

};