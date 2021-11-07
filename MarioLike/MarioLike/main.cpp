#include <SFML/Graphics.hpp>

int main()
{
	/* variables */
	int isJumping = 0;
	float velocity = 0;

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Mario");

	// récupération de la taille de la fenêtre
	sf::Vector2u size = window.getSize();

	sf::RectangleShape rectangle(sf::Vector2f(size.x, -100.f));
	sf::RectangleShape chara(sf::Vector2f(10.f, -50.f));
	sf::RectangleShape Background(sf::Vector2f(size.x,size.y));
	rectangle.setOrigin(0.f, size.y * (-1.f));
	rectangle.setFillColor(sf::Color::Black);

	chara.setOrigin(-50.f, (-100.f + size.y) * -1.f);
	chara.setFillColor(sf::Color::Red);

	/* Création de la texture du background */
	sf::Texture texture;
	if (!texture.loadFromFile("../../Sprites/Background2.jpg"))
	{
		return 0;
	}
	Background.setTexture(&texture);

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// la touche "flèche droite" est enfoncée : on bouge le personnage
			chara.move(0.f, -0.25);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// la touche "flèche droite" est enfoncée : on bouge le personnage
			chara.move(0.f, 0.25);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isJumping == 0)
		{
			isJumping = 1;
			velocity = -0.60f;
		}

		if (isJumping == 1)
		{
			chara.move(0, velocity);
			velocity += 0.001f;
		}
		if (chara.getPosition().y >= rectangle.getPosition().y && isJumping == 1)
		{
			isJumping = 0;
		}

		window.clear();
		window.draw(Background);
		window.draw(rectangle);
		window.draw(chara);
		window.display();
	}

	return 0;
}