#pragma once
#include "Utility.h"
class Player
{
public:
	Player(const bool isWhite);
	~Player();
	char* kingPosition = "";
private:
	bool isWhite;
};