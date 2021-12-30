#include "King.h"

King::King(bool isWhite, string position) : Piece('k', position)
{
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}