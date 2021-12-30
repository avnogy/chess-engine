#include "Engine.h"

bool Engine::isSrcPiece(Game &game,string location)
{
	string src = "", dst = "";
	utility::separateMove(location, src, dst);
	int row = 0, col = 0;
	utility::stringToIndexes(src,row,col);
	char pType = game.board[row][col]->getPieceType();
	return pType != '#';
}

bool Engine::isDstOccupied(Game& game, string location)
{
	string src = "", dst = "";
	utility::separateMove(location, src, dst);
	int row = 0, col = 0;
	utility::stringToIndexes(dst, row, col);
	char pType = game.board[row][col]->getPieceType();
	return (pType != '#' && game.board[row][col]->getPieceColor() == game.currentPlayer);
}

bool Engine::isOutOfBounds(string location)
{
	int row = 0, col = 0;
	string src = "", dst = "";
	
	//seperating src and dst
	utility::separateMove(location, src, dst);

	//checking src
	utility::stringToIndexes(src, row, col);
	if (row < 1 || row > BOARD_SIDE_LENGTH || col < 1 || col > BOARD_SIDE_LENGTH)
	{
		return true;
	}
	//checking dst
	utility::stringToIndexes(dst, row, col);
	if (row < 1 || row > BOARD_SIDE_LENGTH || col < 1 || col > BOARD_SIDE_LENGTH)
	{
		return true;
	}
}

bool Engine::AreIndexesEqual(string location)
{
	//seperating src and dst
	string src = "", dst = ""; 
	utility::separateMove(location, src, dst);

	return (src == dst);
}





