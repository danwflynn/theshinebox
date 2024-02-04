#include "Map.hpp"

Map::Map()
{
	sf::RectangleShape bg = sf::RectangleShape(sf::Vector2f(1400, 80));
	bg.setPosition(0, 920);
	bg.setFillColor(sf::Color(179, 142, 32));
	this->baseGround = bg;

	Platform plat1 = Platform(600, 800, 770);
	Platform plat2 = Platform(400, 600, 620);
	Platform plat3 = Platform(800, 1000, 620);
	this->platforms.push_back(plat1);
	this->platforms.push_back(plat2);
	this->platforms.push_back(plat3);
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