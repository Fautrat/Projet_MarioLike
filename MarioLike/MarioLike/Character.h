#pragma once
#include <SFML/Graphics.hpp>

#define VELOCITY 3.f

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

	void update();

private :
	bool isJumping;
	float speed;

};