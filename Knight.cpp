#include "Knight.h"

Knight::Knight(bool isWhite, string position) : Piece('n', position)
{
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}

Knight::~Knight()
{
}
