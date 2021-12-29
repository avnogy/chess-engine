#pragma once
#include "Utility.h"
class Player
{
public:
	Player(const bool isWhite);
	~Player();
	string kingPosition = "";
private:
	bool isWhite;
};