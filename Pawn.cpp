#include "Pawn.h"

// position string indexes
#define COL 0
#define ROW 1

Pawn::Pawn(bool isWhite, string position) : Piece('p', position)
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
bool Pawn::pieceLegality(string position) const
{
	string destination = "";
	string source = "";
	int forwardDirection = 1;
	bool isInInitialPosition = false;
	utility::separateMove(position, source, destination);

	if (islower(this->_pieceType)) // if pawn is black
	{
		forwardDirection = -1; // forward direction is flipper
	}

	isInInitialPosition = isupper(this->_pieceType) && source[ROW] == WHITE_INITIAL_ROW ||
							islower(this->_pieceType) && source[ROW] == BLACK_INITIAL_ROW;
	if (isInInitialPosition && destination[COL] == source[COL] && (int)destination[ROW] == ((int)source[ROW] + 2) * forwardDirection)
	{
		return true; // pawn can move two steps forward if in initial position
	}
	else if (destination[COL] == source[COL] && (int)destination[ROW] == ((int)source[ROW] + 1) * forwardDirection)
	{
		return true; // pawn can move 1 step forward
	}

	// TODO: add capturing
	// TODO: google en passant
	// TODO: say "holy hell" and add en passant

	return false;
}
