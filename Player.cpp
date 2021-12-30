#include "Player.h"

Player::Player(const bool isWhite):_isWhite(isWhite)
{
	//sets initial king position according to color
	if (isWhite)
	{
		this->_kingPosition = "e1";
	}
	else
	{
		this->_kingPosition = "e8";
	}
}

Player::~Player()
{
}

bool Player::isWhite() const
{
	return this->_isWhite;
}

