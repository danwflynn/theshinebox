#pragma once

#include <SFML/Graphics.hpp>

constexpr float PLATFORM_HEIGHT = 15;

class Platform
{
	sf::RectangleShape sprite;
	float xLeft;
	float xRight;
	float yTop;
	float yBottom;

public:
	Platform(float xLeft, float xRight, float yTop);
	bool touchingGround(float xLeft, float xRight, float yBottom, float verticalSpeed);
	void draw(sf::RenderWindow& window);
};
