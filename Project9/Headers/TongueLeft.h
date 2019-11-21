#pragma once
#include"Fire.h"
class TongueLeft : public Fire
{
public:
	TongueLeft();
	TongueLeft(int x, int y, sf::Image imgFire);
	bool isFireBurning();
	~TongueLeft();

private:

};