#pragma once
#include "Utility.h"
class Player
{
public:
	// constructor & destructor
	Player(const bool isBlack);
	~Player();

	//getter
	bool isWhite() const;

	// fields
	string _kingPosition = "";
private:
	// fields
	bool _isWhite;
};