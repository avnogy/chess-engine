#include "Utility.h"

namespace utility
{
	string indexesToString(int row, char col)
	{
		string locationString = "";
		if (row > 8 || row < 0 || col > 8 || col < 0)
		{
			throw "Invalid index for position string.";
		}
		locationString += col;
		locationString += row + '0';
		return locationString;
	}
}