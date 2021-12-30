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





