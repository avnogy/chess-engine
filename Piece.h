#pragma once
#include "Utility.h"

class Piece
{
public:
	//constructor and destructor.
	Piece(char type);
	~Piece();

	//checks if the source and destination squares are equal.
	bool boardLegality(const string input);

	//checks if destination square is according to piece movement.
	//this function is created for each piece type.
	virtual bool pieceLegality(const string input) const = 0;

	//returns piece color
	bool getPieceColor();

	//getters and setters
	char getPieceType() const;
	void setPieceType(const char new_type);

protected:
	//fields
	char _pieceType;
};