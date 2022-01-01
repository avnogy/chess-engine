#include "Engine.h"



bool Engine::isSrcPiece(Game &game,string location)
{
	//seperating src and dst
	string src = "", dst = "";
	utility::separateMove(location, src, dst);

	//checking if piece at source is not empty
	char pType = game.getPieceFromString(src)->getPieceType();
	return pType != '#';
}

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

bool Engine::isOutOfBounds(string location)
{
	int row = 0, col = 0;
	string src = "", dst = "";
	
	//seperating src and dst
	utility::separateMove(location, src, dst);

	//checking if source is out of bounds
	utility::stringToIndexes(src, row, col);
	if (row < 1 || row > BOARD_SIDE_LENGTH || col < 1 || col > BOARD_SIDE_LENGTH)
	{
		return true;
	}

	//checking if destination is out of bounds
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

	//checking if source and destination locations are equal
	return (src == dst);
}





