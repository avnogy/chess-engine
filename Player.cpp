#include "Player.h"

Player::Player(const bool isWhite):_isWhite(isWhite)
{
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

