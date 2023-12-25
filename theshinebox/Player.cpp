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

void Player::draw(sf::RenderWindow& i_window) 
{
	sprite.setPosition(x - PLAYER_WIDTH / 2, y - PLAYER_HEIGHT / 2);
	i_window.draw(sprite);
}

void Player::update() 
{
	onGround = round(y + PLAYER_HEIGHT / 2) == 1000;

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		x -= PLAYER_WALK_SPEED;
	}
	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		x += PLAYER_WALK_SPEED;
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
		verticalSpeed = -0.7;
	}

	y += verticalSpeed;
}