#include "Engine.h"


// returns true if source point is a piece that can move in this turn
bool Engine::canSrcMove(Game &game,string location)
{
	//seperating src and dst
	string src = "", dst = "";
	utility::separateMove(location, src, dst);

	//checking if piece at source is not empty
	Piece* piece = game.getPieceFromString(src);
	return (piece->getPieceType() != '#' && piece->getPieceColor() == game.currentPlayer);
}

// returns true if src can go there
bool Engine::isDstOccupied(Game& game, string location)
{
	//seperating src and dst locations
	string src = "", dst = "";
	utility::separateMove(location, src, dst);
	
	//getting piece from dst location
	Piece* dstPiece = nullptr;
	dstPiece = game.getPieceFromString(dst);

	//checking if piece is not same color as player or empty 
	char pType = dstPiece->getPieceType();
	return (pType != '#' && dstPiece->getPieceColor() == game.currentPlayer);
}

bool Engine::doesCauseDiscovery(Game& game, string location)
{
	//TODO: implement discovery
	return false;
}

//returns true if out of bounds
bool Engine::isOutOfBounds(string location)
{
	int row = 0, col = 0;
	string src = "", dst = "";
	
	//seperating src and dst
	utility::separateMove(location, src, dst);

	//checking if source is out of bounds
	utility::stringToIndexes(src, row, col);
	if (row < 0 || row >= BOARD_SIDE_LENGTH || col < 0 || col >= BOARD_SIDE_LENGTH)
	{
		return true;
	}

	//checking if destination is out of bounds
	utility::stringToIndexes(dst, row, col);
	if (row < 0 || row >= BOARD_SIDE_LENGTH || col < 0 || col >= BOARD_SIDE_LENGTH)
	{
		return true;
	}

	return false; // if neither src nor dst are out of bounds return false
}

bool Engine::areIndexesEqual(string location)
{
	//seperating src and dst
	string src = "", dst = ""; 
	utility::separateMove(location, src, dst);

	//checking if source and destination locations are equal
	return (src == dst);
}

bool Engine::isPathBlocked(Game& game, string location)
{
	//seperating src and dst
	bool result = false;
	string src = "", dst = "";
	utility::separateMove(location, src, dst);

	//getting indexes
	int srcRow = 0, srcCol = 0, dstRow = 0, dstCol = 0;
	utility::stringToIndexes(src, srcRow, srcCol);
	utility::stringToIndexes(dst, dstRow, dstCol);

	//checking piece spesific path
	switch (tolower(game.getPieceFromString(src)->getPieceType()))
	{
	case 'n':	//is poni
		result = knightPath(game, srcRow, srcCol, dstRow, dstCol);
		break;
	case 'k':	//is king
		result = kingPath(game, srcRow, srcCol, dstRow, dstCol);
		break;
	case 'r':	//is rook
		result = rookPath(game, srcRow, srcCol, dstRow, dstCol);
		break;
	case 'p':	//is pawn
		result = pawnPath(game, srcRow, srcCol, dstRow, dstCol);
		break;
	case 'b': //is bish(op)
		result = bishopPath(game, srcRow, srcCol, dstRow, dstCol);
		break;
	case 'q': //is queen
		result = queenPath(game, srcRow, srcCol, dstRow, dstCol);
		break;
	case '#': //is empty
		result = EmptyPath();
		break;
	default:
		result = true;
	}
	return result;
}

bool Engine::knightPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol)
{
	return false; //ponies are unstoppable
}

bool Engine::kingPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol)
{
	return false; //kings are slow af they dont even move
}

bool Engine::rookPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol)
{
	bool flag = false;
	if (srcRow == dstRow)//if moving on x axis
	{
		for (int i = 1; i <= (abs(srcCol - dstCol) - 1) && !flag; i++)
		{
			if (srcCol > dstCol)
			{
				flag = flag || game.board[srcRow][srcCol - i]->getPieceType() != '#';
			}
			else
			{
				flag = flag || game.board[srcRow][srcCol + i]->getPieceType() != '#';
			}
		}
	}
	else if (srcCol == dstCol)//if moving on y axis
	{
		for (int i = 1; i <= (abs(srcRow - dstRow) - 1); i++)
		{
			if (srcRow > dstRow)
			{
				flag = flag || game.board[srcRow - i][srcCol]->getPieceType() != '#';
			}
			else
			{
				flag = flag || game.board[srcRow + i][srcCol]->getPieceType() != '#';
			}
		}
	}
	return flag;
}

bool Engine::pawnPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol)
{
	return (dstCol - srcCol > 1) && game.board[srcRow][srcCol + 1]->getPieceType() != '#';
}

bool Engine::bishopPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol)
{
	bool flag = false;
	if (srcCol < dstCol && srcRow > dstRow) // if moves right and down
	{
		for (int i = 1; i <= (abs(srcCol - dstCol) - 1) && !flag; i++)
		{
			flag = flag || game.board[srcRow - i][srcCol + i]->getPieceType() != '#';
		}
	}
	else if (srcCol < dstCol && srcRow < dstRow) //id moves right and up
	{
		for (int i = 1; i <= (abs(srcCol - dstCol) - 1) && !flag; i++)
		{
			flag = flag || game.board[srcRow + i][srcCol + i]->getPieceType() != '#';
		}
	}
	else if (srcCol > dstCol && srcRow > dstRow) //if moves left and down
	{
		for (int i = 1; i <= (abs(srcCol - dstCol) - 1) && !flag; i++)
		{
			flag = flag || game.board[srcRow - i][srcCol - i]->getPieceType() != '#';
		}
	}
	else if (srcCol > dstCol && srcRow < dstRow) //if moves left and up
	{
		for (int i = 1; i <= (abs(srcCol - dstCol) - 1) && !flag; i++)
		{
			flag = flag || game.board[srcRow + i][srcCol - i]->getPieceType() != '#';
		}
	}
	return flag;
}

bool Engine::queenPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol)
{
	return bishopPath(game, srcRow, srcCol, dstRow, dstCol) || rookPath(game, srcRow, srcCol, dstRow, dstCol);
}

bool Engine::EmptyPath()
{
	return false; //uhh why.
}


bool Engine::isCheckmate(Game& game, string location)
{
	//TODO: implement checkmate

		//create a new game where the move is done
		//seperating src and dst
	string src = "", dst = "";
	utility::separateMove(location, src, dst);
	Game* demoGame = new Game(game);
	demoGame->execute(location, src, dst);


	demoGame->~Game();

	return false;
}

bool Engine::checkCheck(Game& game)
{
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{
			Piece* piece = game.board[row][col];
			char pieceType = piece->getPieceType();
			string pieceLocation = utility::indexesToString(row, col);
			if (pieceType != '#' && piece->getPieceColor() == !game.currentPlayer)
			{
				string checktry = utility::indexesToString(row, col) + game._players[!game.currentPlayer]->_kingPosition;
				if (game.getPieceFromString(pieceLocation)->pieceLegality(checktry, (game.board)))
				{
					if (canSrcMove(game, checktry) && !isPathBlocked(game, checktry) && !doesCauseDiscovery(game, checktry)) //board legality
					{
							return true; //piece can go there next move
					}
				}

			}
		}
	}
	return false;
}

int Engine::boardLegality(Game& game, string location)
{
	int result = VALID_MOVE;
	//TODO: implement check check :)
	result = (!result && !canSrcMove(game, location)) ? INVALID_MOVE_NO_SRC : result;
	result = (!result && isDstOccupied(game, location)) ? INVALID_MOVE_DST_OCCUPIED : result;
	//result = (!result && doesCauseDiscovery(game, location)) ? INVALID_MOVE_DISCOVERY : result;
	result = (!result && isOutOfBounds(location)) ? INVALID_INDEXES : result;
	result = (!result && isPathBlocked(game, location)) ? INVALID_PIECE_MOVE : result;
	result = (!result && areIndexesEqual(location)) ? INVALID_INDEXES_ARE_EQUAL : result;
	result = (!result && isCheckmate(game, location)) ? CHECKMATE : result;

	return result;
}