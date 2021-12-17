#include "GameUI.h"

#define BIG_FONT_SIZE 120
#define MIDDLE_FONT_SIZE 35
#define SMALL_FONT_SIZE 20


GameUI::GameUI() {
	font.loadFromFile("../../Font/space_age.ttf");
}

/* --------------- StartMenu --------------- */

StartMenu::StartMenu(sf::RenderWindow& window) : GameUI() {

	//Overlay
	this->overlay = sf::RectangleShape(sf::Vector2f((float)window.getSize().x, (float)window.getSize().y));
	overlay.setFillColor(sf::Color(0, 0, 0, 200));

	//Title
	title.setString("SPACE MARIO");
	title.setFont(this->font);
	title.setCharacterSize(BIG_FONT_SIZE);
	sf::FloatRect titleRect = title.getLocalBounds();
	title.setOrigin(titleRect.left + titleRect.width / 2.0f, titleRect.top + titleRect.height / 2.0f);
	title.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f - 200));

	//Message1
	message1.setString("Press Enter to play the game");
	message1.setFont(this->font);
	message1.setCharacterSize(MIDDLE_FONT_SIZE);
	sf::FloatRect messageRect1 = message1.getLocalBounds();
	message1.setOrigin(messageRect1.left + messageRect1.width / 2.0f, messageRect1.top + messageRect1.height / 2.0f);
	message1.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));

	//Message
	message2.setString("Press Escape to quit");
	message2.setFont(this->font);
	message2.setCharacterSize(MIDDLE_FONT_SIZE);
	sf::FloatRect messageRect2 = message2.getLocalBounds();
	message2.setOrigin(messageRect2.left + messageRect2.width / 2.0f, messageRect2.top + messageRect2.height / 2.0f);
	message2.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f + 100));

	//Credits
	/*credits.setString("Credits : ");
	credits.setCharacterSize(SMALL_FONT_SIZE);
	credits.setPosition(sf::Vector2f(20, window.getSize().y - 50));*/
}



void StartMenu::draw(sf::RenderWindow& window) {
	window.draw(overlay);
	window.draw(title);
	window.draw(message1);
	window.draw(message2);
	//window.draw(credits);
}

/* --------------- PauseMenu --------------- */

PauseMenu::PauseMenu(sf::RenderWindow& window) : GameUI() {

	//Overlay
	this->overlay = sf::RectangleShape(sf::Vector2f((float)window.getSize().x, (float)window.getSize().y));
	overlay.setFillColor(sf::Color(0, 0, 0, 200));

	//Title
	title.setString("PAUSE");
	title.setFont(this->font);
	title.setCharacterSize(BIG_FONT_SIZE);
	sf::FloatRect titleRect = title.getLocalBounds();
	title.setOrigin(titleRect.left + titleRect.width / 2.0f, titleRect.top + titleRect.height / 2.0f);
	title.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));
}



void PauseMenu::draw(sf::RenderWindow& window) {
	window.draw(overlay);
	window.draw(title);
}

/* --------------- GameOverMenu --------------- */

GameOverMenu::GameOverMenu(sf::RenderWindow& window) : GameUI() {

	//Overlay
	this->overlay = sf::RectangleShape(sf::Vector2f(window.getSize().x, window.getSize().y));
	overlay.setFillColor(sf::Color(0, 0, 0, 255));

	//Title
	title.setString("GAME OVER");
	title.setFont(this->font);
	title.setCharacterSize(BIG_FONT_SIZE);
	sf::FloatRect titleRect = title.getLocalBounds();
	title.setOrigin(titleRect.left + titleRect.width / 2.0f, titleRect.top + titleRect.height / 2.0f);
	title.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f - 200));

	//Message1
	message1.setString("Press Enter to restart");
	message1.setFont(this->font);
	message1.setCharacterSize(MIDDLE_FONT_SIZE);
	sf::FloatRect messageRect1 = message1.getLocalBounds();
	message1.setOrigin(messageRect1.left + messageRect1.width / 2.0f, messageRect1.top + messageRect1.height / 2.0f);
	message1.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));

	//Message
	message2.setString("Press Escape to quit");
	message2.setFont(this->font);
	message2.setCharacterSize(MIDDLE_FONT_SIZE);
	sf::FloatRect messageRect2 = message2.getLocalBounds();
	message2.setOrigin(messageRect2.left + messageRect2.width / 2.0f, messageRect2.top + messageRect2.height / 2.0f);
	message2.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f + 100));

}


void GameOverMenu::draw(sf::RenderWindow& window) {
	window.draw(overlay);
	window.draw(title);
	window.draw(message1);
	window.draw(message2);
}
