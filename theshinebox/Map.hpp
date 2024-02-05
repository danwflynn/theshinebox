#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "MapPieces.hpp"

class Map
{
	sf::RectangleShape baseGround;
	std::vector<Platform> platforms;
	std::vector<MapBlock> blocks;

public:
	Map();
	bool touchingGround(float xLeft, float xRight, float yBottom, float verticalSpeed);
	bool touchingCeiling(float xLeft, float xRight, float yTop, float verticalSpeed);
	bool touchingLeftWall(float xRight, float yTop, float yBottom, float horizontalSpeed);
	bool touchingRightWall(float xLeft, float yTop, float yBottom, float horizontalSpeed);
	void draw_backside(sf::RenderWindow& window);
	void draw_frontside(sf::RenderWindow& window);
};
