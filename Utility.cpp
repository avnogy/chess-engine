#include "Utility.h"

namespace utility
{
	// returns indexes as col(char)row(int)
	// example: 4, 1 -> e2
	string indexesToString(int row, int col)
	{
		string locationString = "";
		if (row >= 8 || row < 0 || col >= 8 || col < 0)
		{
			throw "Invalid index for position string.";
		}
		locationString += col + 'a';
		locationString += row + 1 + '0';
		return locationString;
	}

	// changes the second and third params according to the first
	void stringToIndexes(string location, int& rowDest, int& colDest)
	{
		// TODO: add exceptions to verify input here

		rowDest = location[1] - 1 - '0';

		colDest = location[0] - 'a';
	}

	// separates the source and destination of a move string
	void separateMove(string intactMove, string& src, string& dst)
	{
		src = intactMove[0] + intactMove[1];
		dst = intactMove[2] + intactMove[3];
	}
}