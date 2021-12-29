#pragma once
#include "Utility.h"

class Piece
{
public:
	//constructor and destructor.
	Piece();
	~Piece();

	//checks if the source and destination squares are equal.
	bool boardLegality(const string input);

	//checks if destination square is according to piece movement.
	//this function is created for each piece type.
	virtual bool pieceLegality(const string input) = 0;

	string _position;
	char _pieceType;
};