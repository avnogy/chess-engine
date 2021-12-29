#include "Player.h"

Player::Player(const bool isWhite):isWhite(isWhite)
{
	if (isWhite)
	{
		this->kingPosition = "e1";
	}
	else
	{
		this->kingPosition = "e8";
	}
}

Player::~Player()
{
}

