#pragma once

#include<vector>
#include<SFML\Graphics.hpp>
#include"Global.h"
#include"Wall.h"
#include"Blocks.h"
#include"Destructible.h"
#include"Indestructible.h"
#include"Fone.h"
#include"Door.h"
#include"Boost.h"
#include"Bomb.h"
#include"Fire.h"
#include"Player.h"
#include"Ruined.h"
#include"Monster.h"
#include"SimpleMonster.h"
#include"DeathMonster.h"
#include"DeathSimpleMonster.h"
#include"DeathHero.h"
#include"MainFire.h"
#include"LeftFire.h"
#include"RightFire.h"
#include"TopFire.h"
#include"BotFire.h"
#include"TongueBot.h"
#include"TongueLeft.h"
#include"TongueTop.h"
#include"TongueRight.h"

class Game
{
private:
	static Game* game;
	sf::Image imageBlocks;
	sf::Texture textureBlocks;

	static float timeG;
	float moveSpeed;
	unsigned short bomb_coumt;
	unsigned short fireSize;
	int heroDirection;
	Player player1;
	bool live;
	Fone fone;
	Wall wall;
	Blocks *blocksIndestr;
	unsigned short blocksIndestrSize;
	std::vector<Blocks*> blocksDestr;
	std::vector<Bomb*> vBombs;
	std::vector<std::vector<Fire*>> vvFire;
	std::vector<Fire*> vFire;
	std::vector<Ruined*> vRuined;
	std::vector<Monster*> vMonsters;
	std::vector<DeathMonster*> vDeathMonster;
	int maxPosForDestrBlocks;
	int monstersCount;
	Door *door;
	Boost *boost;
	sf::Clock clock1;
	sf::Sprite sprBUff;
	const unsigned short LITTLE_BIT = 2; // для уникнення похибки накладдання спрайтів;
	bool death;
	DeathHero *deathHero;
	
	Game();
	
	std::vector<Fire*> getNewFire(int x, int y);
	

public:
	static Game* getInstance();
	void mainMethod();
};