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
	void draw(sf::RenderWindow& window);
};
