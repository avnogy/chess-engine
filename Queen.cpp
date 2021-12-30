#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"

Queen::Queen(bool isWhite, string position) : Piece('q', position)
{
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}

Queen::~Queen()
{
}

// returns true if either rook or bishop can move to the destination
bool Queen::pieceLegality(string position) const
{
	return ((Rook*)this)->boardLegality(position) || ((Bishop*)this)->boardLegality(position);
}
