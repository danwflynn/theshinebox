#include "Map.hpp"

Map::Map()
{
	sf::RectangleShape bg = sf::RectangleShape(sf::Vector2f(1400, 80));
	bg.setPosition(0, 920);
	bg.setFillColor(sf::Color(179, 142, 32));
	this->baseGround = bg;

	Platform plat1 = Platform(600, 800, 770);
	this->platforms.push_back(plat1);
}

bool Map::touchingGround(float xLeft, float xRight, float yBottom)
{
	for (Platform platform : this->platforms) {
		if (platform.touchingGround(xLeft, xRight, yBottom)) return true;
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