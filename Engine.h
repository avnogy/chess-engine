#pragma once
#include "Utility.h"
#include "Game.h"
#include "Piece.h"
class Game;
class Engine
{
public:
	//utility functions
	static bool isCheckmate(Game& game, string location);

	static bool boardLegality(Game& game, string location, bool isHorse);

	//board validity functions
	static bool isSrcPiece(Game& game, string location);

	static bool isDstOccupied(Game& game, string location);

	static bool doesCauseDiscovery(Game& game, string location);

	static bool isOutOfBounds(string location);

	static bool areIndexesEqual(string location);

	static bool isPathBlocked(Game& game, string location);

};