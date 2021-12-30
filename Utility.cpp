#include "Utility.h"

namespace utility
{
	string indexesToString(int row, char col)
	{
		string locationString = "";
		// TODO: throw exception if either row or col are invalid
		locationString += col;
		locationString += row + '0';
		return locationString;
	}
}