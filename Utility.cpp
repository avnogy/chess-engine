#include "Utility.h"

namespace utility
{
	string indexesToString(int row, int col)
	{
		string locationString = "";
		if (row > 8 || row < 0 || col > 8 || col < 0)
		{
			throw "Invalid index for position string.";
		}
		locationString += col - 1 + 'a';
		locationString += row + '0';
		return locationString;
	}

	double stringToIndexes(string location)
	{
		return 0.0;
	}
}