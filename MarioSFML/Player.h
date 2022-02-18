#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>


enum Direction {
	DOWN = -2,
	LEFT = -1,
	UP = 0,
	RIGHT = 1
};
#define GRAVITY 6.f

class Player
{
public:
	Player(sf::Vector2f size, sf::Texture* texture, sf::Vector2f position);
	~Player() = default;

    /* Draw player on specified window. */
	void draw(sf::RenderWindow& window);

    /* Set player position. */
	void setPosition(sf::Vector2f position);

    /* Set player score. */
    void setScore(int score);

    /* Get player X coordinates. */
	float getX();

    /* Get player Y coordinates. */
	float getY();

    /* Get player score. */
    int getScore();
    int getLife();
	sf::FloatRect getGlobalBounds();

    /* Process user input in game. */
    int inputProcessing(float deltaTime, float mapSizeX);

    /* Cause damage to player. */
    void damage();

    /* End player jumping. */
    void stopJumping();

private:
    sf::RectangleShape player;
    float moveSpeedX;
	float moveSpeedY;
	bool isJumping;
    int score;
    int life;
};

#endif