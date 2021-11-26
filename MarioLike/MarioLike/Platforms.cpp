#include "Platforms.h"

Platforms::Platforms()
{
	this->platforms_texture.loadFromFile("../../Sprites/platform.png");
	this->platform.setTexture(platforms_texture);

	this->platform.setPosition(sf::Vector2f(10.f, 800.f));

	this->boundingBox = platform.getGlobalBounds();
}