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
	Game();
	static Game* game;
	sf::RenderWindow window;
	sf::Image imageBlocks;
	sf::Image imgRuined;
	sf::Image imageFone;
	sf::Image imageHero;
	sf::Image imageBomb;
	sf::Image imgBoost;
	sf::Texture textureBlocks;
	static float timeGame;
	float moveSpeed;
	unsigned short bomb—ount;
	unsigned short fireSize;
	Player player;
	bool isAlive;
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
	std::vector<DeathMonster*> vDeadMonster;
	int maxPosForDestrBlocks;
	int monstersCount;
	Door *door;
	Boost *boost;
	sf::Clock clock;
	sf::Sprite sprFire;
	bool death;
	DeathHero *deathHero;
	sf::Event Event;
	
	void setGameParameters();
	void setLevelParameters();
	
	std::vector<Fire*> getNewFire(int x, int y);
	

public:
	static Game* getInstance();
	void mainMethod();
};