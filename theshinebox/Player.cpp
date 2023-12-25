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

