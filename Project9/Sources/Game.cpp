
#include "..\Headers\Game.h"
#include<iostream>
float Game::timeGame = 0;
Game *Game::game = nullptr;
Game::Game()
{
	
	
}
Game* Game::getInstance()
{
	if (game == nullptr)
	{
		std::cout << "Creation of Singleton " << std::endl;
		return game = new Game();
	}
	return game;
}
void Game::setGameParameters()
{
	// Load resources
	imageBlocks.loadFromFile("blocks.png");
	imgRuined.loadFromFile("ruined.png");
	imageFone.loadFromFile("fone2.png");
	imageHero.loadFromFile("image.png");
	imageBomb.loadFromFile("bomb.png");
	imgBoost.loadFromFile("bigBoom.png");

	fone.setTexture(imageFone);
	player.setTexture(imageHero);
	
	textureBlocks.loadFromImage(imageBlocks);
	
	sprFire.setTextureRect(sf::IntRect(0, 0, UNIT_SIZE - LITTLE_BIT * 2, UNIT_SIZE - LITTLE_BIT * 2));

	// Create window. Set parameters
	window.create(sf::VideoMode(600, 600), "Bomberman");
	window.setFramerateLimit(60);
	srand(time(0));
}
void Game::setLevelParameters()
{
	blocksIndestrSize = 36;
	moveSpeed = 1.3;
	bombÑount = 2;
	fireSize = 1;
	monstersCount = 5;
	maxPosForDestrBlocks = 131;
	deathHero = nullptr;

	// set indestructible blocks
	blocksIndestr = new Indestructible[blocksIndestrSize];
	for (int i = 0; i < blocksIndestrSize; i++)
	{
		blocksIndestr[i] = Indestructible(i, &textureBlocks);
	}


	// set destructible blocks
	for (int i = 0, pos = 1; pos <= maxPosForDestrBlocks; i++)
	{
		if (rand() % 2 == 0)
		{
			pos++;
		}
		if (rand() % 3 == 0)
		{
			pos++;
		}
		pos++;
		blocksDestr.push_back(new Destructible(&textureBlocks, pos));
	}
	// rand pos for dors behind block, set it;
	int* numbBlockForDor = new int;
	*numbBlockForDor = rand() % blocksDestr.size();
	door = new Door(blocksDestr.at(*numbBlockForDor)->getSprite().getPosition().x, blocksDestr.at(*numbBlockForDor)->getSprite().getPosition().y);

	// rand pos for boost behind block, set it;
	int* numbBlockForBoost = new int;
	do {
		*numbBlockForBoost = rand() % blocksDestr.size();
	} while (*numbBlockForDor == *numbBlockForBoost);
	boost = new Boost(blocksDestr.at(*numbBlockForBoost)->getSprite().getPosition().x, blocksDestr.at(*numbBlockForBoost)->getSprite().getPosition().y, imgBoost);
	delete numbBlockForDor, numbBlockForBoost;

	// set monsters;
	vMonsters.clear();
	for (int i = 0; i < monstersCount; i++)
	{
		vMonsters.push_back(new SimpleMonster(blocksIndestr, blocksIndestrSize, blocksDestr));
	}

	// set player characteristics
	player.setMS(moveSpeed);
	player.setBombCount(bombÑount);
	isAlive = true;
};
 std::vector<Fire*> Game::getNewFire(int x, int y)
{
	
	//fire centr
	int fireX = x, fireY = y;
	bool possibility = true;
	vFire.clear();
	vFire.push_back(new MainFire(x, y));
	//fire right
	for (int i = 0; i < fireSize; i++)
	{
		fireX += UNIT_SIZE;

		sprFire.setPosition(fireX + LITTLE_BIT, fireY + LITTLE_BIT);
		if (sprFire.getGlobalBounds().intersects(wall.getRightBound()))
		{
			break;
		}
		for (int j = 0; j < blocksIndestrSize; j++)
		{
			if (sprFire.getGlobalBounds().intersects(blocksIndestr[j].getBound()))
			{
				possibility = false;
				break;
			}
		}
		if (possibility == false)
		{
			break;
		}
		for (int j = 0; j < blocksDestr.size(); j++)
		{
			if (sprFire.getGlobalBounds().intersects(blocksDestr.at(j)->getBound()))
			{
				vRuined.push_back(new Ruined(blocksDestr.at(j)->getSprite().getPosition().x, blocksDestr.at(j)->getSprite().getPosition().y, imgRuined));
				delete blocksDestr.at(j);
				blocksDestr.erase(blocksDestr.begin() + j);
				j--;
				possibility = false;
				break;
			}
		}
		if (possibility == false)
		{
			break;
		}

		if (fireSize - 1 != i)
		{
			vFire.push_back(new RightFire(fireX, fireY));
		}
		else
		{
			vFire.push_back(new TongueRight(fireX, fireY));
		}
	}
	//fire left
	fireX = x;
	possibility = true;
	for (int i = 0; i < fireSize; i++)
	{
		fireX -= UNIT_SIZE;

		sprFire.setPosition(fireX + LITTLE_BIT, fireY + LITTLE_BIT);
		if (sprFire.getGlobalBounds().intersects(wall.getLeftBound()))
		{
			break;
		}
		for (int j = 0; j < blocksIndestrSize; j++)
		{
			if (sprFire.getGlobalBounds().intersects(blocksIndestr[j].getBound()))
			{
				possibility = false;
				break;
			}
		}
		if (possibility == false)
		{
			break;
		}
		for (int j = 0; j < blocksDestr.size(); j++)
		{
			if (sprFire.getGlobalBounds().intersects(blocksDestr.at(j)->getBound()))
			{
				vRuined.push_back(new Ruined(blocksDestr.at(j)->getSprite().getPosition().x, blocksDestr.at(j)->getSprite().getPosition().y, imgRuined));
				delete blocksDestr.at(j);
				blocksDestr.erase(blocksDestr.begin() + j);
				j--;
				possibility = false;
				break;
			}
		}
		if (possibility == false)
		{
			break;
		}

		if (fireSize - 1 != i)
		{
			vFire.push_back(new LeftFire(fireX, y));
		}
		else
		{
			vFire.push_back(new TongueLeft(fireX, y));
		}
	}
	//fire top
	fireX = x;
	possibility = true;
	for (int i = 0; i < fireSize; i++)
	{
		fireY -= UNIT_SIZE;
		sprFire.setPosition(fireX + LITTLE_BIT, fireY + LITTLE_BIT);
		if (sprFire.getGlobalBounds().intersects(wall.getUpBound()))
		{
			break;
		}
		for (int j = 0; j < blocksIndestrSize; j++)
		{
			if (sprFire.getGlobalBounds().intersects(blocksIndestr[j].getBound()))
			{
				possibility = false;
				break;
			}
		}
		if (possibility == false)
		{
			break;
		}
		for (int j = 0; j < blocksDestr.size(); j++)
		{
			if (sprFire.getGlobalBounds().intersects(blocksDestr.at(j)->getBound()))
			{
				vRuined.push_back(new Ruined(blocksDestr.at(j)->getSprite().getPosition().x, blocksDestr.at(j)->getSprite().getPosition().y, imgRuined));
				delete blocksDestr.at(j);
				blocksDestr.erase(blocksDestr.begin() + j);
				possibility = false;
				break;
			}
		}
		if (possibility == false)
		{
			break;
		}

		if (fireSize - 1 != i)
		{
			vFire.push_back(new TopFire(x, fireY));
		}
		else
		{
			vFire.push_back(new TongueTop(x, fireY));
		}
	}
	//fire bot
	fireY = y;
	possibility = true;
	for (int i = 0; i < fireSize; i++)
	{
		fireY += UNIT_SIZE;
		sprFire.setPosition(fireX + LITTLE_BIT, fireY + LITTLE_BIT);
		if (sprFire.getGlobalBounds().intersects(wall.getDownBound()))
		{
			break;
		}
		for (int j = 0; j < blocksIndestrSize; j++)
		{
			if (sprFire.getGlobalBounds().intersects(blocksIndestr[j].getBound()))
			{
				possibility = false;
				break;
			}
		}
		if (possibility == false)
		{
			break;
		}
		for (int j = 0; j < blocksDestr.size(); j++)
		{
			if (sprFire.getGlobalBounds().intersects(blocksDestr.at(j)->getBound()))
			{
				vRuined.push_back(new Ruined(blocksDestr.at(j)->getSprite().getPosition().x, blocksDestr.at(j)->getSprite().getPosition().y, imgRuined));
				delete blocksDestr.at(j);
				blocksDestr.erase(blocksDestr.begin() + j);
				j--;
				possibility = false;
				break;
			}
		}
		if (possibility == false)
		{
			break;
		}
		if (fireSize - 1 != i)
		{
			vFire.push_back(new BotFire(fireX, fireY));
		}
		else
		{
			vFire.push_back(new TongueBot(fireX, fireY));
		}
	}
	return vFire;
}


 void Game::mainMethod()
{



	setGameParameters();
	setLevelParameters();


	// Main game cycle
	while (window.isOpen())
	{
		// Set time(game speed)
		timeGame = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		timeGame = timeGame / 10000;

		sf::Event Event;
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
				window.close();
		}

		// Logic
		// Move hero and bomb placing
		if (isAlive == true)
		{
			player.move(blocksIndestr, blocksIndestrSize, blocksDestr, vBombs, timeGame, wall);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
			{
				if ((Bomb::getCountBomb() == 0) || (Bomb::getCountBomb() < player.getBombCount() && !player.GetInvSprite().getGlobalBounds().intersects(vBombs.back()->getBounds())))
				{
					vBombs.push_back(new Bomb(player.GetInvSprite().getPosition().x, player.GetInvSprite().getPosition().y, imageBomb));
				}
			}
		}
		// Fire + bomb
		if (!vvFire.empty())  
		{
			for (size_t k = 0; k < vvFire.size(); k++)
			{
				for (size_t i = 0; i < vvFire.at(k).size(); i++)
				{
					for (size_t j = 0; j < vBombs.size(); j++)
					{
						if (vvFire.at(k).at(i)->getSprite().getGlobalBounds().intersects(vBombs.at(j)->getInvBounds()))
						{
							vBombs.at(j)->setTime(3);

							break;
						}
					}
				}
			}
		}
		// Fire + Hero
		if (!vvFire.empty()) 
		{
			for (size_t k = 0; k < vvFire.size(); k++)
			{
				for (size_t i = 0; i < vvFire.at(k).size(); i++)
				{
					if (vvFire.at(k).at(i)->getSprite().getGlobalBounds().intersects(player.GetInvSprite().getGlobalBounds()))
					{
						isAlive = false;
						break;
					}
				}
			}
		}
		for (int i = 0; i < vMonsters.size(); i++)
		{
			if (vMonsters.at(i)->getBounds().intersects(player.GetInvSprite().getGlobalBounds()))
			{
				isAlive = false;
				break;
			}
		}
		if (deathHero == nullptr && isAlive == false)
		{
			deathHero = new DeathHero(player.GetInvSprite().getPosition().x, player.GetInvSprite().getPosition().y);

		}
		// Draw
		window.clear(sf::Color::Black);
		window.draw(fone.getSprite());
		for (int i = 0; i < blocksIndestrSize; i++)
		{
			window.draw(blocksIndestr[i].getSprite());
		}
		window.draw(door->getSprite());
		if (boost)
		{
			window.draw(boost->getSprite());
			if (player.GetInvSprite().getGlobalBounds().intersects(boost->getBound()))
			{
				delete boost;
				boost = nullptr;
				fireSize++;
			}

		}
		for (int i = 0; i < blocksDestr.size(); i++)
		{
			window.draw(blocksDestr.at(i)->getSprite());

		}
		window.draw(wall.getSpriteUp());
		window.draw(wall.getSpriteLeft());
		if (deathHero == nullptr)
		{
			window.draw(player.GetSprite());
		}
		window.draw(wall.getSpriteDown());
		window.draw(wall.getSpriteRight());
		// Bomb animation
		for (int i = 0; i < vBombs.size(); i++)
		{
			if (!vBombs[i]->isBombAlive(timeGame))
			{
				vvFire.push_back(getNewFire(vBombs[i]->getSprite().getPosition().x, vBombs[i]->getSprite().getPosition().y));
				delete vBombs[i];
				vBombs.erase(vBombs.begin() + i);
			}
			else
			{
				window.draw(vBombs[i]->getSprite());
			}
		}
		// Fire! Abd animation!
		for (int i = 0; i < vvFire.size(); i++)
		{
			if (vvFire[i].at(0)->fireInTheHall())
			{
				for (int j = 0; j < vvFire[i].size(); j++)
				{
					window.draw(vvFire[i].at(j)->getSprite());
				}
			}
			else
			{
				for (int j = 0; j < vvFire.at(i).size(); j++)
				{
					delete vvFire[i].at(j);
					vvFire[i].erase(vvFire[i].begin() + j);
				}
				vvFire.erase(vvFire.begin() + i);

			}

		}
		// Extermination! And animation
		for (int i = 0; i < vRuined.size(); i++)
		{
			if (!vRuined[i]->destruction())
			{

				delete vRuined[i];
				vRuined.erase(vRuined.begin() + i);

			}
			else
			{
				window.draw(vRuined[i]->getSprite());
			}
		}
		// Monster move and death
		if (!vMonsters.empty())
		{
			for (size_t j = 0; j < vMonsters.size(); j++)
			{
				death = false;
				if (!vvFire.empty())
				{
					for (size_t k = 0; !death && k < vvFire.size(); k++)
					{
						for (size_t i = 0; !death && i < vvFire.at(k).size(); i++)
						{
							if (vvFire.at(k).at(i)->getSprite().getGlobalBounds().intersects(vMonsters.at(j)->getBounds()))
							{
								vDeadMonster.push_back(new DeathSimpleMomster(vMonsters.at(j)->getSprite().getPosition().x, vMonsters.at(j)->getSprite().getPosition().y));
								delete vMonsters.at(j);
								vMonsters.erase(vMonsters.begin() + j);
								death = true;
								break;
							}
						}

					}
				}
				if (!death)
				{
					vMonsters.at(j)->move(blocksIndestr, blocksIndestrSize, blocksDestr, timeGame, vBombs, wall);
					window.draw(vMonsters.at(j)->getSprite());
				}
			}

		}
		// Drow dead monster
		if (!vDeadMonster.empty()) 
		{	
			for (int i = 0; i < vDeadMonster.size(); i++)
			{
				if (vDeadMonster.at(i)->sweetDeath())
				{
					window.draw(vDeadMonster.at(i)->getSprite());
				}
				else
				{
					delete vDeadMonster.at(i);
					vDeadMonster.erase(vDeadMonster.begin() + i);
					break;
				}

			}
		}
		// Drow dead hero
		if (deathHero != nullptr)
		{
			window.draw(deathHero->getSprite());
		}
		if (deathHero != nullptr && !deathHero->bitterDeath())
		{
			std::cout << "tyt/n";
			system("pause");
			door->~Door();
			break;
		}
		// Level won
		if (player.GetInvSprite().getGlobalBounds().intersects(door->getBound()) && vMonsters.empty())
		{
			// next lvl
			break;
		}
		window.display();
	}

}