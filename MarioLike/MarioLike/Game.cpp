#include "Game.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define MAX_FPS 60


Game::Game()
{
	this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Mario in Space", sf::Style::Fullscreen);
	this->window.setFramerateLimit(MAX_FPS);
	this->size = window.getSize();
	this->character = new Character();
	this->platforms = new Platforms();
	this->Background_texture.loadFromFile("../../Sprites/Background2.jpg");
	this->Background.setTexture(Background_texture);
}

Game::~Game()
{

}

void Game::restart()
{
	this->character = new Character();
}


void Game::start()
{
	sf::Sprite button_play;
	sf::Texture button_texture;

	bool start = false;
	button_texture.loadFromFile("../../Sprites/Button.jpg");
	button_play.setTexture(button_texture);

	button_play.setPosition(760.f, 460.f);

	while (window.isOpen() && !start)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			// la touche "echap" est enfoncée : on met l'event a closed
			window.close();
			break;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			// le bouton gauche est enfoncé 
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			if (localPosition.x >= button_play.getPosition().x && localPosition.y >= button_play.getPosition().y && localPosition.x <= button_play.getPosition().x + 400 && localPosition.y <= button_play.getPosition().y + 190)
				start = true;
		}

		printf("pos start x %d et y %d", button_play.getPosition().x, button_play.getPosition().y);

		window.draw(button_play);

		window.display();
	}
}

void Game::loop()
{
	sf::Clock clock;

	start();

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
			character->setSpeedX(-VELOCITY);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// la touche "flèche droite" est enfoncée : on bouge le personnage
			character->setSpeedX(VELOCITY);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			// la touche "R" est enfoncée : on restart le personnage
			restart();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			// la touche "echap" est enfoncée : on met l'event a closed
			window.close();
			break;
		}

		if (character->boundingBox.intersects(platforms->boundingBox))
		{
			character->endJump();
		}
			
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !character->isJumping())
		{
			character->startJump();
		}

		character->update(); /* update le boxing collision du character et bouge le personnage */


		window.clear();

		window.draw(Background);
		window.draw(platforms->platform);
		window.draw(character->character);

		window.display();
	}
}