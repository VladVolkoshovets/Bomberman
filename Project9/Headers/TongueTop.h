#pragma once
#include"Fire.h"
class TongueTop : public Fire
{
public:
	TongueTop();
	TongueTop(int x, int y, sf::Image imgFire);
	bool isFireBurning();
	~TongueTop();

private:

};
