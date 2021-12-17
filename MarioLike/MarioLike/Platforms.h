#include <SFML/Graphics.hpp>


class Platforms
{
public:
	sf::Vector2u size;
	sf::Sprite platform;
	sf::Texture platforms_texture;
	sf::FloatRect boundingBox;

	Platforms(float, float);
	~Platforms();


};