#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Platforms.h"

#define GRAVITY 3.f

class Game
{
public:
	sf::RenderWindow window;
	sf::Vector2u size;
	sf::Sprite Background;
	sf::Texture Background_texture;
	Character *character;
	Platforms *platforms;

	Game();
	~Game();

	void Loop();
};