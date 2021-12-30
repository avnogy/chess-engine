#include "Utility.h"
#include "Game.h"

class Engine
{
public:
	bool isSrcPieces(string);
	bool isDstOccupied(string);
	bool doesCauseDiscoverey(string);
	bool isOutOfBounds(string);
	bool AreIndexesEqual(string);
	bool IsCheckmate(string);
};