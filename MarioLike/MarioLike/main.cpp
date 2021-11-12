#include <SFML/Graphics.hpp>
#include <errno.h>

int main()
{
	/* variables */
	int isJumping = 0;
	float velocity = 0;

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Mario");

	// récupération de la taille de la fenêtre
	sf::Vector2u size = window.getSize();

	sf::Sprite chara;
	sf::Sprite Background;
	sf::Sprite platform;
	sf::Sprite platform2;
	sf::Sprite platform3;

	/* Création des textures */
	sf::Texture texture;
	sf::Texture chara_texture;
	sf::Texture platform_texture;
	if (!texture.loadFromFile("../../Sprites/Background2.jpg"))
		return 0;
	if (!chara_texture.loadFromFile("../../Sprites/Character.png"))
		return 0;
	if (!platform_texture.loadFromFile("../../Sprites/platform.png"))
		return 0;


	Background.setTexture(texture);
	chara.setTexture(chara_texture);
	chara.setPosition(50.f, size.y - 95.f);

	/* création platforms */
	platform.setTexture(platform_texture);
	platform.setPosition(0.f,size.y - 50.f); 
	platform2.setTexture(platform_texture);
	platform2.setPosition(400.f, size.y - 50.f);
	platform3.setTexture(platform_texture);
	platform3.setPosition(1000.f, size.y - 50.f);


	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		//updateGame(elapsed);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// la touche "flèche gauche" est enfoncée : on bouge le personnage
			chara.move(-0.25, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// la touche "flèche droite" est enfoncée : on bouge le personnage
			chara.move(0.25, 0.f);
		}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		//{
		//	// la touche "flèche haut" est enfoncée : on bouge le personnage
		//	chara.move(0.f, -0.25);
		//}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		//{
		//	// la touche "flèche bas" est enfoncée : on bouge le personnage
		//	chara.move(0.f, 0.25);
		//}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isJumping == 0)
		{
			isJumping = 1;
			velocity = -0.70f;
		}

		/* gestion de la vélocité en l'air */
		if (isJumping == 1)
		{
			chara.move(0, velocity);
			velocity += 0.002f;
		}

		/* arret du saut */
		if (chara.getPosition().y >= platform.getPosition().y - 45 && isJumping == 1)
		{
			isJumping = 0;
		}

		window.clear();
		window.draw(Background);
		window.draw(platform);
		window.draw(platform2);
		window.draw(platform3);
		window.draw(chara);
		window.display();
	}
	return 0;
}