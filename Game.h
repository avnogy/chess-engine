#include "Utility.h"
#include "Player.h"

#define BOARD_SIDE_LENGTH 8

class Piece;
class Player;

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
	static char* initialBoard;
	
	// constructor & destructor
	Game();
	~Game();
	
	// methods
	void move(char* moveData);
};