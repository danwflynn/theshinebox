#pragma once

#include <SFML/Graphics.hpp>

constexpr float PLATFORM_HEIGHT = 15;

class MapPiece
{
protected:
	sf::RectangleShape sprite;
	float xLeft;
	float xRight;
	float yTop;
	float yBottom;

public:
	bool touchingGround(float xLeft, float xRight, float yBottom);
	void draw(sf::RenderWindow& window);
};

class Platform : MapPiece
{
public:
	Platform(float xLeft, float xRight, float yTop);
};
