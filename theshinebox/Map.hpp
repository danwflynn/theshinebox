#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "MapPieces.hpp"

class Map
{
	sf::RectangleShape baseGround;
	std::vector<Platform> platforms;

public:
	Map();
	bool touchingGround(float xLeft, float xRight, float yBottom);
	bool touchingWall(float xLeft, float xRight, float yTop, float yBottom);
	void draw(sf::RenderWindow& window);
};
