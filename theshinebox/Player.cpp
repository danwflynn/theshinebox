#include "Player.hpp"

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
		else horizontalSpeed = 0;
	}
	else if (0 == (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		stopMoving();
	}

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 1 == onGround)
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
	if (horizontalSpeed > 0) {
		horizontalSpeed -= HORIZONTAL_ACCELERATION;
	}
	else if (horizontalSpeed < 0) {
		horizontalSpeed += HORIZONTAL_ACCELERATION;
	}
}

void Player::jump()
{
	verticalSpeed = STARTING_JUMP_VELOCITY;
}

Player::Player() :
	crouching(0),
	dead(0),
	onGround(0),
	verticalSpeed(0),
	horizontalSpeed(0),
	x(400),
	y(300),
	jumpTimer(0)
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
	onGround = round(y + PLAYER_HEIGHT / 2) == 1000;

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
}