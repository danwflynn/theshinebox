#pragma once

#include <SFML/Graphics.hpp>

//define constants for window dimensions

class Camera 
{
public:
	Camera(sf::RenderWindow& window);
	void update(float x, float y);

private:
	sf::RenderWindow& window;
	sf::View view;
};