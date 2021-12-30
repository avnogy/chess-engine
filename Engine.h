#include "Utility.h"
#include "Game.h"

class Engine
{
public:
	static bool isSrcPiece(Game& game, string location);
	static bool isDstOccupied(Game& game, string location);
	static bool doesCauseDiscoverey(Game& game, string location);
	static bool isOutOfBounds(string location);
	static bool AreIndexesEqual(string location);
	static bool IsCheckmate(Game& game, string location);
};