#include "Game.h"

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

	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{

		}
	}
}
