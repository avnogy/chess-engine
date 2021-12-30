#include "Queen.h"

Queen::Queen(bool isWhite, string position) : Piece('q', position)
{
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}