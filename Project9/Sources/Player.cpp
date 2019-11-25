#include"../Headers/Player.h"

Player::Player()
{
	spriteHero.setTexture(textureMain);
	spriteHero.setTextureRect(sf::IntRect(0, 0, 18, 21));
	spriteHero.setScale(sf::Vector2f(2.223, 2.239));
	spriteInvisible.setTextureRect(sf::IntRect(0, 0, 18, 18));
	spriteInvisible.setScale(sf::Vector2f(2.f, 2.f));
	currentFrame = 0;
	spriteCount = 0;
	spriteHero.setPosition(40, 33);
	spriteInvisible.setPosition(42, 44);
	needToReturn = false;
}
Player::~Player()
{
}
void Player::setTexture(sf::Image imageHero)
{
	textureMain.loadFromImage(imageHero);
}
sf::Sprite Player::GetSprite()
{
	return spriteHero;
}
sf::Sprite Player::GetInvSprite()
{
	return spriteInvisible;
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
	// Animation
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
	
	// Moving
	spriteHero.move(-moveSpeed * time, 0);
	spriteInvisible.move(-moveSpeed * time, 0);
	heroBounds = spriteInvisible.getGlobalBounds();
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
				// Move. If the hero is not located between blocks, corrects
				if (spriteInvisible.getPosition().y + MOVE_CORECTION < indestBlocksArr[i].getSprite().getPosition().y)								
				{
					spriteHero.move(moveSpeed * time, 0);																			
					spriteInvisible.move(moveSpeed * time, 0);
					MoveUp(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);										
					needToReturn = false;
					break;

				}
				else if (spriteInvisible.getPosition().y - MOVE_CORECTION > indestBlocksArr[i].getSprite().getPosition().y)
				{
					spriteHero.move(moveSpeed * time, 0);
					spriteInvisible.move(moveSpeed * time, 0);
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
			if ((heroBounds.intersects(vBombs[i]->getBounds()) && vBombs[i]->getIsTimeWentOut()) || (heroBounds.intersects(vBombs[i]->getInvBounds()) && vBombs[i]->getInvisibleWentOut()))
			{
				needToReturn = true;
			}
		}
	}
	if (needToReturn == true)
	{
		spriteHero.move(moveSpeed * time, 0);
		spriteInvisible.move(moveSpeed * time, 0);
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
	spriteInvisible.move(moveSpeed * time, 0);
	heroBounds = spriteInvisible.getGlobalBounds();
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
				if (spriteInvisible.getPosition().y + MOVE_CORECTION < indestBlocksArr[i].getSprite().getPosition().y)
				{
					spriteHero.move(-moveSpeed * time, 0);
					spriteInvisible.move(-moveSpeed * time, 0);
					MoveUp(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
					needToReturn = false;
					break;

				}
				else if (spriteInvisible.getPosition().y - MOVE_CORECTION > indestBlocksArr[i].getSprite().getPosition().y)
				{
					spriteHero.move(-moveSpeed * time, 0);
					spriteInvisible.move(-moveSpeed * time, 0);
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
			if ((heroBounds.intersects(vBombs[i]->getBounds()) && vBombs[i]->getIsTimeWentOut()) || (heroBounds.intersects(vBombs[i]->getInvBounds()) && vBombs[i]->getInvisibleWentOut()))
			{
				needToReturn = true;
				break;
			}
		}
	}
	if (needToReturn == true)
	{
		spriteHero.move(-moveSpeed * time, 0);
		spriteInvisible.move(-moveSpeed * time, 0);
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
	spriteInvisible.move(0, -moveSpeed * time);
	heroBounds = spriteInvisible.getGlobalBounds();
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
				if (spriteInvisible.getPosition().x + MOVE_CORECTION < indestBlocksArr[i].getSprite().getPosition().x)
				{
					spriteHero.move(0, moveSpeed * time);
					spriteInvisible.move(0, moveSpeed * time);
					MoveLeft(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
					needToReturn = false;
					break;
				}
				else if (spriteInvisible.getPosition().x - MOVE_CORECTION > indestBlocksArr[i].getSprite().getPosition().x)
				{
					spriteHero.move(0, moveSpeed * time);
					spriteInvisible.move(0, moveSpeed * time);
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
			if ((heroBounds.intersects(vBombs[i]->getBounds()) && vBombs[i]->getIsTimeWentOut()) || (heroBounds.intersects(vBombs[i]->getInvBounds()) && vBombs[i]->getInvisibleWentOut()))
			{
				needToReturn = true;
				break;
			}
		}
	}
	if (needToReturn == true)
	{
		spriteHero.move(0, moveSpeed * time);
		spriteInvisible.move(0, moveSpeed * time);
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
	spriteInvisible.move(0, moveSpeed * time);
	heroBounds = spriteInvisible.getGlobalBounds();
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
				if (spriteInvisible.getPosition().x + MOVE_CORECTION < indestBlocksArr[i].getSprite().getPosition().x)
				{
					spriteHero.move(0, -moveSpeed * time);
					spriteInvisible.move(0, -moveSpeed * time);
					MoveLeft(indestBlocksArr, sizeIndestBlocks, destBlocksV, vBombs, time, wall);
					needToReturn = false;
					break;
				}
				else if (spriteInvisible.getPosition().x - MOVE_CORECTION > indestBlocksArr[i].getSprite().getPosition().x)
				{
					spriteHero.move(0, -moveSpeed * time);
					spriteInvisible.move(0, -moveSpeed * time);
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
			if ((heroBounds.intersects(vBombs[i]->getBounds()) && vBombs[i]->getIsTimeWentOut()) || (heroBounds.intersects(vBombs[i]->getInvBounds()) && vBombs[i]->getInvisibleWentOut()))
			{
				needToReturn = true;
				break;
			}
		}
	}
	if (needToReturn == true)
	{
		spriteHero.move(0, -moveSpeed * time);
		spriteInvisible.move(0, -moveSpeed * time);
	}
}
void Player::move(Blocks * indestBlocksArr, unsigned short sizeIndestBlocks, std::vector<Blocks*> destBlocksV, std::vector<Bomb*> vBombs, float time, Wall & wall)
{

	needToReturn = true;
	heroBounds = spriteInvisible.getGlobalBounds();
	for (int i = 0; i < Bomb::getCountBomb(); i++)
	{
		if (!vBombs[i]->getIsTimeWentOut() && !heroBounds.intersects(vBombs[i]->getBounds()))
		{
			vBombs[i]->setIsTimeWentOut(true);
		}
	}
	for (int i = 0; i < Bomb::getCountBomb(); i++)
	{
		if (!vBombs[i]->getInvisibleWentOut() && !heroBounds.intersects(vBombs[i]->getInvBounds()))
		{
			vBombs[i]->setInvisibleWentOut(true);
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
void Player::setDefaultPosition()
{
	spriteHero.setPosition(40, 33);
	spriteInvisible.setPosition(42, 44);
}