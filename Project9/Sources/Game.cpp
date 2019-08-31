
#include "..\Headers\Game.h"

float Game::timeG = 0;
Game *Game::game = nullptr;
Game::Game()
{
	blocksIndestrSize = 36;

	imageBlocks.loadFromFile("blocks.png");
	textureBlocks.loadFromImage(imageBlocks);

	moveSpeed = 1.3;
	bombCoumt = 3;
	fireSize = 2;
	monstersCount = 5;
	heroDirection = 0;
	deathHero = nullptr;
	sprBUff.setTextureRect(sf::IntRect(0, 0, unitSize - aLittleBit * 2, unitSize - aLittleBit * 2));
}
 std::vector<Fire*> Game::getNewFire(int x, int y)
{
	//fire centr
	int buffX = x, buffY = y;
	bool possibility = 1;
	vFire.clear();
	vFire.push_back(new MainFire(x, y));
	//fire right
	for (int i = 0; i < fireSize; i++)
	{
		buffX += unitSize;

		sprBUff.setPosition(buffX + aLittleBit, buffY + aLittleBit);
		if (sprBUff.getGlobalBounds().intersects(wall.getRightBound()))
		{
			break;
		}
		for (int j = 0; j < blocksIndestrSize; j++)
		{
			if (sprBUff.getGlobalBounds().intersects(blocksIndestr[j].getBound()))
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
			if (sprBUff.getGlobalBounds().intersects(blocksDestr.at(j)->getBound()))
			{
				vRuined.push_back(new Ruined(blocksDestr.at(j)->getSprite().getPosition().x, blocksDestr.at(j)->getSprite().getPosition().y));
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
			vFire.push_back(new RightFire(buffX, buffY));
		}
		else
		{
			vFire.push_back(new TongueRight(buffX, buffY));
		}
	}
	//fire left
	buffX = x;
	possibility = true;
	for (int i = 0; i < fireSize; i++)
	{
		buffX -= unitSize;

		sprBUff.setPosition(buffX + aLittleBit, buffY + aLittleBit);
		if (sprBUff.getGlobalBounds().intersects(wall.getLeftBound()))
		{
			break;
		}
		for (int j = 0; j < blocksIndestrSize; j++)
		{
			if (sprBUff.getGlobalBounds().intersects(blocksIndestr[j].getBound()))
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
			if (sprBUff.getGlobalBounds().intersects(blocksDestr.at(j)->getBound()))
			{
				vRuined.push_back(new Ruined(blocksDestr.at(j)->getSprite().getPosition().x, blocksDestr.at(j)->getSprite().getPosition().y));
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
			vFire.push_back(new LeftFire(buffX, y));
		}
		else
		{
			vFire.push_back(new TongueLeft(buffX, y));
		}
	}
	//fire top
	buffX = x;
	possibility = true;
	for (int i = 0; i < fireSize; i++)
	{
		buffY -= unitSize;
		sprBUff.setPosition(buffX + aLittleBit, buffY + aLittleBit);
		if (sprBUff.getGlobalBounds().intersects(wall.getUpBound()))
		{
			break;
		}
		for (int j = 0; j < blocksIndestrSize; j++)
		{
			if (sprBUff.getGlobalBounds().intersects(blocksIndestr[j].getBound()))
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
			if (sprBUff.getGlobalBounds().intersects(blocksDestr.at(j)->getBound()))
			{
				vRuined.push_back(new Ruined(blocksDestr.at(j)->getSprite().getPosition().x, blocksDestr.at(j)->getSprite().getPosition().y));
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
			vFire.push_back(new TopFire(x, buffY));
		}
		else
		{
			vFire.push_back(new TongueTop(x, buffY));
		}
	}
	//fire bot
	buffY = y;
	possibility = true;
	for (int i = 0; i < fireSize; i++)
	{
		buffY += unitSize;
		sprBUff.setPosition(buffX + aLittleBit, buffY + aLittleBit);
		if (sprBUff.getGlobalBounds().intersects(wall.getDownBound()))
		{
			break;
		}
		for (int j = 0; j < blocksIndestrSize; j++)
		{
			if (sprBUff.getGlobalBounds().intersects(blocksIndestr[j].getBound()))
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
			if (sprBUff.getGlobalBounds().intersects(blocksDestr.at(j)->getBound()))
			{
				vRuined.push_back(new Ruined(blocksDestr.at(j)->getSprite().getPosition().x, blocksDestr.at(j)->getSprite().getPosition().y));
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
			vFire.push_back(new BotFire(buffX, buffY));
		}
		else
		{
			vFire.push_back(new TongueBot(buffX, buffY));
		}
	}
	return vFire;
}
 Game * Game::getInstance()
{
	if (game == nullptr)
	{
		std::cout << "Creation of Singleton " << std::endl;
		return game = new Game();
	}
	return game;
}
 void Game::method()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Bomberman");
	window.setFramerateLimit(60);
	srand(time(0));

	blocksIndestr = new Indestructible[blocksIndestrSize];
	for (int i = 0; i < blocksIndestrSize; i++)
	{
		blocksIndestr[i] = Indestructible(i, &textureBlocks);

	}


	//blocksDestr.fill = new Destructible[90]; //131
	for (int i = 0, j = 1; j <= 131; i++)
	{
		if (rand() % 2 == 0)
		{
			j++;
		}
		if (rand() % 3 == 0)
		{
			j++;
		}
		j++;
		blocksDestr.push_back(new Destructible(&textureBlocks, j));

	}

	int *buff = new int;
	*buff = rand() % blocksDestr.size();
	std::cout << "buff = " << *buff;
	door = new Door(blocksDestr.at(*buff)->getSprite().getPosition().x, blocksDestr.at(*buff)->getSprite().getPosition().y);
	delete buff;
	vMonsters.clear();
	for (int i = 0; i < monstersCount; i++)
	{
		
		vMonsters.push_back(new SimpleMonster(blocksIndestr, blocksIndestrSize, blocksDestr));
	}


	//bomb = nullptr;
	player1.setMS(moveSpeed);
	player1.setBombCount(bombCoumt);
	live = true;
	while (window.isOpen())
	{
		timeG = clock1.getElapsedTime().asMicroseconds();
		clock1.restart();
		timeG = timeG / 10000;

		sf::Event Event;
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
				window.close();
		}
		if (live == true)
		{
			player1.move(blocksIndestr, blocksIndestrSize, blocksDestr, vBombs, timeG, wall);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
			{
				if ((Bomb::getCountBomb() == 0) || (Bomb::getCountBomb() < player1.getBombCount() && !player1.GetInvSprite().getGlobalBounds().intersects(vBombs.back()->getBounds())))
				{
					vBombs.push_back(new Bomb(player1.GetInvSprite().getPosition().x, player1.GetInvSprite().getPosition().y));
				}

			}
		}
		window.clear(sf::Color::Black);
		window.draw(fone.getSprite());
		for (int i = 0; i < blocksIndestrSize; i++)
		{
			window.draw(blocksIndestr[i].getSprite());
		}
		window.draw(door->getSprite());
		for (int i = 0; i < blocksDestr.size(); i++)
		{
			window.draw(blocksDestr.at(i)->getSprite());

		}

		window.draw(wall.getSpriteUp());
		window.draw(wall.getSpriteLeft());
		if (deathHero == nullptr)
		{
			window.draw(player1.GetSprite());
		}
		window.draw(wall.getSpriteDown());
		window.draw(wall.getSpriteRight());

		for (int i = 0; i < vBombs.size(); i++)             //анімація бомби, кінець її, початок вогню 
		{
			if (!vBombs[i]->stay(timeG))
			{
				vvFire.push_back(getNewFire(vBombs[i]->getSprite().getPosition().x, vBombs[i]->getSprite().getPosition().y));
				delete vBombs[i];
				vBombs.erase(vBombs.begin() + i);
			}
			else
			{
				window.draw(vBombs[i]->getSprite());
				//window.draw(vBombs[i]->getInvSprite());   //   тест невидимої текстури
			}
		}
		for (int i = 0; i < vvFire.size(); i++)			// вивід і видалення вогню
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
		for (int i = 0; i < vRuined.size(); i++)             //анімація знищення
		{
			if (!vRuined[i]->destruction())
			{

				delete vRuined[i];
				vRuined.erase(vRuined.begin() + i);

			}  
			else
			{
				window.draw(vRuined[i]->getSprite());
				//window.draw(vBombs[i]->getInvSprite());   //   тест невидимої текстури
			}
		}
		if (!vMonsters.empty()) //monster move and death
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
								vDeathMonster.push_back(new DeathSimpleMomster(vMonsters.at(j)->getSprite().getPosition().x, vMonsters.at(j)->getSprite().getPosition().y));
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
					vMonsters.at(j)->move(blocksIndestr, blocksIndestrSize, blocksDestr, timeG, vBombs, wall);
					window.draw(vMonsters.at(j)->getSprite());
				}
			}
				
		}
		
		if (!vvFire.empty())  //fire + bomb
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
		if (!vvFire.empty())  //fire + Hero
		{
			for (size_t k = 0; k < vvFire.size(); k++)
			{
				for (size_t i = 0; i < vvFire.at(k).size(); i++)
				{
					if (vvFire.at(k).at(i)->getSprite().getGlobalBounds().intersects(player1.GetInvSprite().getGlobalBounds()))
					{
						live = false;
						break;
					}
				}
			}
		}
		for (int i = 0; i < vMonsters.size(); i++)
		{
			if (vMonsters.at(i)->getBounds().intersects(player1.GetInvSprite().getGlobalBounds()))
			{
				live = false;
				break;
			}
		}
		if (deathHero == nullptr && live == false)
		{
			std::cout << "DEAD!!!" << std::endl;
			deathHero = new DeathHero(player1.GetInvSprite().getPosition().x, player1.GetInvSprite().getPosition().y);

		}
		
		if (!vDeathMonster.empty()) // drow deathMonster
		{	
			for (int i = 0; i < vDeathMonster.size(); i++)
			{
				if (vDeathMonster.at(i)->sweetDeath())
				{
					window.draw(vDeathMonster.at(i)->getSprite());
				}
				else
				{
					delete vDeathMonster.at(i);
					vDeathMonster.erase(vDeathMonster.begin() + i);
					break;
				}

			}
		}
		if (deathHero != nullptr)
		{
			window.draw(deathHero->getSprite());
		}
		if (deathHero != nullptr && !deathHero->bitterDeath())
		{
			break;
		}
		
		if (player1.GetInvSprite().getGlobalBounds().intersects(door->getBound()) && vMonsters.empty())
		{
			break;
		}
		window.display();
	}

}