#pragma once
#include "Utility.h"
#include "Game.h"
#include "Piece.h"
#include <vector>

#define VALID_MOVE 0 
#define CHECK_MOVE 1
#define INVALID_MOVE_NO_SRC 2
#define INVALID_MOVE_DST_OCCUPIED 3
#define INVALID_MOVE_DISCOVERY 4
#define INVALID_INDEXES 5
#define INVALID_PIECE_MOVE 6
#define INVALID_INDEXES_ARE_EQUAL 7
#define CHECKMATE 8

#define DST 2
#define SRC 0
#define ROW 1
#define COL 0

class Game;
class Engine
{
public:
	//utility functions
	static bool isCheck(Game& game, string moveData);

	static bool checkCheck(Game& game);

	static int boardLegality(Game& game, string moveData);

	//board validity functions
	static bool canSrcMove(Game& game, string moveData);

	static bool isDstOccupied(Game& game, string moveData);

	static bool doesCauseDiscovery(Game& game, string moveData);

	static bool isOutOfBounds(string moveData);

	static bool areIndexesEqual(string moveData);

	static bool isPathBlocked(Game& game, string moveData);

	//piece specific path checking 
	static bool knightPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol);
	static bool kingPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol);
	static bool rookPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol);
	static bool pawnPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol);
	static bool bishopPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol);
	static bool queenPath(Game& game, int srcRow, int srcCol, int dstRow, int dstCol);
	static bool EmptyPath();


};