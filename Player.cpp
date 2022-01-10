#include "Player.h"

Player::Player(const bool isBlack) :_isWhite(!isBlack)
{
	//sets initial king position according to color
	if (isBlack)
	{
		this->_kingPosition = "e8";
	}
	else
	{
		this->_kingPosition = "e1";
	}
}

Player::~Player()
{
}

//getter
bool Player::isWhite() const
{
	return this->_isWhite;
}

