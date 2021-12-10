#include "Character.h"



Character::Character() 
{
	this->character_texture.loadFromFile("../../Sprites/Character.png");
	this->character.setTexture(character_texture);
	this->character.setPosition(sf::Vector2f(STARTING_POS_X, STARTING_POS_Y));
	this->jump = false;
	this->speedX = 0;
	this->speedY = 0;
	this->boundingBox = character.getGlobalBounds();
}


void Character::move(float x, float y)
{
	this->character.move(x,y);
}

/* Update la boundingbox du joueur, mets à jour sa position avec un move et change sa vitesse */
void Character::update()
{
	this->character.move(speedX, speedY);

	boundingBox = character.getGlobalBounds();

	setSpeedY(speedY + GRAVITY);
	setSpeedX(0.f);
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