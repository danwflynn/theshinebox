#include "Map.hpp"

Map::Map()
{
	sf::RectangleShape bg = sf::RectangleShape(sf::Vector2f(1400, 80));
	bg.setPosition(0, 920);
	bg.setFillColor(sf::Color(179, 142, 32));
	this->baseGround = bg;
}

bool Map::touchingGround(float xLeft, float xRight, float yBottom)
{
	return yBottom >= this->baseGround.getPosition().y;
}

void Map::draw(sf::RenderWindow& window)
{
	window.draw(this->baseGround);
}