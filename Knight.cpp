#include "Knight.h"

Knight::Knight(bool isWhite) : Piece('n')
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
int Knight::pieceLegality(const string route, Piece*** board)
{
	string destination;
	string source;
	utility::separateMove(route, source, destination);

	return (abs(destination[0] - source[0]) == 2 && abs(destination[1] - source[1]) == 1) ||
		(abs(destination[0] - source[0]) == 1 && abs(destination[1] - source[1]) == 2) ? NORMAL_MOVE : DENIED_MOVE;
}
