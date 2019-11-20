#include"../Headers/Destructible.h"
Destructible::Destructible() {}
Destructible::Destructible(sf::Texture *textureBlocks, int counter)
{
	spriteBlocks->setTexture(*textureBlocks);
	spriteBlocks->setTextureRect(sf::IntRect(88, 0, 66, 66));
	spriteBlocks->setScale(sf::Vector2f(0.61f, 0.61f));
	setPos(counter);
	blockBounds = spriteBlocks->getGlobalBounds();
}
Destructible::~Destructible()
{
	delete spriteBlocks;
}
void Destructible::setPos(int i)
{
	short column = 0, row = 0;
	if (i <= 11)
	{
		column = i;
		spriteBlocks->setPosition(2 * UNIT_SIZE + UNIT_SIZE * column, UNIT_SIZE);
	}
	else if (i <= 89)
	{
		i -= 12;
		column = i % 13;
		row = (i / 13) * 2;
		spriteBlocks->setPosition(UNIT_SIZE + UNIT_SIZE * column, UNIT_SIZE * 3 + UNIT_SIZE*row);
	}
	else if (i <= 131)
	{
		i = i - 90;
		column = i % 7;
		row = i / 7;
		spriteBlocks->setPosition(UNIT_SIZE + UNIT_SIZE * 2 * column, UNIT_SIZE * 2 + UNIT_SIZE * 2 * row);
	}



	//11 - перший ряд [1 . 11]
	//6*13  3 5 7 9 11 13 ряд [12, 90]
	//6*7  алгоритм як зверху лівіше на 40 і + стовепець [91, 131]
}