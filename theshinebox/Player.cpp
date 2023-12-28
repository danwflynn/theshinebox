#include "Player.hpp"
#include <cstdlib>

void Player::handleInput()
{
	if (1 == (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ^ sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (onGround) sprite.setScale(-1.f, 1.f);
			moveLeft();
		}
		else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (onGround) sprite.setScale(1.f, 1.f);
			moveRight();
		}
		else stopMoving();
	}
	else if (0 == (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		stopMoving();
	}
	
	prevJumpDur = jumpDuration;

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && verticalSpeed == 0)
	{
		if (jumpDuration < JUMP_TIMER_MAX) jumpDuration++;
	}

	if (jumpDuration != 0 && 1 == onGround && jumpDuration == prevJumpDur)
	{
		shortJump();
	}
	
	if (jumpDuration == JUMP_TIMER_MAX && 1 == onGround)
	{
		jump();
	}
}

void Player::moveLeft()
{
	if (horizontalSpeed > -PLAYER_WALK_SPEED) horizontalSpeed -= HORIZONTAL_ACCELERATION;
}

void Player::moveRight()
{
	if (horizontalSpeed < PLAYER_WALK_SPEED) horizontalSpeed += HORIZONTAL_ACCELERATION;
}

void Player::stopMoving()
{
	if (abs(horizontalSpeed) > 1e-08)
	{
		if (horizontalSpeed > 0) {
			horizontalSpeed -= HORIZONTAL_ACCELERATION;
		}
		else if (horizontalSpeed < 0) {
			horizontalSpeed += HORIZONTAL_ACCELERATION;
		}
	}
	else
	{
		horizontalSpeed = 0;
	}
}

void Player::jump()
{
	verticalSpeed = JUMP_VELOCITY;
	jumpDuration = 0;
}

void Player::shortJump()
{
	verticalSpeed = SHORT_JUMP_VELOCITY;
	jumpDuration = 0;
}

Player::Player(float x, float y) :
	crouching(0),
	dead(0),
	onGround(0),
	verticalSpeed(0),
	horizontalSpeed(0),
	x(x),
	y(y),
	jumpDuration(1),
	prevJumpDur(0)
{
	texture.loadFromFile("msuit.png");
	jumpTexture.loadFromFile("msuitjump.png");
	sprite.setTexture(texture);
	sprite.setOrigin(PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2);
}

void Player::draw(sf::RenderWindow& window) 
{
	sprite.setPosition(x, y);
	window.draw(sprite);
}

void Player::update() 
{
	onGround = y + PLAYER_HEIGHT / 2 > 999;

	if (onGround == 0)
	{
		verticalSpeed += GRAVITY;
	}
	else
	{
		verticalSpeed = 0;
	}

	handleInput();


	x += horizontalSpeed;
	y += verticalSpeed;
	if (abs(verticalSpeed) > 1e-08)
	{
		sprite.setTexture(jumpTexture);
	}
	else
	{
		sprite.setTexture(texture);
	}
}
