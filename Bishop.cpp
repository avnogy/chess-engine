#include "Bishop.h"

Bishop::Bishop(bool isWhite, string position) : Piece('b', position)
{
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}

Bishop::~Bishop()
{
}
