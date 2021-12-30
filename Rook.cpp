#include "Rook.h"

Rook::Rook(bool isWhite, string position) : Piece('r', position)
{
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}