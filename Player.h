#pragma once
#include "Utility.h"
class Player
{
public:
	// constructor & destructor
	Player(const bool isWhite);
	~Player();

	//getter
	bool isWhite() const;
	// public fields
	string _kingPosition = "";
private:
	// fields
	bool _isWhite;
};