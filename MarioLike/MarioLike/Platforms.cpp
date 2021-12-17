#include "Platforms.h"

Platforms::Platforms(float x, float y)
{
	this->platforms_texture.loadFromFile("../../Sprites/platform.png");
	this->platform.setTexture(platforms_texture);

	this->platform.setPosition(x, y);

	this->boundingBox = platform.getGlobalBounds();
}