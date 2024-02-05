#include "Map.hpp"

Map::Map()
{
	sf::RectangleShape bg = sf::RectangleShape(sf::Vector2f(1400, 80));
	bg.setPosition(0, 920);
	bg.setFillColor(sf::Color(179, 142, 32));
	this->baseGround = bg;

	this->platforms.push_back(Platform(600, 800, 770));
	this->platforms.push_back(Platform(400, 600, 620));
	this->platforms.push_back(Platform(800, 1000, 620));
	this->platforms.push_back(Platform(300, 1100, 470));
}

bool Map::touchingGround(float xLeft, float xRight, float yBottom, float verticalSpeed)
{
	for (Platform platform : this->platforms) {
		if (platform.touchingGround(xLeft, xRight, yBottom, verticalSpeed)) return true;
	}
	return yBottom >= this->baseGround.getPosition().y;
}

void Map::draw(sf::RenderWindow& window)
{
	window.draw(this->baseGround);
	for (Platform platform : this->platforms) {
		platform.draw(window);
	}
}