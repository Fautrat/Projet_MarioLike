#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{

	Game* game = new Game();
	game->loop();
	delete game;
	game = nullptr;

	return 0;
}