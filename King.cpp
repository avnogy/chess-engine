#include "King.h"

King::King(bool isWhite, string position) : Piece('k', position)
{
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}

King::~King()
{
}

// returns true if position is next to the current position
bool King::pieceLegality(string position) const
{
	string destination;
	string source;
	utility::separateMove(position, source, destination);

	// returns true if difference between row, column or both is 1
	return abs(source[0] - destination[0]) == 1 || abs(source[1] - destination[1]) == 1;
}
