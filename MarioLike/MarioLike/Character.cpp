#include "Character.h"


Character::Character() 
{
	this->character_texture.loadFromFile("../../Sprites/Character.png");
	this->character.setTexture(character_texture);
	this->character.setPosition(sf::Vector2f(10.f, 700.f));
	this->jump = false;
	this->speedX = 0;
	this->speedY = 0;
	this->boundingBox = character.getGlobalBounds();
}


void Character::move(float x, float y)
{
	this->character.move(x,y);
}

void Character::update()
{
	

	this->character.move(speedX, speedY);

	setSpeedY(speedY + GRAVITY);
	setSpeedX(0.f);

	boundingBox = character.getGlobalBounds();
}

void Character::startJump()
{
	this->jump = true;
	setSpeedY(-JUMP_VELOCITY);
}

void Character::endJump()
{
	this->jump = false;
	setSpeedY(0.f);
}

void Character::setSpeedX(float speedX)
{
	this->speedX = speedX;
}

void Character::setSpeedY(float speedY)
{
	this->speedY = speedY;
}

bool Character::isJumping()
{
	return jump;
}