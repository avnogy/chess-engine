#pragma once
#include "Utility.h"
class Player
{
public:
	// constructor & destructor
	Player(const bool isWhite);
	~Player();

	// public fields
	string _kingPosition = "";
private:
	// fields
	bool _isWhite;
};