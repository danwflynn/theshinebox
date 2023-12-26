#pragma once

#include <SFML/Graphics.hpp>

constexpr float PLAYER_WIDTH = 52;
constexpr float PLAYER_HEIGHT = 110;
constexpr float PLAYER_WALK_SPEED = 0.3;
constexpr float GRAVITY = 0.001;
constexpr float STARTING_JUMP_VELOCITY = -0.55;
constexpr float HORIZONTAL_ACCELERATION = 0.001;
constexpr unsigned char JUMP_TIMER = 8;

class Player
{
	bool crouching;
	bool dead;
	bool onGround;

	float verticalSpeed;
	float horizontalSpeed;
	float x;
	float y;

	unsigned char jumpTimer;

	sf::Sprite sprite;
	sf::Texture texture;

	void handleInput();
	void moveLeft();
	void moveRight();
	void stopMoving();
	void jump();

public:
	Player();

	void draw(sf::RenderWindow& i_window);
	void update();
};