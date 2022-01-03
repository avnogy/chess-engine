#include "Empty.h"

Empty::Empty() : Piece('#')
{
	
}

Empty::~Empty()
{
}

// an empty piece cannot move anywhere
bool Empty::pieceLegality(const string route, Piece*** board) const
{
	return false;
}
