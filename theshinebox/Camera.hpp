#pragma once

#include <SFML/Graphics.hpp>

class Camera 
{
public:
	Camera(sf::RenderWindow& window);
	void update(sf::Vector2f targetPosition);

private:
	sf::RenderWindow& window;
	sf::View view;
};