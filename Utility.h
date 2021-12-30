#pragma once
#include <iostream>
#include <string>
#include <cctype>
#define BLACK 0
#define WHITE 1
#define BOARD_SIDE_LENGTH 8
using std::string;
using std::cout;
using std::endl;

namespace utility
{
	string indexesToString(int row, int col);
	void stringToIndexes(string location, int& rowDest, int& colDest);
	void separateMove(string intactMove, string& src, string& dst);
}