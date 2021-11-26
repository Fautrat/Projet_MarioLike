#include "Game.h"

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

Game::Game()
{
	this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Mario in Space");
	this->window.setFramerateLimit(60);
	this->size = window.getSize();
	this->character = new Character();
	this->platforms = new Platforms();
	this->Background_texture.loadFromFile("../../Sprites/Background2.jpg");
	this->Background.setTexture(Background_texture);
}

Game::~Game()
{

}

void Game::Loop()
{
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// la touche "flèche gauche" est enfoncée : on bouge le personnage
			character->character.move(-0.25, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// la touche "flèche droite" est enfoncée : on bouge le personnage
			character->character.move(0.25, 0.f);
		}

		if(!character->boundingBox.intersects(platforms->boundingBox))
			character->character.move(0, - GRAVITY);
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isJumping == 0)
		//{
		//	isJumping = 1;
		//	velocity = -0.70f;
		//}

		///* gestion de la vélocité en l'air */
		//if (isJumping == 1)
		//{
		//	chara.move(0, velocity);
		//	velocity += 0.002f;
		//}

		///* arret du saut */
		//if (chara.getPosition().y >= platform.getPosition().y - 45 && isJumping == 1)
		//{
		//	isJumping = 0;
		//}

		window.clear();
		window.draw(Background);
		window.draw(platforms->platform);
		window.draw(character->character);
		window.display();
	}
}