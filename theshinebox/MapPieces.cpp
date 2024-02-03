#include "MapPieces.hpp"

bool MapPiece::touchingGround(float xLeft, float xRight, float yBottom)
{
	//TODO: Implement this
	return false;
}

void MapPiece::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

Platform::Platform(float xLeft, float xRight, float yTop)
{
	this->xLeft = xLeft;
	this->xRight = xRight;
	this->yTop = yTop;
	this->yBottom = yTop + PLATFORM_HEIGHT;

	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(xRight - xLeft, PLATFORM_HEIGHT));
	shape.setPosition(xLeft, yTop);
	shape.setFillColor(sf::Color(255, 112, 212));
	this->sprite = shape;
}
