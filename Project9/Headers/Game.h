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
	sf::Image imgBlocks;
	sf::Image imgRuined;
	sf::Image imgFone;
	sf::Image imgHero;
	sf::Image imgBomb;
	sf::Image imgBoost;
	sf::Image imgWall;
	sf::Image imgFire;
	sf::Image imgMonster;
	sf::Image imgDeathMonster;
	sf::Texture textureBlocks;
	static float timeElapsed;
	unsigned short gameSpeed;
	float moveSpeed;
	unsigned short bomb—ount;
	unsigned short fireSize;
	Fone fone;
	Wall wall;
	Blocks *blocksIndestr;
	unsigned short blocksIndestrAmount;
	std::vector<Blocks*> vBlocksDestr;
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
	Player hero;
	bool isHeroAlive;
	bool isGameOver;

	bool isLevelCompleted;
	DeathHero *deathHero;
	sf::Event windowEvent;
	bool loadingResources();
	void setGameParameters();
	void setFirstLevelParameters();
	void setSecondLevelParameters();
	void levelGeneration();
	void levelDestructor();

	// Binding to time
	void timeBound();

	// Return false if window was closed
	bool isWidowOpen();

	// handles game logic, works with any levels
	void logic();

	// Draw and display everything in the game, works with any levels
	void draw();

	// Main game cycle, works with any levels
	void gameCycle();

	// Creates instances of classes of flames, and checks this possibility
	// Calling after bomb detonation, in the same position
	std::vector<Fire*> getNewFire(int x, int y);

public:
	static Game* getInstance();
	void mainMethod();
};