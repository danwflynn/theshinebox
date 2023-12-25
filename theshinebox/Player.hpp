#pragma once

#include <SFML/Graphics.hpp>

class Player
{
	bool crouching;
	bool dead;
	bool onGround;

	float verticalSpeed;
	float horizontalSpeed;
	float x;
	float y;

	sf::Sprite sprite;
	sf::Texture texture;

public:
	bool getDead() const;
	float getVerticalSpeed() const;
	float getHorizontalSpeed() const;
	float getX() const;
	float getY() const;

	void draw(sf::RenderWindow& i_window);

};