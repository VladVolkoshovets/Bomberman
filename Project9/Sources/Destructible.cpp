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
		spriteBlocks->setPosition(2 * unitSize + unitSize * column, unitSize);
	}
	else if (i <= 89)
	{
		i -= 12;
		column = i % 13;
		row = (i / 13) * 2;
		spriteBlocks->setPosition(unitSize + unitSize * column, unitSize * 3 + unitSize*row);
	}
	else if (i <= 131)
	{
		i = i - 90;
		column = i % 7;
		row = i / 7;
		spriteBlocks->setPosition(unitSize + unitSize * 2 * column, unitSize * 2 + unitSize * 2 * row);
	}



	//11 - ������ ��� [1 . 11]
	//6*13  3 5 7 9 11 13 ��� [12, 90]
	//6*7  �������� �� ������ ���� �� 40 � + ��������� [91, 131]
}