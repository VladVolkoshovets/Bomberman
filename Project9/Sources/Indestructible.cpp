#include"../Headers/Indestructible.h"
void Indestructible::setPos(int i)
{
	short column = 0, row = 0;
	column = i % 6;
	row = i / 6;
	spriteBlocks->setPosition(80 + 80 * column, 80 + 80 * row);
}
Indestructible::Indestructible()
{
}