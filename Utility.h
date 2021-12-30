#pragma once
#include <iostream>
#include <string>
#include <cctype>
#define BLACK 0
#define WHITE 1

using std::string;
using std::cout;
using std::endl;

namespace utility
{
	string indexesToString(int row, int col);
	double stringToIndexes(string location);
}