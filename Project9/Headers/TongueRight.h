#pragma once
#include"Fire.h"
class TongueRight : public Fire
{
public:
	TongueRight();
	TongueRight(int x, int y, sf::Image imgFire);
	bool isFireBurning();
	~TongueRight();

private:

};
