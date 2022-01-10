#include "Empty.h"

Empty::Empty() : Piece('#')
{
	
}

Empty::~Empty()
{
}

// an empty piece cannot move anywhere
int Empty::pieceLegality(const string route, Piece*** board)
{
	return DENIED_MOVE;
}