#include "Game.h"

string Game::INITIAL_BOARD = "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr0";

// switches the current player to the other 
void Game::switchPlayer()
{
	_currentPlayer = !_currentPlayer;
}

// constructor
Game::Game()
{
	this->_currentPlayer = WHITE;
	
	this->_players[WHITE] = new Player(WHITE);
	this->_players[BLACK] = new Player(BLACK);

	// initializing every piece on the board
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{
			this->_board[row][col] = nullptr;
		}
	}
}

// destructor
Game::~Game()
{
	delete this->_players[WHITE];
	delete this->_players[BLACK];

	// deleting every piece on the board
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{
			// calling the appropriate destructor for every piece
			switch (this->_board[row][col]->getPieceType())
			{
			case '#':
				delete (Empty*)this->_board[row][col];
				break;
			case 'r':
			case 'R':
				delete (Rook*)this->_board[row][col];
				break;
			case 'b':
			case 'B':
				delete (Bishop*)this->_board[row][col];
				break;
			case 'n':
			case 'N':
				delete (Knight*)this->_board[row][col];
				break;
			case 'q':
			case 'Q':
				delete (Queen*)this->_board[row][col];
			case 'k':
			case 'K':
				delete (King*)this->_board[row][col];
			case 'p':
			case 'P':
				delete (Pawn*)this->_board[row][col];
			default:

			}
		}
	}
}
