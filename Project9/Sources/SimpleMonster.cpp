#include"../Headers/SimpleMonster.h"

SimpleMonster::SimpleMonster(Blocks * indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, sf::Image imgMonster)
{
	texture.loadFromImage(imgMonster);
	spriteMonster.setTexture(texture);
	spriteMonster.setTextureRect(sf::IntRect(0, 0, 66, 66));
	spriteMonster.setScale(UNIT_SIZE/66., UNIT_SIZE/66.);
	invSprite.setTextureRect(sf::IntRect(0, 0, UNIT_SIZE - 4, UNIT_SIZE - 4));
	setPosition(indestBlocksArr, sizeIndestBlocks, destBlocksV);
	currentFrame = 0;
	moveSpeed = 0.55;
	moveSide = rand() % 4;
}

SimpleMonster::~SimpleMonster()
{
}

void SimpleMonster::move(Blocks * indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, float time, std::vector<Bomb*> vBombs,  Wall & wall)
{
	movePossibility = 1;
	
	currentFrame += 0.045*time;
	if (currentFrame >= 4)
	{
		currentFrame = 0;
	}
	switch ((int)currentFrame)
	{
	case 0:
		spriteMonster.setTextureRect(sf::IntRect(0, 0, 66, 66));
		
		break;
	case 1:
		spriteMonster.setTextureRect(sf::IntRect(96, 0, 66, 66));
		break;
	case 2:
		spriteMonster.setTextureRect(sf::IntRect(0, 0, 66, 66));
		break;
	case 3:
		spriteMonster.setTextureRect(sf::IntRect(196, 0, 66, 66));
		break;
	default:
		break;
	}
	if (moveSide == 0)
	{

		spriteMonster.move(-moveSpeed*time, 0);
		invSprite.move(-moveSpeed*time, 0);
		if (getBounds().intersects(wall.getLeftBound()))
		{
			movePossibility = false;
		}
		else
		{
			for (int i = 0; i < sizeIndestBlocks; i++)
			{
				if (getBounds().intersects(indestBlocksArr[i].getBound()))
				{
					movePossibility = false;
					break;
				}
			}
			for (int i = 0; i < destBlocksV.size() && movePossibility == true; i++)
			{
				if (getBounds().intersects(destBlocksV.at(i)->getBound()))
				{
					movePossibility = false;
					break;
				}
			}
			for (int i = 0; i < Bomb::getCountBomb() && movePossibility == true; i++)
			{
				if (getBounds().intersects(vBombs[i]->getBounds()))
				{
					movePossibility = false;
					break;
				}
			}
		}
		if (movePossibility == false)
		{
			spriteMonster.move(moveSpeed*time, 0);
			invSprite.move(moveSpeed*time, 0);
			moveSide = rand() % 4;
		}
	}

	else if (moveSide == 1)
	{
		invSprite.move(moveSpeed*time, 0);
		spriteMonster.move(moveSpeed*time, 0);
		if (getBounds().intersects(wall.getRightBound()))
		{
			movePossibility = false;
		}
		else
		{
			for (int i = 0; i < sizeIndestBlocks; i++)
			{
				if (getBounds().intersects(indestBlocksArr[i].getBound()))
				{
					movePossibility = false;
					break;
				}
			}
			for (int i = 0; i < destBlocksV.size() && movePossibility == true; i++)
			{
				if (getBounds().intersects(destBlocksV.at(i)->getBound()))
				{
					movePossibility = false;
					break;
				}
			}
			for (int i = 0; i < Bomb::getCountBomb() && movePossibility == true; i++)
			{
				if (getBounds().intersects(vBombs[i]->getBounds()))
				{
					movePossibility = false;
					break;
				}
			}
		}
		if (movePossibility == false)
		{
			spriteMonster.move(-moveSpeed*time, 0);
			invSprite.move(-moveSpeed*time, 0);
			moveSide = rand() % 4;
		}

	}
	else if (moveSide == 2)
	{

		spriteMonster.move(0, moveSpeed*time);
		invSprite.move(0, moveSpeed*time);
		if (getBounds().intersects(wall.getDownBound()))
		{
			movePossibility = false;
		}
		else
		{
			for (int i = 0; i < sizeIndestBlocks; i++)
			{
				if (getBounds().intersects(indestBlocksArr[i].getBound()))
				{
					movePossibility = false;
					break;
				}
			}
			for (int i = 0; i < destBlocksV.size() && movePossibility == true; i++)
			{
				if (getBounds().intersects(destBlocksV.at(i)->getBound()))
				{
					movePossibility = false;
					break;
				}
			}
			for (int i = 0; i < Bomb::getCountBomb() && movePossibility == true; i++)
			{
				if (getBounds().intersects(vBombs[i]->getBounds()))
				{
					movePossibility = false;
					break;
				}
			}
		}
		if (movePossibility == false)
		{
			spriteMonster.move(0, -moveSpeed*time);
			invSprite.move(0, -moveSpeed*time);
			moveSide = rand() % 4;
		}
	}
	else if (moveSide == 3)
	{

		spriteMonster.move(0, -moveSpeed*time);
		invSprite.move(0, -moveSpeed*time);
		if (getBounds().intersects(wall.getUpBound()))
		{
			movePossibility = false;
		}
		else
		{
			for (int i = 0; i < sizeIndestBlocks; i++)
			{
				if (getBounds().intersects(indestBlocksArr[i].getBound()))
				{
					movePossibility = false;
					break;
				}
			}
			for (int i = 0; i < destBlocksV.size() && movePossibility == true; i++)
			{
				if (getBounds().intersects(destBlocksV.at(i)->getBound()))
				{
					movePossibility = false;
					break;
				}
			}
			for (int i = 0; i < Bomb::getCountBomb() && movePossibility == true; i++)
			{
				if (getBounds().intersects(vBombs[i]->getBounds()))
				{
					movePossibility = false;
					break;
				}
			}
		}
		if (movePossibility == false)
		{
			spriteMonster.move(0, moveSpeed*time);
			invSprite.move(0, moveSpeed*time);
			moveSide = rand() % 4;
			
		}
	}
}