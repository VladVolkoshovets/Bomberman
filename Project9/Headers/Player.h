#pragma once
#include<SFML\Graphics.hpp>
#include"Blocks.h"
#include"Bomb.h"
#include"Wall.h"
class  Hero
{
private:
	sf::Texture textureMain;
	sf::Sprite spriteHero;
	sf::Sprite spriteInvisible;
	float moveSpeed;
	unsigned short bombCount;
	float currentFrame;
	sf::FloatRect heroBounds;
	int spriteCount;
	bool needToReturn;
	const int MOVE_CORECTION = 20;
	void MoveUp(Blocks* indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, std::vector<Bomb*> vBombs, float time, Wall& wall);
	void MoveDown(Blocks* indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, std::vector<Bomb*> vBombs, float time, Wall& wall);
	void MoveLeft(Blocks* indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, std::vector<Bomb*> vBombs, float time, Wall& wall);
	void MoveRight(Blocks* indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, std::vector<Bomb*> vBombs, float time, Wall& wall);

public:
	Hero();
	~Hero();
	void setTexture(sf::Image);
	sf::Sprite GetSprite();
	sf::Sprite GetInvSprite();
	void setMS(float moveSpeed);
	void setBombCount(unsigned short bombCount);
	unsigned short getBombCount();
	void move(Blocks *indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, std::vector<Bomb*> vBombs, float time, Wall &wall);
};