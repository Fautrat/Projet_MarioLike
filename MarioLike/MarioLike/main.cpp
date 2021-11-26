#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	/* variables */
	//int isJumping = 0;
	//float velocity = 0;

	//sf::RenderWindow window(sf::VideoMode(1600, 900), "Mario");

	//// récupération de la taille de la fenêtre
	//sf::Vector2u size = window.getSize();

	//sf::Sprite chara;
	//sf::Sprite Background;
	//sf::Sprite platform;
	//sf::Sprite platform2;
	//sf::Sprite platform3;

	///* Création des textures */
	//sf::Texture texture;
	//sf::Texture chara_texture;
	//sf::Texture platform_texture;
	//if (!texture.loadFromFile("../../Sprites/Background2.jpg"))
	//	return 0;
	//if (!chara_texture.loadFromFile("../../Sprites/Character.png"))
	//	return 0;
	//if (!platform_texture.loadFromFile("../../Sprites/platform.png"))
	//	return 0;


	//Background.setTexture(texture);
	//chara.setTexture(chara_texture);
	//chara.setPosition(50.f, size.y - 95.f);

	///* création platforms */
	//platform.setTexture(platform_texture);
	//platform.setPosition(0.f,size.y - 50.f); 
	//platform2.setTexture(platform_texture);
	//platform2.setPosition(400.f, size.y - 50.f);
	//platform3.setTexture(platform_texture);
	//platform3.setPosition(1000.f, size.y - 50.f);

	Game* game = new Game();
	game->Loop();
	delete game;
	game = nullptr;

	return 0;
}