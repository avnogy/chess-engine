#include "Engine.h"


// returns true if source point is a piece that can move in this turn
bool Engine::canSrcMove(Game &game,string location)
{
	//seperating src and dst
	string src = "", dst = "";
	utility::separateMove(location, src, dst);

	//checking if piece at source is not empty
	char pType = game.getPieceFromString(src)->getPieceType();
	return pType != '#' &&
			(isupper(pType) && game.currentPlayer == WHITE ||
			islower(pType) && game.currentPlayer == BLACK);
}

// returns true if can go there
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
	//TODO: implement blocking
	return false;
}

bool Engine::isCheckmate(Game& game, string location)
{
	//TODO: implement checkmate
	return false;
}

bool Engine::boardLegality(Game& game, string location, bool isHorse)
{
	return(!canSrcMove(game, location) //                   implemented
		&& isDstOccupied(game, location) //                 
		&& !doesCauseDiscovery(game, location) //           
		&& !isOutOfBounds(location) //                      implemented
		&& !areIndexesEqual(location) //                    
		&& (isHorse || !isPathBlocked(game, location))); // 
}