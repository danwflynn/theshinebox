#pragma once

#include <SFML/Graphics.hpp>
#include "Map.hpp"

constexpr float PLAYER_WIDTH = 52;
constexpr float PLAYER_HEIGHT = 124;
constexpr float PLAYER_WALK_SPEED = 0.3f;
constexpr float GRAVITY = 0.001f;
constexpr float SHORT_JUMP_VELOCITY = -0.45f;
constexpr float JUMP_VELOCITY = -0.65f;
constexpr float HORIZONTAL_ACCELERATION = 0.001f;
constexpr float HORIZONTAL_HITBOX_BUFFER = 4;
constexpr float MAX_HEALTH = 100;

constexpr unsigned char JUMP_TIMER_MAX = 180;
constexpr unsigned short LOOPS_PER_ANIMATION_FRAME = 150;

class Player
{
	bool crouching;
	bool dead;
	bool onGround;

	float verticalSpeed;
	float horizontalSpeed;
	float health;
	float prevVerticalSpeed;

	unsigned char jumpDuration;
	unsigned char prevJumpDur;
	unsigned short walkTimer;

	Map* map;

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
	void takeFallDamage();

public:
	float x;
	float y;

	Player(float x, float y, Map* map);

	void draw(sf::RenderWindow& window);
	void update();
	void draw_attributes(sf::RenderWindow& window, float xPos, float yPos);
};