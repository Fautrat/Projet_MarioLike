#include "Game.h"

#define WINDOW_WIDTH 1680
#define WINDOW_HEIGHT 1050
#define MAX_FPS 60


Game::Game()
{
	/* création de la fenetre */
	this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Mario in Space");
	this->window.setFramerateLimit(MAX_FPS);


	/* création du personnage */
	this->character = new Character();

	/* création des platforms */
	this->platforms.push_back(new Platforms(20,900));
	this->platforms.push_back(new Platforms(500, 900));
	this->platforms.push_back(new Platforms(900, 900));

	/* création du background */
	this->backgroundTexture.loadFromFile("../../Sprites/Background2.jpg");
	this->background.setTexture(backgroundTexture);

	/* creation du bouton de start */

	this->buttonTexture.loadFromFile("../../Sprites/Button.png");
	this->button.setTexture(buttonTexture);
	this->button.setOrigin(195, 85);
	this->button.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	/* Init des Menus */
	this->gameOver = new GameOverMenu(this->window);
	this->pause = new PauseMenu(this->window);
	this->start = new StartMenu(this->window);

	// Game status
	this->status = GameStatus::START;
}

Game::~Game()
{

}

void Game::restart()
{
	this->character = new Character();
}

void Game::loop()
{
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				// Close window
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed :
					if(event.key.code == sf::Keyboard::Escape)
						window.close();
					if (event.key.code == sf::Keyboard::P)
					{
						if (status == GameStatus::INGAME)
						{
							status = GameStatus::PAUSE;
						}
						else if (status == GameStatus::PAUSE)
						{
							status = GameStatus::INGAME;
						}
					}
					if (event.key.code == sf::Keyboard::Enter)
					{
						if (status == GameStatus::START)
						{
							status = GameStatus::INGAME;
						}
						else if (status == GameStatus::GAMEOVER)
						{
							status = GameStatus::INGAME;
						}
					}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (status == GameStatus::START) 
		{
			window.clear();
			start->draw(window);
		}

		else if (status == GameStatus::PAUSE)
		{
			window.clear();
			pause->draw(window);
		}

		else if (status == GameStatus::INGAME)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				// la touche "flèche gauche" est enfoncée :  on change la vitesse du personnage
				character->setSpeedX(-VELOCITY);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				// la touche "flèche droite" est enfoncée : on change la vitesse du personnage
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

			for (auto& itr : platforms)
			{
				if (character->boundingBox.intersects(itr->boundingBox))
				{
					character->endJump();
				}
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !character->isJumping())
			{
				character->startJump();
			}

			character->update(); /* update le boxing collision du character et bouge le personnage */


			window.clear();

			window.draw(background);

			for (auto& itr : platforms)
			{
				window.draw(itr->platform);
			}

			window.draw(character->character);
		}
		/* Fonction obligatoire pour afficher la fenetre */
		window.display();
	}
}