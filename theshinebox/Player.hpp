#pragma once

#include <SFML/Graphics.hpp>

constexpr float PLAYER_WIDTH = 52;
constexpr float PLAYER_HEIGHT = 124;
constexpr float PLAYER_WALK_SPEED = 0.3f;
constexpr float GRAVITY = 0.001f;
constexpr float SHORT_JUMP_VELOCITY = -0.45f;
constexpr float JUMP_VELOCITY = -0.65f;
constexpr float HORIZONTAL_ACCELERATION = 0.001f;

constexpr unsigned char JUMP_TIMER_MAX = 180;
constexpr unsigned short LOOPS_PER_ANIMATION_FRAME = 150;

class Player
{
	bool crouching;
	bool dead;
	bool onGround;

	float verticalSpeed;
	float horizontalSpeed;
	float x;
	float y;

	unsigned char jumpDuration;
	unsigned char prevJumpDur;
	unsigned short walkTimer;

	sf::Sprite sprite;
	sf::Texture texture;
	sf::Texture jumpTexture;
	sf::Texture prejumpTexture;
	sf::Texture crouchTexture;
	sf::Texture walkTextures[6];

	void handleInput();
	void handleSprites();
	void moveLeft();
	void moveRight();
	void stopMoving();
	void jump();
	void shortJump();

public:
	Player(float x, float y);

	void draw(sf::RenderWindow& i_window);
	void update();
};