#include "Player.hpp"
#include <cstdlib>
#include <iostream>

void Player::handleInput()
{
	if (1 == (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ^ sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			moveLeft();
		}
		else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
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
	if (horizontalSpeed > -PLAYER_WALK_SPEED)
	horizontalSpeed -= HORIZONTAL_ACCELERATION;
}

void Player::moveRight()
{
	if (horizontalSpeed < PLAYER_WALK_SPEED)
		horizontalSpeed += HORIZONTAL_ACCELERATION;
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

Player::Player() :
	crouching(0),
	dead(0),
	onGround(0),
	verticalSpeed(0),
	horizontalSpeed(0),
	x(400),
	y(300),
	jumpDuration(1),
	prevJumpDur(0)
{
	texture.loadFromFile("mario.png");
	sprite.setTexture(texture);
}

void Player::draw(sf::RenderWindow& i_window) 
{
	sprite.setPosition(x - PLAYER_WIDTH / 2, y - PLAYER_HEIGHT / 2);
	i_window.draw(sprite);
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
	//std::cout << horizontalSpeed << std::endl;
}
