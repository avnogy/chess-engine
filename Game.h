#pragma once
#include "Utility.h"
#include "Player.h"
#include "Piece.h"
#include "Engine.h"

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
	Player* _players[2];
	// helper methods
	void switchPlayer();
	void clearBoard();
	void removePiece(int row, int col);
public:
	// fields
	bool currentPlayer;
	Piece* board[BOARD_SIDE_LENGTH][BOARD_SIDE_LENGTH];
	// static variable
	static string INITIAL_BOARD;

	// constructor & destructor
	Game();
	~Game();

	// methods
	Piece* getPieceFromString(string location);
	void copyBoardFromString(string boardString);
	void printBoard();
	void move(string moveData);
};