#include "Bishop.h"

Bishop::Bishop(bool isWhite, string position) : Piece('b', position)
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
bool Bishop::pieceLegality(string position) const
{
	string destination;
	string source;
	utility::separateMove(position, source, destination);
	// if the difference between each coordinate of destination and source is equal
	// then they are located diagonally from each other
	return abs(destination[0] - source[0]) == abs(destination[1] - source[1]);
}
