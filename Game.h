#pragma once
#include "Utility.h"
#include "Player.h"
#include "Piece.h"
#include "Engine.h"
#include "Empty.h"
#include "Rook.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"

class Player;
class Piece;
class Empty;
class Rook;
class Bishop;
class Queen;
class King;
class Knight;
class Pawn;

class Game
{
private:
	// fields
	char _outputCode[2];
	// helper methods
	void clearBoard();
	void removePiece(int row, int col);
public:
	void switchPlayer();
	Player* _players[2];
	// fields
	bool currentPlayer;
	Piece*** board;
	// static variable
	static string INITIAL_BOARD;

	// constructor & destructor
	Game();
	~Game();
	Game(Game& other);

	// methods
	Piece* getPieceFromString(string location);
	void copyBoardFromString(string boardString);
	string getStringFromBoard();
	void printBoard();
	char* move(string moveData);
	void execute(string moveData,string src,string dst);
};