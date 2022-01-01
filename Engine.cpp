#include "Engine.h"



bool Engine::isSrcPiece(Game &game,string location)
{
	string src = "", dst = "";
	utility::separateMove(location, src, dst);
	char pType = Piece::getPieceFromString(game, src)->getPieceType();
	return pType != '#';
}

bool Engine::isDstOccupied(Game& game, string location)
{
	//seperating src and dst
	string src = "", dst = "";
	utility::separateMove(location, src, dst);
	
	//getting piece from dst location
	Piece* dstPiece = nullptr;
	dstPiece = Piece::getPieceFromString(game, dst);

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





