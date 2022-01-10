#include "Rook.h"

Rook::Rook(bool isWhite) : Piece('r')
{
	this->_canCastle = true;
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}

Rook::~Rook()
{
}

// returns true if destination is on the same row or on the same column as the source
int Rook::pieceLegality(const string route, Piece*** board)
{
	string destination;
	string source;
	utility::separateMove(route, source, destination);

	if (destination[0] == source[0] || destination[1] == source[1])
	{
		setCastleFlag(false);
		return NORMAL_MOVE;
	}
	return DENIED_MOVE;
}

bool Rook::canCastle() const
{
	return this->_canCastle;
}

void Rook::setCastleFlag(const bool newState)
{
	this->_canCastle = newState;
}