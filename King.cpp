#include "King.h"

King::King(bool isWhite) : Piece('k')
{
	this->_canCastle = true;
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}

King::~King()
{
}

// returns true if position is next to the current position
bool King::pieceLegality(const string route, Piece*** board) const
{
	string destination;
	string source;
	utility::separateMove(route, source, destination);

	// returns true if difference between row, column or both is 1
	return abs(source[0] - destination[0]) == 1 || abs(source[1] - destination[1]) == 1;
}
