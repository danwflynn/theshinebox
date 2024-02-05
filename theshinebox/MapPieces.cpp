#include "MapPieces.hpp"
#include <cstdlib>

bool Platform::touchingGround(float xL, float xR, float yB, float verticalSpeed)
{
	return ((xL >= xLeft && xL <= xRight) || (xR >= xLeft && xR <= xRight)) && abs(yB - yTop) < 0.5f && verticalSpeed >= 0;
}

void Platform::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

Platform::Platform(float xLeft, float xRight, float yTop) :
	xLeft(xLeft),
	xRight(xRight),
	yTop(yTop)
{
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(xRight - xLeft, PLATFORM_HEIGHT));
	shape.setPosition(xLeft, yTop);
	shape.setFillColor(sf::Color(255, 112, 212));
	this->sprite = shape;
}

bool MapBlock::touchingGround(float xL, float xR, float yB, float verticalSpeed)
{
	return ((xL >= xLeft && xL <= xRight) || (xR >= xLeft && xR <= xRight)) && abs(yB - yTop) < 0.5f && verticalSpeed >= 0;
}

bool MapBlock::touchingCeiling(float xL, float xR, float yT, float verticalSpeed)
{
	return ((xL >= xLeft && xL <= xRight) || (xR >= xLeft && xR <= xRight)) && abs(yT - yBottom) < 0.5f && verticalSpeed < 0;
}

bool MapBlock::touchingLeftWall(float xRight, float yTop, float yBottom, float horizontalSpeed)
{
	return false;
}

bool MapBlock::touchingRightWall(float xLeft, float yTop, float yBottom, float horizontalSpeed)
{
	return false;
}

void MapBlock::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

MapBlock::MapBlock(sf::Vector2f position, float width, float height) :
	xLeft(position.x),
	xRight(position.x + width),
	yTop(position.y),
	yBottom(position.y + height)
{
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(width, height));
	shape.setPosition(position);
	shape.setFillColor(sf::Color(179, 142, 32));
	this->sprite = shape;
}
