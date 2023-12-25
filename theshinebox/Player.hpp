#pragma once

#include <SFML/Graphics.hpp>

constexpr float PLAYER_WIDTH = 52;
constexpr float PLAYER_HEIGHT = 110;
constexpr float PLAYER_WALK_SPEED = 0.5;
constexpr float GRAVITY = 0.001;

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
	Player();

	bool getDead() const;
	float getVerticalSpeed() const;
	float getHorizontalSpeed() const;
	float getX() const;
	float getY() const;

	void draw(sf::RenderWindow& i_window);
	void update();
};