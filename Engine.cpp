#include "Engine.h"

bool Engine::isSrcPiece(Game &game,string location)
{
	//double indexes = utility::stringToIndexes(location);
	//int row = indexes;
	//int col = int(indexes * 10) % 10;
	int row = 0, col = 0;
	utility::stringToIndexes(location,row,col);
	char pType = game.board[row][col]->getPieceType();
	return pType != '#';
}

