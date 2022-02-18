#include "Player.h"

Player::Player(sf::Vector2f size, sf::Texture* texture, sf::Vector2f position) {
    player.setSize(size);
    player.setTexture(texture);
	player.setPosition(position);
	this->moveSpeedX = 0.f;
	this->moveSpeedY = 0.f;
	this->isJumping = false;
	this->score = 0;
	this->life = 3;

}

void Player::draw(sf::RenderWindow& window) {
    window.draw(player);
}


void Player::setPosition(sf::Vector2f position) {
    player.setPosition(position);
}

void Player::setScore(int score) {
	this->score = score;
}

float Player::getX() {
	return player.getPosition().x;
}

float Player::getY() {
	return player.getPosition().y;
}

int Player::getScore() {
	return score;
}

int Player::getLife() {
	return this->life;
}

sf::FloatRect Player::getGlobalBounds() {
	return player.getGlobalBounds();
}

void Player::damage() {
	this->life = std::max(this->life - 1, 0);
}

int Player::inputProcessing(float deltaTime, float mapSizeX) {

	int retour = Direction::UP;

	//SPACE
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping)
	{
		isJumping = true;
		moveSpeedY = -300.f;
	}

	//RIGHT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (getX() + (moveSpeedX * deltaTime) < mapSizeX)
			moveSpeedX = 200.f;
		retour = Direction::RIGHT;
	}
	//LEFT
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		if (getX() + (-moveSpeedX * deltaTime) > 0)
			if (getX() > moveSpeedX * deltaTime)
				moveSpeedX = -200.f;
		retour =  Direction::LEFT;
	}
	else if(moveSpeedY >= 0.f)
		retour = Direction::DOWN;

	player.move(moveSpeedX * deltaTime, moveSpeedY * deltaTime);

	if(isJumping)
		moveSpeedY = moveSpeedY + GRAVITY;


	moveSpeedX = 0.f;

	return retour;
}

void Player::stopJumping() 
{
	isJumping = false;
	this->moveSpeedY = 0.f;
}