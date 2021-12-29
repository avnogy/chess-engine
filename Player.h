#pragma once
#include "Utility.h"
class Player
{
public:
	Player(const bool isWhite);
	~Player();
	char kingPosition[3];
private:
	bool isWhite;
};