#pragma once
#include "Utility.h"
#include "Game.h"
#include "Piece.h"

#define VALID_MOVE 0 
#define CHECK_MOVE 1
#define INVALID_MOVE_NO_SRC 2
#define INVALID_MOVE_DST_OCCUPIED 3
#define INVALID_MOVE_DISCOVERY 4
#define INVALID_INDEXES 5
#define INVALID_PIECE_MOVE 6
#define INVALID_INDEXES_ARE_EQUAL 7
#define CHECKMATE 8

class Game;
class Engine
{
public:
	//utility functions
	static bool isCheckmate(Game& game, string location);

	static bool isCheck(Game& game, string moveData);

	static bool checkCheck(Game& game);

	static int boardLegality(Game& game, string location);

	//board validity functions
	static bool canSrcMove(Game& game, string location);

	static bool isDstOccupied(Game& game, string location);

	static bool doesCauseDiscovery(Game& game, string location);

	static bool isOutOfBounds(string location);

	static bool areIndexesEqual(string location);

	static bool isPathBlocked(Game& game, string location);

	//piece specific path checking 
	static bool knightPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol);
	static bool kingPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol);
	static bool rookPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol);
	static bool pawnPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol);
	static bool bishopPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol);
	static bool queenPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol);
	static bool EmptyPath();


};