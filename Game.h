#include "Utility.h"
#include "Player.h"
#include "Piece.h"

#define BOARD_SIDE_LENGTH 8

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
	Piece* _board[BOARD_SIDE_LENGTH][BOARD_SIDE_LENGTH];
	bool _currentPlayer;
	Player* _players[2];

	// helper methods
	void switchPlayer();
public:
	// static variable
	static string INITIAL_BOARD;
	
	// constructor & destructor
	Game();
	~Game();
	
	// methods
	void move(char* moveData);
};