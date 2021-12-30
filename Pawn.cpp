#include "Pawn.h"

Pawn::Pawn(bool isWhite, string position) : Piece('p', position)
{
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}