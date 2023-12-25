#include "Player.hpp"

Player::Player() :
	crouching(0),
	dead(0),
	onGround(0),
	verticalSpeed(0),
	horizontalSpeed(0),
	x(400),
	y(300)
{
	texture.loadFromFile("mario.png");
	sprite.setTexture(texture);
}

bool Player::getDead() const
{
	return dead;
}

float Player::getVerticalSpeed() const
{
	return verticalSpeed;
}

float Player::getHorizontalSpeed() const
{
	return horizontalSpeed;
}

float Player::getX() const
{
	return x;
}

float Player::getY() const
{
	return y;
}

void Player::draw(sf::RenderWindow& i_window) 
{
	sprite.setPosition(x - PLAYER_WIDTH / 2, y - PLAYER_HEIGHT / 2);
	i_window.draw(sprite);
}

void Player::update() 
{
	onGround = round(y + PLAYER_HEIGHT / 2) == 1000;

	if (1 == (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ^ sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			horizontalSpeed = -PLAYER_WALK_SPEED;
		}
		else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			horizontalSpeed = PLAYER_WALK_SPEED;
		}
		else horizontalSpeed = 0;
	}
	else if (0 == (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		horizontalSpeed = 0;
	}

	if (onGround == 0)
	{
		verticalSpeed += GRAVITY;
	}
	else {
		verticalSpeed = 0;
	}

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 1 == onGround)
	{
		verticalSpeed = -0.55;
	}

	x += horizontalSpeed;
	y += verticalSpeed;
}