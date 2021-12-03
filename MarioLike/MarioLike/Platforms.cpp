#include "Platforms.h"

Platforms::Platforms()
{
	this->platforms_texture.loadFromFile("../../Sprites/platform.png");
	this->platform.setTexture(platforms_texture);

	this->platform.setPosition(sf::Vector2f(20.f, 900.f));

	this->boundingBox = platform.getGlobalBounds();
}