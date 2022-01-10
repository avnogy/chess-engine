#include "Piece.h"

Piece::Piece(char type):
	_pieceType(type)
{
}

Piece::~Piece()
{
}

//checks if piece moves
bool Piece::doesMove(const string input) const
{
	string src = "", dst = "";
	utility::separateMove(input, src, dst);

	return src == dst;
}

//getters and setters
bool Piece::getPieceColor()
{
	//TODO: check if works 
	return isupper(getPieceType());
}

//getter
char Piece::getPieceType() const
{
	return this->_pieceType;
}

//setter
void Piece::setPieceType(const char new_type)
{
	this->_pieceType = new_type;
}

