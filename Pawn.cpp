#include "Pawn.h"
#include "Empty.h"

// position string indexes
#define COL 0
#define ROW 1

class Empty;

Pawn::Pawn(bool isWhite) : Piece('p')
{
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
	this->_enPassantFlag = false;
}

Pawn::~Pawn()
{
}

// returns true if pawn can move to the destination
bool Pawn::pieceLegality(const string route, Piece*** board)
{
	string destination = "";
	string source = "";
	int forwardDirection = 1;
	int destRow = 0, destCol = 0;
	int srcRow = 0, srcCol = 0;
	bool isInInitialPosition = false;
	
	utility::separateMove(route, source, destination);
	utility::stringToIndexes(destination, destRow, destCol);
	utility::stringToIndexes(source, srcRow, srcCol);

	if (isupper(this->_pieceType)) // if pawn is black
	{
		forwardDirection = -1; // forward direction is flipped
	}

	isInInitialPosition = islower(this->_pieceType) && source[ROW] == WHITE_INITIAL_ROW ||
							isupper(this->_pieceType) && source[ROW] == BLACK_INITIAL_ROW;
	if (isInInitialPosition && destination[COL] == source[COL] && (int)destination[ROW] == (int)source[ROW] + 2 * forwardDirection)
	{
		setEnPassantFlag(true);
		return true; // pawn can move two steps forward if in initial position
	}

	if (destination[COL] == source[COL] && (int)destination[ROW] == (int)source[ROW] + 1 * forwardDirection)
	{
		return board[destRow][destCol]->getPieceType() == '#'; // pawn can move 1 step forward if there is no piece there
	}

	if (abs(destination[COL] - source[COL]) == 1 // goes 1 space to either side
		&& (int)destination[ROW] == (int)source[ROW] + 1 * forwardDirection // goes 1 forward
		&& board[destRow][destCol]->getPieceType() != '#' // lands on a piece
		&& isupper(board[destRow][destCol]->getPieceType()) != isupper(this->getPieceType())) // does not land on friendly piece
	{
		return true;
	}
	
	if (abs(destination[COL] - source[COL]) == 1 // goes 1 space to the side
		&& (int)destination[ROW] == (int)source[ROW] + 1 * forwardDirection // goes 1 space forward
		&& ((Pawn*)board[srcRow][destCol])->canBeTakenEnPassant()) // can take en passant
	{
		// holy hell
		delete (Pawn*)board[srcRow][destCol];
		board[srcRow][destCol] = new Empty();
		return true;
	}

	return false;
}

bool Pawn::canBeTakenEnPassant() const
{
	return this->_enPassantFlag;
}

void Pawn::setEnPassantFlag(const bool newState)
{
	this->_enPassantFlag = newState;
}
