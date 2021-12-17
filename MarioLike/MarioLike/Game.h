#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "Platforms.h"
#include "GameUI.h"

enum GameStatus {
	START,
	INGAME,
	PAUSE,
	GAMEOVER,
	VICTORY
};

class Game
{
public:
	sf::RenderWindow window;

	sf::Sprite background;
	sf::Texture backgroundTexture;
	Character *character;
	std::vector<Platforms*> platforms;

	sf::Sprite button;
	sf::Texture buttonTexture;
	GameUI *gameOver;
	GameUI *pause;
	GameUI *start;

	int status;

	Game();
	~Game();

	void loop();
	void restart();
};