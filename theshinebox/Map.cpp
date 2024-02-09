#include "Map.hpp"
#include <cstdlib>

Map::Map()
{
	sf::RectangleShape bg = sf::RectangleShape(sf::Vector2f(2000, 80));
	bg.setPosition(0, 920);
	bg.setFillColor(sf::Color(179, 142, 32));
	this->baseGround = bg;

	this->platforms.push_back(Platform(600, 800, 770));
	this->platforms.push_back(Platform(400, 600, 620));
	this->platforms.push_back(Platform(800, 1000, 620));
	this->platforms.push_back(Platform(300, 1100, 470));
	this->platforms.push_back(Platform(1200, 1275, 760));

	this->blocks.push_back(MapBlock(sf::Vector2f(1100, 600), 100, 320));
	this->blocks.push_back(MapBlock(sf::Vector2f(400, 200), 400, 100));
	this->blocks.push_back(MapBlock(sf::Vector2f(100, 840), 100, 40));
	this->blocks.push_back(MapBlock(sf::Vector2f(140, 640), 20, 40));
}

bool Map::touchingGround(float xLeft, float xRight, float yBottom, float verticalSpeed)
{
	for (Platform platform : this->platforms) {
		if (platform.touchingGround(xLeft, xRight, yBottom, verticalSpeed)) return true;
	}
	for (MapBlock block : this->blocks) {
		if (block.touchingGround(xLeft, xRight, yBottom, verticalSpeed)) return true;
	}
	return abs(yBottom - this->baseGround.getPosition().y) < 0.5f && verticalSpeed >= 0;
}

bool Map::touchingCeiling(float xLeft, float xRight, float yTop, float verticalSpeed)
{
	for (MapBlock block : this->blocks) {
		if (block.touchingCeiling(xLeft, xRight, yTop, verticalSpeed)) return true;
	}
	return false;
}

bool Map::touchingLeftWall(float xRight, float yTop, float yBottom, float horizontalSpeed)
{
	for (MapBlock block : this->blocks) {
		if (block.touchingLeftWall(xRight, yTop, yBottom, horizontalSpeed)) return true;
	}
	return false;
}

bool Map::touchingRightWall(float xLeft, float yTop, float yBottom, float horizontalSpeed)
{
	for (MapBlock block : this->blocks) {
		if (block.touchingRightWall(xLeft, yTop, yBottom, horizontalSpeed)) return true;
	}
	return xLeft <= 0 && horizontalSpeed <= 0;
}

void Map::draw_backside(sf::RenderWindow& window)
{
	window.draw(this->baseGround);
	for (MapBlock block : this->blocks) {
		block.draw(window);
	}
}

void Map::draw_frontside(sf::RenderWindow& window)
{
	for (Platform platform : this->platforms) {
		platform.draw(window);
	}
}
