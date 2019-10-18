#include"../Headers/Player.h"
#include<iostream>






Player::Player()
{
	imageMain.loadFromFile("image.png");
	textureMain.loadFromImage(imageMain);
	spriteHero.setTexture(textureMain);
	spriteHero.setTextureRect(sf::IntRect(0, 0, 18, 21));
	spriteHero.setScale(sf::Vector2f(2.223, 2.239));

	spriteInvis.setTextureRect(sf::IntRect(0, 0, 18, 18));
	spriteInvis.setScale(sf::Vector2f(2.f, 2.f));
	currentFrame = 0;
	spriteCount = 0;
	spriteHero.setPosition(40, 33);
	spriteInvis.setPosition(42, 44);
	needToReturn = false;

}
Player::~Player()
{
}
sf::Sprite Player::GetSprite()
{
	return spriteHero;
}
sf::Sprite Player::GetInvSprite()
{
	return spriteInvis;
}
void Player::setMS(float moveSpeed)
{
	this->moveSpeed = moveSpeed;
}
void Player::setBombCount(unsigned short bombCount)
{
	this->bombCount = bombCount;
}
unsigned short Player::getBombCount()
{
	return bombCount;
}
void Player::MoveLeft(Blocks* indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, std::vector<Bomb*> vBombs, float time, Wall& wall)
{
	needToReturn = false;
	currentFrame += 0.1 * time;
	if (currentFrame >= 4)
	{
		currentFrame = 0;
	};
	if (int(currentFrame) == 2)
	{
		spriteCount = 2;
	}
	else if (int(currentFrame) == 3)
	{
		spriteCount = 1;
	}
	else
	{
		spriteCount = 0;
	}
	
	spriteHero.move(-moveSpeed * time, 0);
	spriteInvis.move(-moveSpeed * time, 0);
	heroBounds = spriteInvis.getGlobalBounds();
	if (heroBounds.intersects(wall.getLeftBound()))
	{
		needToReturn = true;
	}
	else
	{
		for (int i = 0; i < sizeIndestBlocks; i++)
		{

			if (heroBounds.intersects(indestBlocksArr[i].getBound()))
			{
				if (spriteInvis.getPosition().y + 24 < indestBlocksArr[i].getSprite().getPosition().y)								//is placed?
				{
					spriteHero.move(moveSpeed * time, 0);																			//remuving to right
					spriteInvis.move(moveSpeed * time, 0);
					MoveUp(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);										//placing
					std::cout << "Up!!" << std::endl;
					needToReturn = false;
					break;

				}
				else if (spriteInvis.getPosition().y - 24 > indestBlocksArr[i].getSprite().getPosition().y)
				{
					spriteHero.move(moveSpeed * time, 0);
					spriteInvis.move(moveSpeed * time, 0);
					MoveDown(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
					needToReturn = false;
					break;
				}
				else 
				{
					needToReturn = true;
					break;
				}
				
			}
		}
		spriteHero.setTextureRect(sf::IntRect(30, (int(currentFrame) - spriteCount) * 30, 18, 21));
		for (int i = 0; i < destBlocksV.size() && needToReturn == false; i++)
		{
			if (heroBounds.intersects(destBlocksV.at(i)->getBound()))
			{
				needToReturn = true;
			}
		}
		for (int i = 0; i < Bomb::getCountBomb() && needToReturn == false; i++)
		{
			if ((heroBounds.intersects(vBombs[i]->getBounds()) && vBombs[i]->getWentOut()) || (heroBounds.intersects(vBombs[i]->getInvBounds()) && vBombs[i]->getInvWentOut()))
			{
				needToReturn = true;
			}
		}
	}
	if (needToReturn == true)
	{
		spriteHero.move(moveSpeed * time, 0);
		spriteInvis.move(moveSpeed * time, 0);
	}
}
void Player::MoveRight(Blocks* indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, std::vector<Bomb*> vBombs, float time, Wall& wall)
{
	needToReturn = false;
	currentFrame += 0.1 * time;
	if (currentFrame >= 4)
	{
		currentFrame = 0;
	};
	if (int(currentFrame) == 2)
	{
		spriteCount = 2;
	}
	else if (int(currentFrame) == 3)
	{
		spriteCount = 1;
	}
	else
	{
		spriteCount = 0;
	}
	spriteHero.setTextureRect(sf::IntRect(90, (int(currentFrame) - spriteCount) * 30, 18, 21));
	spriteHero.move(moveSpeed * time, 0);
	spriteInvis.move(moveSpeed * time, 0);
	heroBounds = spriteInvis.getGlobalBounds();
	if (heroBounds.intersects(wall.getRightBound()))
	{
		needToReturn = true;
	}
	else
	{
		for (int i = 0; i < sizeIndestBlocks && needToReturn == false; i++)
		{
			if (heroBounds.intersects(indestBlocksArr[i].getBound()))
			{
				if (spriteInvis.getPosition().y + 24 < indestBlocksArr[i].getSprite().getPosition().y)
				{
					spriteHero.move(-moveSpeed * time, 0);
					spriteInvis.move(-moveSpeed * time, 0);
					MoveUp(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
					std::cout << "Up!!" << std::endl;
					needToReturn = false;
					break;

				}
				else if (spriteInvis.getPosition().y - 24 > indestBlocksArr[i].getSprite().getPosition().y)
				{
					spriteHero.move(-moveSpeed * time, 0);
					spriteInvis.move(-moveSpeed * time, 0);
					MoveDown(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
					needToReturn = false;
					break;
				}
				else
				{
					needToReturn = true;
					break;
				}
			}
		}
		for (int i = 0; i < destBlocksV.size() && needToReturn == false; i++)
		{
			if (heroBounds.intersects(destBlocksV.at(i)->getBound()))
			{
				needToReturn = true;
				break;
			}
		}
		for (int i = 0; i < Bomb::getCountBomb() && needToReturn == false; i++)
		{
			if ((heroBounds.intersects(vBombs[i]->getBounds()) && vBombs[i]->getWentOut()) || (heroBounds.intersects(vBombs[i]->getInvBounds()) && vBombs[i]->getInvWentOut()))
			{
				needToReturn = true;
				break;
			}
		}
	}
	if (needToReturn == true)
	{
		spriteHero.move(-moveSpeed * time, 0);
		spriteInvis.move(-moveSpeed * time, 0);
	}
}
void Player::MoveUp(Blocks* indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, std::vector<Bomb*> vBombs, float time, Wall& wall)
{
	needToReturn = false;
	currentFrame += 0.1 * time;
	if (currentFrame >= 4)
	{
		currentFrame = 0;
	};
	if (int(currentFrame) == 2)
	{
		spriteCount = 2;
	}
	else if (int(currentFrame) == 3)
	{
		spriteCount = 1;
	}
	else
	{
		spriteCount = 0;
	}
	spriteHero.setTextureRect(sf::IntRect(60, (int(currentFrame) - spriteCount) * 30, 18, 21));
	spriteHero.move(0, -moveSpeed * time);
	spriteInvis.move(0, -moveSpeed * time);
	heroBounds = spriteInvis.getGlobalBounds();
	if (heroBounds.intersects(wall.getUpBound()))
	{
		needToReturn = true;
	}
	else
	{
		for (int i = 0; i < sizeIndestBlocks; i++)
		{
			if (heroBounds.intersects(indestBlocksArr[i].getBound()))
			{
				if (spriteInvis.getPosition().x + 24 < indestBlocksArr[i].getSprite().getPosition().x)
				{
					spriteHero.move(0, moveSpeed * time);
					spriteInvis.move(0, moveSpeed * time);
					MoveLeft(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
					needToReturn = false;
					break;
				}
				else if (spriteInvis.getPosition().x - 24 > indestBlocksArr[i].getSprite().getPosition().x)
				{
					spriteHero.move(0, moveSpeed * time);
					spriteInvis.move(0, moveSpeed * time);
					MoveRight(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
					needToReturn = false;
					break;
				}
				else {
					needToReturn = true;
					break;
				}
				
			}
		}
		for (int i = 0; i < destBlocksV.size() && needToReturn == false; i++)
		{
			if (heroBounds.intersects(destBlocksV.at(i)->getBound()))
			{
				needToReturn = true;
				break;
			}
		}

		for (int i = 0; i < Bomb::getCountBomb() && needToReturn == false; i++)
		{
			if ((heroBounds.intersects(vBombs[i]->getBounds()) && vBombs[i]->getWentOut()) || (heroBounds.intersects(vBombs[i]->getInvBounds()) && vBombs[i]->getInvWentOut()))
			{
				needToReturn = true;
				break;
			}
		}
	}
	if (needToReturn == true)
	{
		spriteHero.move(0, moveSpeed * time);
		spriteInvis.move(0, moveSpeed * time);
	}
}

void Player::MoveDown(Blocks* indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, std::vector<Bomb*> vBombs, float time, Wall& wall)
{
	needToReturn = false;
	currentFrame += 0.1 * time;
	if (currentFrame >= 4)
	{
		currentFrame = 0;
	};
	if (int(currentFrame) == 2)
	{
		spriteCount = 2;
	}
	else if (int(currentFrame) == 3)
	{
		spriteCount = 1;
	}
	else
	{
		spriteCount = 0;
	}
	spriteHero.setTextureRect(sf::IntRect(0, (int(currentFrame) - spriteCount) * 30, 18, 21));
	spriteHero.move(0, moveSpeed * time);
	spriteInvis.move(0, moveSpeed * time);
	heroBounds = spriteInvis.getGlobalBounds();
	if (heroBounds.intersects(wall.getDownBound()))
	{
		needToReturn = true;
	}
	else
	{
		for (int i = 0; i < sizeIndestBlocks && needToReturn == false; i++)
		{
			if (heroBounds.intersects(indestBlocksArr[i].getBound()))
			{
				if (spriteInvis.getPosition().x + 24 < indestBlocksArr[i].getSprite().getPosition().x)
				{
					spriteHero.move(0, -moveSpeed * time);
					spriteInvis.move(0, -moveSpeed * time);
					MoveLeft(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
					needToReturn = false;
					break;
				}
				else if (spriteInvis.getPosition().x - 24 > indestBlocksArr[i].getSprite().getPosition().x)
				{
					spriteHero.move(0, -moveSpeed * time);
					spriteInvis.move(0, -moveSpeed * time);
					MoveRight(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
					needToReturn = false;
					break;
				}
				else {
					needToReturn = true;
					break;
				}
			}
		}
		for (int i = 0; i < destBlocksV.size() && needToReturn == false; i++)
		{
			if (heroBounds.intersects(destBlocksV.at(i)->getBound()))
			{
				needToReturn = true;
				break;
			}
		}
		for (int i = 0; i < Bomb::getCountBomb() && needToReturn == false; i++)
		{
			if ((heroBounds.intersects(vBombs[i]->getBounds()) && vBombs[i]->getWentOut()) || (heroBounds.intersects(vBombs[i]->getInvBounds()) && vBombs[i]->getInvWentOut()))
			{
				needToReturn = true;
				break;
			}
		}
	}
	if (needToReturn == true)
	{
		spriteHero.move(0, -moveSpeed * time);
		spriteInvis.move(0, -moveSpeed * time);
	}
}
void Player::move(Blocks * indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, std::vector<Bomb*> vBombs, float time, Wall & wall)
{

	needToReturn = true;
	heroBounds = spriteInvis.getGlobalBounds();
	for (int i = 0; i < Bomb::getCountBomb(); i++)
	{
		if (!vBombs[i]->getWentOut() && !heroBounds.intersects(vBombs[i]->getBounds()))
		{
			vBombs[i]->setWentOut(true);
		}
	}
	for (int i = 0; i < Bomb::getCountBomb(); i++)
	{
		if (!vBombs[i]->getInvWentOut() && !heroBounds.intersects(vBombs[i]->getInvBounds()))
		{
			vBombs[i]->setInvWentOut(true);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		MoveLeft(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		MoveRight(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		MoveDown(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		MoveUp(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
	}

}