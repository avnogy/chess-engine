#include "Rook.h"

Rook::Rook(bool isWhite) : Piece('r')
{
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}

Rook::~Rook()
{
}

// returns true if destination is on the same row or on the same column as the source
bool Rook::pieceLegality(const string route) const
{
	string destination;
	string source;
	utility::separateMove(route, source, destination);

	return destination[0] == source[0] || destination[1] == source[1];
}
