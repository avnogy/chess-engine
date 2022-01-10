#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"

Queen::Queen(bool isWhite) : Piece('q')
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
int Queen::pieceLegality(const string route, Piece*** board)
{
	Rook* theoreticalRook = new Rook(isupper(this->getPieceType()));
	Bishop* theoreticalBishop = new Bishop(isupper(this->getPieceType()));
	bool canMove = theoreticalRook->pieceLegality(route, board) || theoreticalBishop->pieceLegality(route, board);

	delete theoreticalRook;
	delete theoreticalBishop;
	return canMove ? NORMAL_MOVE : DENIED_MOVE;
}