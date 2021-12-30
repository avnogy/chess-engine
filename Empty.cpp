#include "Empty.h"

Empty::Empty(string position) : Piece('#', position)
{
	
}

Empty::~Empty()
{
}

// an empty piece cannot move anywhere
bool Empty::pieceLegality(string position) const
{
	return false;
}
