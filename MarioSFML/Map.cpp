#include "Map.h"
#include "AssetsManager.h"
#include <iostream>
#include <fstream>

#define BLOCKSIZE 40.f
#define QUADTREE_X 3600
#define QUADTREE_Y 800
#define DISTANCE 41.f

Map::Map(AssetsManager& assets, sf::RenderWindow& window) 
{
	size = {(float)window.getSize().x, (float)window.getSize().y };

	player = nullptr;

	active = false;

}

Map::~Map() {

	delete player;
	player = nullptr;

	for (auto element : groundMap) {
		delete element.second;
	}
	for (auto element : enemyMap) {
		delete element.second;
	}
	for (auto element : coinMap) {
		delete element.second;
	}
	for (auto element : flagMap) {
		delete element.second;
	}

	groundMap.clear();
	enemyMap.clear();
	coinMap.clear();
	flagMap.clear();
}

void Map::draw(sf::RenderWindow& window) {

	if (active) {
		this->player->draw(window);

		for (auto it = groundMap.begin(); it != groundMap.end(); ++it)
			it->second->draw(window);

		for (auto it = enemyMap.begin(); it != enemyMap.end(); ++it)
			it->second->draw(window);

		for (auto it = coinMap.begin(); it != coinMap.end(); ++it)
			it->second->draw(window);

		for (auto it = flagMap.begin(); it != flagMap.end(); ++it)
			it->second->draw(window);
	}
}

void Map::readMap(AssetsManager& assets, std::string& filename) {

	active = true;
	int row = 0, col = -1;
	int maxCol = 0;
	char ch;
	std::fstream mapFile(filename, std::fstream::in);
	std::string line;

	while (std::getline(mapFile, line)) {
		row++;
	}

	mapFile.clear();
	mapFile.seekg(0);

	this->nbBlocks.y = row;

	// Read each char from the file 
	while (mapFile >> std::noskipws >> ch) {
		if (ch == '\n') {
			row--;
			if (col > maxCol)
				maxCol = col;
			col = -1;
		}
		else {
			col++;
		}

		if (ch == 'P') 
			this->player = new Player({ BLOCKSIZE, BLOCKSIZE }, &assets.getTRef("player"), { BLOCKSIZE * col, size.y - row * BLOCKSIZE });

		if (ch == 'G') {
			Ground* ground = new Ground({ BLOCKSIZE, BLOCKSIZE }, &assets.getTRef("ground"), { BLOCKSIZE * col, size.y - row * BLOCKSIZE });
			groundMap.insert({ std::make_pair(BLOCKSIZE * col, size.y - row * BLOCKSIZE),ground });
			collimap.insert({ std::make_pair(BLOCKSIZE * col, size.y - row * BLOCKSIZE), "ground" });
		}

		if (ch == '1') {
			Astronaut* enemy = new Astronaut({ BLOCKSIZE, BLOCKSIZE }, &assets.getTRef("astronaut"), { BLOCKSIZE * col, size.y - row * BLOCKSIZE });
			enemyMap.insert({ std::make_pair(BLOCKSIZE * col, size.y - row * BLOCKSIZE),enemy });
			collimap.insert({ std::make_pair(BLOCKSIZE * col, size.y - row * BLOCKSIZE), "enemy" });
		}

		if (ch == 'o') {
			Coin* coin = new Coin({ BLOCKSIZE, BLOCKSIZE }, &assets.getTRef("coin"), { BLOCKSIZE * col, size.y - row * BLOCKSIZE });
			coinMap.insert({ std::make_pair(BLOCKSIZE * col, size.y - row * BLOCKSIZE),coin });
			collimap.insert({ std::make_pair(BLOCKSIZE * col, size.y - row * BLOCKSIZE), "coin" });
		}

		if (ch == '*') {
			Flag* flag = new Flag({ BLOCKSIZE, BLOCKSIZE }, &assets.getTRef("flagMiddle"), { BLOCKSIZE * col, size.y - row * BLOCKSIZE });
			flagMap.insert({ std::make_pair(BLOCKSIZE * col, size.y - row * BLOCKSIZE),flag });
			collimap.insert({ std::make_pair(BLOCKSIZE * col, size.y - row * BLOCKSIZE), "flag" });
		}

		if (ch == '=') {
			Flag* flag = new Flag({ BLOCKSIZE, BLOCKSIZE }, &assets.getTRef("flagBottom"), { BLOCKSIZE * col, size.y - row * BLOCKSIZE });
			flagMap.insert({ std::make_pair(BLOCKSIZE * col, size.y - row * BLOCKSIZE),flag });
			collimap.insert({ std::make_pair(BLOCKSIZE * col, size.y - row * BLOCKSIZE), "flag" });
		}

		if (ch == '-') {
			Flag* flag = new Flag({ BLOCKSIZE, BLOCKSIZE }, &assets.getTRef("flagTop"), { BLOCKSIZE * col, size.y - row * BLOCKSIZE });
			flagMap.insert({ std::make_pair(BLOCKSIZE * col, size.y - row * BLOCKSIZE),flag });
			collimap.insert({ std::make_pair(BLOCKSIZE * col, size.y - row * BLOCKSIZE), "flag" });
		}
	}
	this->nbBlocks.x = maxCol + 1;
	this->size = { nbBlocks.x * BLOCKSIZE, nbBlocks.y * BLOCKSIZE };
}

int Map::checkCollisions(int input) {

	for (auto it = collimap.begin(); it != collimap.end(); ++it) {
		float x = it->first.first;
		float y = it->first.second;
		if (player->getGlobalBounds().intersects(sf::FloatRect(x, y, BLOCKSIZE, BLOCKSIZE)))
		{
			if (it->second == "flag")
				return GameStatus::VICTORY;
			else if (it->second == "coin")
			{
				coinMap.erase(std::make_pair(x, y));
				collimap.erase(std::make_pair(x, y));
				player->setScore(player->getScore() + 1);
				it = collimap.begin();
			}
			else if(it->second == "ground")
			{
				switch (input)
				{
				case Direction::UP:
					player->setPosition({ player->getX(), y + DISTANCE });
					break;
				case Direction::DOWN:
					player->stopJumping();
					player->setPosition({ player->getX(), y - DISTANCE });
					break;
				case Direction::LEFT:
					player->setPosition({ x + DISTANCE , player->getY() });
					break;
				case Direction::RIGHT:
					player->setPosition({ x - DISTANCE, player->getY() });
					break;
				}
			}
			else
			{
				switch (input)
				{
				case Direction::UP:
					player->stopJumping();
					player->setPosition({ player->getX(), y + DISTANCE });
					player->damage();
					if (player->getLife() == 0)
						return GameStatus::GAMEOVER;
					break;
				case Direction::DOWN:
					enemyMap.erase(std::make_pair(x, y));
					collimap.erase(std::make_pair(x, y));
					player->setScore(player->getScore() + 5);
					it = collimap.begin();
					break;
				case Direction::LEFT:
					player->setPosition({ x + 55.f , player->getY() }); /* distance 55.f plus grande sinon on collisionne encore avec l'enemy */
					player->damage();
					if (player->getLife() == 0)
						return GameStatus::GAMEOVER;
					break;
				case Direction::RIGHT:
					player->setPosition({ x - 55.f, player->getY() }); /* distance 55.f plus grande sinon on collisionne encore avec l'enemy */
					player->damage();
					if (player->getLife() == 0)
						return GameStatus::GAMEOVER;
					break;
				}
			}
		}
	}
	return GameStatus::INGAME;
}