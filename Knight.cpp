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

// im really not sure how the horsey moves tbh
bool Knight::pieceLegality(string position) const
{
	string destination;
	string source;
	utility::separateMove(position, source, destination);

	return abs(destination[0] - source[0]) == 2 && abs(destination[1] - source[1]) == 1 ||
		abs(destination[0] - source[0]) == 1 && abs(destination[1] - source[1]) == 2;
}
