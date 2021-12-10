#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{

	Game* game = new Game();
	game->start();
	game->loop();
	delete game;
	game = nullptr;

	return 0;
}