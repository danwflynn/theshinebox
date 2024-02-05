#pragma once

#include <SFML/Graphics.hpp>

constexpr float PLATFORM_HEIGHT = 15;

class Platform
{
	sf::RectangleShape sprite;
	float xLeft;
	float xRight;
	float yTop;

public:
	Platform(float xLeft, float xRight, float yTop);
	bool touchingGround(float xLeft, float xRight, float yBottom, float verticalSpeed);
	void draw(sf::RenderWindow& window);
};

class MapBlock
{
	sf::RectangleShape sprite;
	float xLeft;
	float xRight;
	float yTop;
	float yBottom;

public:
	MapBlock(sf::Vector2f position, float width, float height);
	bool touchingGround(float xLeft, float xRight, float yBottom, float verticalSpeed);
	bool touchingCeiling(float xLeft, float xRight, float yTop, float verticalSpeed);
	bool touchingLeftWall(float xRight, float yTop, float yBottom, float horizontalSpeed);
	bool touchingRightWall(float xLeft, float yTop, float yBottom, float horizontalSpeed);
	void draw(sf::RenderWindow& window);
};
