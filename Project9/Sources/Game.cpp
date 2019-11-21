#include "..\Headers\Game.h"
float Game::timeElapsed = 0;
Game *Game::game = nullptr;
Game::Game()
{
}
Game* Game::getInstance()
{
	if (game == nullptr)
	{
		return game = new Game();
	}
	return game;
}
bool Game::loadingResources()
{
	return imgBlocks.loadFromFile("blocks.png")
		&& imgRuined.loadFromFile("ruined.png")
		&& imgFone.loadFromFile("fone.png")
		&& imgHero.loadFromFile("hero.png")
		&& imgBomb.loadFromFile("bomb.png")
		&& imgBoost.loadFromFile("fireBoost.png")
		&& imgWall.loadFromFile("wall.jpg")
		&& imgFire.loadFromFile("fire.png")
		&& imgDeathMonster.loadFromFile("monster_death.png")
		&& imgMonster.loadFromFile("monster.png");
	
}
void Game::setGameParameters()
{
	// Set textures
	fone.setTexture(imgFone);
	hero.setTexture(imgHero);
	wall.setTexture(imgWall);
	textureBlocks.loadFromImage(imgBlocks);
	sprFire.setTextureRect(sf::IntRect(0, 0, UNIT_SIZE - LITTLE_BIT * 2, UNIT_SIZE - LITTLE_BIT * 2));

	// Create window. Set parameters
	window.create(sf::VideoMode(600, 600), "Bomberman");
	window.setFramerateLimit(60);
	srand(time(0));
}
void Game::setLevelParameters()
{
	gameSpeed = 10000;
	blocksIndestrAmount = 36;
	monstersCount = 5;
	maxPosForDestrBlocks = 131;
	isGameOver = false;

	// Set player characteristics
	moveSpeed = 1.3;
	bomb—ount = 2;
	fireSize = 1;
	hero.setMS(moveSpeed);
	hero.setBombCount(bomb—ount);
	isHeroAlive = true;
	deathHero = nullptr;
};
void Game::generationLevel() 
{
	// Set indestructible blocks
	blocksIndestr = new Indestructible[blocksIndestrAmount];
	for (int i = 0; i < blocksIndestrAmount; i++)
	{
		blocksIndestr[i] = Indestructible(i, &textureBlocks);
	}

	// Set destructible blocks
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

	// Rand pos for dors behind block, set it;
	int* numbBlockForDor = new int;
	*numbBlockForDor = rand() % blocksDestr.size();
	door = new Door(blocksDestr.at(*numbBlockForDor)->getSprite().getPosition().x, blocksDestr.at(*numbBlockForDor)->getSprite().getPosition().y, imgBlocks);

	// Rand pos for boost behind block, set it;
	int* numbBlockForBoost = new int;
	do {
		*numbBlockForBoost = rand() % blocksDestr.size();
	} while (*numbBlockForDor == *numbBlockForBoost);
	boost = new Boost(blocksDestr.at(*numbBlockForBoost)->getSprite().getPosition().x, blocksDestr.at(*numbBlockForBoost)->getSprite().getPosition().y, imgBoost);
	delete numbBlockForDor, numbBlockForBoost;

	// Set monsters;
	vMonsters.clear();
	for (int i = 0; i < monstersCount; i++)
	{
		vMonsters.push_back(new SimpleMonster(blocksIndestr, blocksIndestrAmount, blocksDestr, imgMonster));
	}
}
bool Game::isWidowOpen()
{
	while (window.pollEvent(windowEvent))
	{
		if (windowEvent.type == sf::Event::Closed)
		{
			window.close();
			return false;
		}
		return true;
	}
}
void Game::timeBound()
{
	timeElapsed = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	timeElapsed = timeElapsed / gameSpeed;
}
// A function that creates instances of classes of flames, and checks this possibility
// Calling after bomb detonation, in the same position
std::vector<Fire*> Game::getNewFire(int x, int y)
{
	// Fire central
	int fireX = x, fireY = y;
	bool possibility = true;
	vFire.clear();
	vFire.push_back(new MainFire(x, y, imgFire));
	// Fire right
	for (int i = 0; i < fireSize; i++)
	{
		fireX += UNIT_SIZE;

		sprFire.setPosition(fireX + LITTLE_BIT, fireY + LITTLE_BIT);
		if (sprFire.getGlobalBounds().intersects(wall.getRightBound()))
		{
			break;
		}
		for (int j = 0; j < blocksIndestrAmount; j++)
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
			vFire.push_back(new RightFire(fireX, fireY, imgFire));
		}
		else
		{
			vFire.push_back(new TongueRight(fireX, fireY, imgFire));
		}
	}
	// Fire left
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
		for (int j = 0; j < blocksIndestrAmount; j++)
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
			vFire.push_back(new LeftFire(fireX, y, imgFire));
		}
		else
		{
			vFire.push_back(new TongueLeft(fireX, y, imgFire));
		}
	}
	// Fire top
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
		for (int j = 0; j < blocksIndestrAmount; j++)
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
			vFire.push_back(new TopFire(x, fireY, imgFire));
		}
		else
		{
			vFire.push_back(new TongueTop(x, fireY, imgFire));
		}
	}
	// Fire bot
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
		for (int j = 0; j < blocksIndestrAmount; j++)
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
			vFire.push_back(new BotFire(fireX, fireY, imgFire));
		}
		else
		{
			vFire.push_back(new TongueBot(fireX, fireY, imgFire));
		}
	}
	return vFire;
}
void Game::logic()
{
	// Move hero and bomb placing
	if (isHeroAlive == true)
	{
		hero.move(blocksIndestr, blocksIndestrAmount, blocksDestr, vBombs, timeElapsed, wall);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
		{
			if ((Bomb::getCountBomb() == 0) || (Bomb::getCountBomb() < hero.getBombCount() && !hero.GetInvSprite().getGlobalBounds().intersects(vBombs.back()->getBounds())))
			{
				vBombs.push_back(new Bomb(hero.GetInvSprite().getPosition().x, hero.GetInvSprite().getPosition().y, imgBomb));
			}
		}
	}

	//  Increment fire size if hero took boost
	if (boost)
	{
		if (hero.GetInvSprite().getGlobalBounds().intersects(boost->getBound()))
		{
			delete boost;
			boost = nullptr;
			fireSize++;
		}
	}
	
	// Instantaneous detonation ≥f fire is on a bomb
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

	// Killing hero if fire is on him
	if (!vvFire.empty())
	{
		for (size_t k = 0; k < vvFire.size(); k++)
		{
			for (size_t i = 0; i < vvFire.at(k).size(); i++)
			{
				if (vvFire.at(k).at(i)->getSprite().getGlobalBounds().intersects(hero.GetInvSprite().getGlobalBounds()))
				{
					isHeroAlive = false;
					break;
				}
			}
		}
	}

	// Killing hero if monster is on him
	for (int i = 0; i < vMonsters.size(); i++)
	{
		if (vMonsters.at(i)->getBounds().intersects(hero.GetInvSprite().getGlobalBounds()))
		{
			isHeroAlive = false;
			break;
		}
	}

	// Creating "gost" of hero if he is dead 
	if (deathHero == nullptr && isHeroAlive == false)
	{
		deathHero = new DeathHero(hero.GetInvSprite().getPosition().x, hero.GetInvSprite().getPosition().y, imgHero);

	}

	// ≤f the bomb time is out, detonation. Creating flames. Delete bomb
	for (int i = 0; i < vBombs.size(); i++)
	{
		if (!vBombs[i]->isBombAlive(timeElapsed))
		{
			vvFire.push_back(getNewFire(vBombs[i]->getSprite().getPosition().x, vBombs[i]->getSprite().getPosition().y));
			delete vBombs[i];
			vBombs.erase(vBombs.begin() + i);
		}
	}

	// Monsters move and death
	if (!vMonsters.empty())
	{
		for (size_t j = 0; j < vMonsters.size(); j++)
		{
			vMonsters.at(j)->move(blocksIndestr, blocksIndestrAmount, blocksDestr, timeElapsed, vBombs, wall);
			if (!vvFire.empty())
			{
				for (size_t k = 0; k < vvFire.size(); k++)
				{
					for (size_t i = 0; i < vvFire.at(k).size(); i++)
					{
						if (vvFire.at(k).at(i)->getSprite().getGlobalBounds().intersects(vMonsters.at(j)->getBounds()))
						{
							vDeadMonster.push_back(new DeathSimpleMomster(vMonsters.at(j)->getSprite().getPosition().x, vMonsters.at(j)->getSprite().getPosition().y, imgDeathMonster));
							delete vMonsters.at(j);
							vMonsters.erase(vMonsters.begin() + j);
							break;
						}
					}

				}
			}
			
		}

	}

	// After the animation of death, the game ends
	if (deathHero != nullptr && !deathHero->bitterDeath())
	{
		isGameOver = true;
	}

	// After killing all the monstersand and passing the hero at the door, the level is complete
	if (hero.GetInvSprite().getGlobalBounds().intersects(door->getBound()) && vMonsters.empty())
	{
		// next lvl
		isGameOver = true;
	}
}
void Game::draw()
{
	window.clear(sf::Color::Black);
	window.draw(fone.getSprite());
	window.draw(door->getSprite());

	// Draw boost if not activated
	if (boost != nullptr)
	{
		window.draw(boost->getSprite());
	}

	// Draw blocks
	for (int i = 0; i < blocksIndestrAmount; i++)
	{
		window.draw(blocksIndestr[i].getSprite());
	}
	for (int i = 0; i < blocksDestr.size(); i++)
	{
		window.draw(blocksDestr.at(i)->getSprite());

	}

	// Draw walls
	window.draw(wall.getSpriteUp());
	window.draw(wall.getSpriteLeft());
	window.draw(wall.getSpriteDown());
	window.draw(wall.getSpriteRight());

	// Draw fire. Stop drowing after the animation is over
	for (int i = 0; i < vvFire.size(); i++)
	{
		if (vvFire[i].at(0)->isFireBurning())
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

	// Draw destruction of blocks. Stop drowing after the animation is over
	for (int i = 0; i < vRuined.size(); i++)
	{
		if (vRuined[i]->destruction())
		{
			window.draw(vRuined[i]->getSprite());
		}
		else
		{
			delete vRuined[i];
			vRuined.erase(vRuined.begin() + i);
		}
	}

	// Draw monsters
	if (!vMonsters.empty())
	{
		for (size_t j = 0; j < vMonsters.size(); j++)
		{
			window.draw(vMonsters.at(j)->getSprite());
		}
	}

	// Draw death of the monster if he is dead, stop drawing after the animation is over
	if (!vDeadMonster.empty())
	{
		for (int i = 0; i < vDeadMonster.size(); i++)
		{
			if (vDeadMonster.at(i)->deathAnimation())
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

	// Draw hero
	if (isHeroAlive == true)
	{
		window.draw(hero.GetSprite());
	}

	// Draw bomb
	for (int i = 0; i < vBombs.size(); i++)
	{
		if (vBombs[i]->isBombAlive(timeElapsed))
		{
			window.draw(vBombs[i]->getSprite());
		}
	}

	//  Draw death of the hero
	if (deathHero != nullptr)
	{
		window.draw(deathHero->getSprite());
	}
	window.display();
}
 void Game::mainMethod()
{
	 // —heck is all files loaded. if not, stops at the console with error mesage. The game does not start
	 if (!loadingResources())
	 {
		 system("pause");
		 return;
	 }
	setGameParameters();
	setLevelParameters();
	generationLevel();

	// Main game cycle
	while (Game::isWidowOpen() && !isGameOver)
	{
		timeBound();
		logic();
		draw();
	}
}