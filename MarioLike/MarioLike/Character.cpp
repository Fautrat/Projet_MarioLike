#include "Character.h"


Character::Character()
{
	this->character_texture.loadFromFile("../../Sprites/Character.png");
	this->character.setTexture(character_texture);
	this->character.setPosition(sf::Vector2f(10.f, 700.f));
	this->isJumping = false;
	this->speed = VELOCITY;
	//this->boundingBox = character.getGlobalBounds;
}


void Character::move(float x, float y)
{
	this->character.move(x,y);
}