#include "Bishop.h"

Bishop::Bishop(bool isWhite) : Piece('b')
{
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}

Bishop::~Bishop()
{
}

// returns true if destination is located diagonally from the source
bool Bishop::pieceLegality(const string route, Piece*** board)
{
	string destination;
	string source;
	utility::separateMove(route, source, destination);
	// if the difference between each coordinate of destination and source is equal
	// then they are located diagonally from each other
	return abs(destination[0] - source[0]) == abs(destination[1] - source[1]);
}
