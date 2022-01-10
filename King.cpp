#include "King.h"
#include "Rook.h"

King::King(bool isWhite) : Piece('k')
{
	this->_canCastle = true;
	if (isWhite)
	{
		this->_pieceType = toupper(this->_pieceType);
	}
}

King::~King()
{
}

// returns true if position is next to the current position
int King::pieceLegality(const string route, Piece*** board)
{
	string destination;
	string source;
	utility::separateMove(route, source, destination);

	// returns true if difference between row, column or both is 1
	if (abs(source[0] - destination[0]) == 1 || abs(source[1] - destination[1]) == 1)
	{
		setCastleFlag(false);
		return NORMAL_MOVE;
	}
	else if (source[1] == destination[1] && abs(source[0] - destination[0]) == 2)
	{
		if (this->_canCastle)
		{
			if (source[0] - destination[0] > 0) //if went left
			{
				if (!this->getPieceColor())//if white
				{
					if (board[0][0]->getPieceType() == 'r' && ((Rook*)board[0][0])->canCastle())
					{
						return CASTLING;
					}
				}
				else //black
				{
					if (board[7][7]->getPieceType() == 'R' && ((Rook*)board[7][7])->canCastle())
					{
						return CASTLING;
					}
				}
			}
			else //went right
			{
				if (!this->getPieceColor())//if white
				{
					if (board[0][7]->getPieceType() == 'r' && ((Rook*)board[7][7])->canCastle())
					{
						return CASTLING;
					}
				}
				else //black
				{
					if (board[7][0]->getPieceType() == 'R' && ((Rook*)board[0][0])->canCastle())
					{
						return CASTLING;
					}
				}
			}
		}

	}
	return DENIED_MOVE;
}

//getter
bool King::canCastle() const
{
	return this->_canCastle;
}

//setter
void King::setCastleFlag(const bool newState)
{
	this->_canCastle = newState;
}
