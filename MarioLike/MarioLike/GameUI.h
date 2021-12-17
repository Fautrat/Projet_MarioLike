#ifndef GAMEUI_H
#define GAMEUI_H

#include <SFML/Graphics.hpp>
#include <sstream>

class GameUI
{
public:
	GameUI();
	~GameUI()=default;

	/* Draw UI on specified window. */
	virtual void draw(sf::RenderWindow& window)=0;

protected:
	sf::Font font;
};

/* --------------- StartMenu --------------- */

class StartMenu : public GameUI
{
public:
	StartMenu(sf::RenderWindow& window);
	~StartMenu()=default;
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape overlay;
	sf::Text title;
	sf::Text message1;
	sf::Text message2;
	sf::Text credits;
};

/* --------------- PauseMenu --------------- */

class PauseMenu : public GameUI
{
public:
	PauseMenu(sf::RenderWindow& window);
	~PauseMenu()=default;
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape overlay;
	sf::Text title;
};

/* --------------- GameOverMenu --------------- */

class GameOverMenu : public GameUI
{
public:
	GameOverMenu(sf::RenderWindow& window);
	~GameOverMenu()=default;
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape overlay;
	sf::Text title;
	sf::Text message1;
	sf::Text message2;
};

#endif // !GAMEUI_H


