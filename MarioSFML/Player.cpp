#include "Player.h"

Player::Player(sf::Vector2f size, sf::Texture* texture, sf::Vector2f position) {
    player.setSize(size);
    player.setTexture(texture);
	player.setPosition(position);
	this->size = size.y;
	this->moveSpeed = 0.f;
	this->moveSpeedY = 0.f;
	this->isJumping = false;
	this->maxJump = 200.f;
	this->posY = getY();
	this->basePosY = getY();
	this->startJumping = false;
	this->gravity = 6.f;
	this->score = 0;
	this->life = 3;

}

void Player::draw(sf::RenderWindow& window) {
    window.draw(player);
}

void Player::jump(sf::Vector2f distance) {

	//up
	if (isJumping && getY() > posY - maxJump) {
		player.move(distance * gravity);
	}
	//need to go down because maxJump reached
	else 
		isJumping = false;
	//down
	if (!isJumping && getY() < posY) {
		player.move(distance * -gravity);
		//put the player on the ground (without it the player is a bit in the ground)
		/*if (getY() > posY) {
			setPosition({ (float)getX(),posY });
		}*/
	}
	//allow jump
	if (!isJumping && getY() == posY) {
		startJumping = false;
		posY = basePosY;
	}
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

float Player::getSpeed() {
	return moveSpeed;
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

	int retour;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping)
	{
		isJumping = true;
		moveSpeedY = -300.f;
	}


	//RIGHT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (getX() + (moveSpeed * deltaTime) < mapSizeX)
			moveSpeed = 200.f;
			/*player.move({ moveSpeed * deltaTime, 0 });*/
		retour = Direction::RIGHT;
	}
	//LEFT
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		if (getX() + (-moveSpeed * deltaTime) > 0)
			if (getX() > moveSpeed * deltaTime)
				moveSpeed = -200.f;
				/*player.move({ -moveSpeed * deltaTime, 0 });*/
		retour =  Direction::LEFT;
	}
	else
		retour= Direction::DOWN;

	player.move(moveSpeed * deltaTime, moveSpeedY * deltaTime);

	if (isJumping)
		moveSpeedY += gravity;
	else
		moveSpeedY = gravity;

	moveSpeed = 0.f;

	return retour;
}

void Player::stopJumping() {
	isJumping = false;
	moveSpeedY = 0.f;
}

void Player::setPosY(float posY) {
	this->posY = posY;
}

void Player::setStartJumping() {
	this->startJumping = false;
}

void Player::setBaseY() {
	this->posY = basePosY;;
}