#pragma once
#include <SFML/Graphics.hpp>

#define VELOCITY 3.f
#define JUMP_VELOCITY 8.f
#define MAX_VELOCITY 8.f
#define GRAVITY 0.2f

#define STARTING_POS_Y 700.f
#define STARTING_POS_X 30.f

class Character 
{
public:

	sf::Vector2u size;
	sf::Sprite character;
	sf::Texture character_texture;
	sf::FloatRect boundingBox;

	Character();
	~Character();

	void move(float,float);

	/* Function draw character to window  */
	void draw(sf::RenderWindow);

	/* Get player X coordinates. */
	float getX();

	/* Get player Y coordinates. */
	float getY();

	/* Get player speed. */
	float getSpeed();

	void setSpeedX(float);

	void setSpeedY(float);

	void update();

	void startJump();

	void endJump();

	bool isJumping();

private :
	bool jump;
	float speedX;
	float speedY;

};