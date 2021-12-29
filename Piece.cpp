#include "Piece.h"

Piece::Piece(char type, string position):
	_pieceType(type), _position(position)
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

string Piece::getPosition() const
{
	return this->_position;
}

void Piece::setPosition(const string new_position)
{
	this->_position = new_position;
}

char Piece::getPieceType() const
{
	return this->_pieceType;
}

void Piece::setPieceType(const char new_type)
{
	this->_pieceType = new_type;
}

