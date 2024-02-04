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
	yTop(yTop),
	yBottom(yTop + PLATFORM_HEIGHT)
{
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(xRight - xLeft, PLATFORM_HEIGHT));
	shape.setPosition(xLeft, yTop);
	shape.setFillColor(sf::Color(255, 112, 212));
	this->sprite = shape;
}
