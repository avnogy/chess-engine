#include "Rook.h"

Rook::Rook(bool isWhite, string position) : Piece('r', position)
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
bool Rook::pieceLegality(string position) const
{
	string destination;
	string source;
	utility::separateMove(position, source, destination);

	return destination[0] == source[0] || destination[1] == source[1];
}
