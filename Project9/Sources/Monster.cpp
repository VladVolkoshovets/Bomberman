#include"../Headers/Monster.h"
Monster::Monster()
{
}

Monster::~Monster()
{
}
void Monster::setPosition(Blocks * indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV)
{
	sf::Sprite greenZone;
	greenZone.setTextureRect(sf::IntRect(0, 0, UNIT_SIZE*4, UNIT_SIZE*4));
	greenZone.setPosition(UNIT_SIZE, UNIT_SIZE);
	int x, y;
	bool isSeted;
	
	do
	{
		isSeted = true;
		x = rand() % 13;
		y = rand() % 13;
		invSprite.setPosition(UNIT_SIZE + UNIT_SIZE * x + 2, UNIT_SIZE + UNIT_SIZE * y + 2);
		for (size_t i = 0; i < sizeIndestBlocks; i++)
		{
			if (invSprite.getGlobalBounds().intersects(indestBlocksArr[i].getBound()))
			{
				isSeted = 0;
				break;
			}
		}
		if (isSeted == 1)
		{
			for (size_t i = 0; i < destBlocksV.size(); i++)
			{
				if (invSprite.getGlobalBounds().intersects(destBlocksV.at(i)->getBound()))
				{
					isSeted = 0;
					break;
				}
			}
		}
		if (isSeted == 1 && invSprite.getGlobalBounds().intersects(greenZone.getGlobalBounds()))
		{
			isSeted = 0;
		}
	
	} while (isSeted == false);
	spriteMonster.setPosition(UNIT_SIZE + UNIT_SIZE*x, UNIT_SIZE + UNIT_SIZE*y);
}
sf::Sprite Monster::getSprite()
{
	return spriteMonster;
}

sf::FloatRect Monster::getBounds()
{
	return invSprite.getGlobalBounds();
}

unsigned short Monster::monsterCount = 0;