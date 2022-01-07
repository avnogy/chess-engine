#include "Pawn.h"

// position string indexes
#define COL 0
#define ROW 1

Pawn::Pawn(bool isWhite) : Piece('p')
{
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}

Pawn::~Pawn()
{
}

// returns true if pawn can move to the destination
bool Pawn::pieceLegality(const string route, Piece*** board) const
{
	string destination = "";
	string source = "";
	int forwardDirection = 1;
	int destRow = 0;
	int destCol = 0;
	bool isInInitialPosition = false;
	utility::separateMove(route, source, destination);
	utility::stringToIndexes(destination, destRow, destCol);

	if (islower(this->_pieceType)) // if pawn is black
	{
		forwardDirection = -1; // forward direction is flipper
	}

	isInInitialPosition = isupper(this->_pieceType) && source[ROW] == WHITE_INITIAL_ROW ||
							islower(this->_pieceType) && source[ROW] == BLACK_INITIAL_ROW;
	if (isInInitialPosition && destination[COL] == source[COL] && (int)destination[ROW] == (int)source[ROW] + 2 * forwardDirection)
	{
		return true; // pawn can move two steps forward if in initial position
	}

	if (destination[COL] == source[COL] && (int)destination[ROW] == (int)source[ROW] + 1 * forwardDirection)
	{
		return true; // pawn can move 1 step forward
	}

	if (abs(destination[COL] - source[COL]) == 1 // goes 1 space to either side
		&& (int)destination[ROW] == (int)source[ROW] + 1 * forwardDirection // goes 1 forward
		&& board[destRow][destCol]->getPieceType() != '#' // lands on a piece
		&& isupper(board[destRow][destCol]->getPieceType()) != isupper(this->getPieceType())) // does not land of friendly piece
	{
		return true;
	}
	// TODO: google en passant
	// TODO: say "holy hell" and add en passant

	return false;
}
