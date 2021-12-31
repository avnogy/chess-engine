#include "Piece.h"

Piece::Piece(char type):
	_pieceType(type)
{
}

Piece::~Piece()
{
}

bool Piece::boardLegality(const string input)
{
	//TODO: call all engine functions to check position 
	return false;
}


//getters and setters
bool Piece::getPieceColor()
{
	//TODO: check if works 
	return isupper(getPieceType());
}

char Piece::getPieceType() const
{
	return this->_pieceType;
}

void Piece::setPieceType(const char new_type)
{
	this->_pieceType = new_type;
}

