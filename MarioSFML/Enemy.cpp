#include "Enemy.h"

/* --------------- ENEMY --------------- */

Enemy::Enemy(sf::Vector2f size, sf::Texture* texture, sf::Vector2f position) {
	enemy.setTexture(texture);
	enemy.setPosition(position);
    enemy.setSize(size);
    moveSpeed = 0;
}

sf::FloatRect Enemy::getGlobalBounds() {
    return enemy.getGlobalBounds();
}

void Enemy::move(sf::Vector2f distance) {
    enemy.move(distance);
}

void Enemy::setPosition(sf::Vector2f position) {
    enemy.setPosition(position);
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(enemy);
}

/* --------------- ASTRONAUT --------------- */

Astronaut::Astronaut(sf::Vector2f size, sf::Texture* texture, sf::Vector2f position) : Enemy(size, texture, position) {}

