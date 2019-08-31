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
	greenZone.setTextureRect(sf::IntRect(0, 0, unitSize*4, unitSize*4));
	greenZone.setPosition(unitSize, unitSize);
	int x, y;
	bool seted;
	
	do
	{
		seted = 1;
		x = rand() % 13;
		y = rand() % 13;
		invSprite.setPosition(unitSize + unitSize * x + 2, unitSize + unitSize * y + 2);
		for (size_t i = 0; i < sizeIndestBlocks; i++)
		{
			if (invSprite.getGlobalBounds().intersects(indestBlocksArr[i].getBound()))
			{
				seted = 0;
				break;
			}
		}
		if (seted == 1)
		{
			for (size_t i = 0; i < destBlocksV.size(); i++)
			{
				if (invSprite.getGlobalBounds().intersects(destBlocksV.at(i)->getBound()))
				{
					seted = 0;
					break;
				}
			}
		}
		if (seted == 1 && invSprite.getGlobalBounds().intersects(greenZone.getGlobalBounds()))
		{
			seted = 0;
		}
	
	} while (seted == false);
	spriteMonster.setPosition(unitSize + unitSize*x, unitSize + unitSize*y);
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