#include "Game.h"
#include "Utility.h"
#include "Empty.h"
#include "Rook.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"

string Game::INITIAL_BOARD = "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr0";

// switches the current player to the other 
void Game::switchPlayer()
{
	currentPlayer = !currentPlayer;
}

// initialize board according to a string
void Game::copyBoardFromString(string boardString)
{
	clearBoard();
	if (boardString.length() < BOARD_SIDE_LENGTH * BOARD_SIDE_LENGTH)
	{
		throw "Unable to read string in order to copy board";
	}

	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{
			int index = row * BOARD_SIDE_LENGTH + col;
			char piece = Game::INITIAL_BOARD[index];
			Piece* piecePointer = nullptr;
			switch (piece)
			{
			case '#':
				piecePointer = new Empty();
				break;
			case 'r':
			case 'R':
				piecePointer = new Rook(isupper(piece));
				break;
			case 'b':
			case 'B':
				piecePointer = new Bishop(isupper(piece));
				break;
			case 'n':
			case 'N':
				piecePointer = new Knight(isupper(piece));
				break;
			case 'q':
			case 'Q':
				piecePointer = new Queen(isupper(piece));
				break;
			case 'k':
			case 'K':
				piecePointer = new King(isupper(piece));
				break;
			case 'p':
			case 'P':
				piecePointer = new Pawn(isupper(piece));
				break;
			default:
				throw "Unknown piece in board string.";
			}
			this->board[row][col] = piecePointer;
		}
	}
}

// frees all memory allocated on the board
void Game::clearBoard()
{
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{
			if (this->board[row][col] != nullptr)
			{
				// calling the appropriate destructor for every piece
				switch (this->board[row][col]->getPieceType())
				{
				case '#':
					delete (Empty*)this->board[row][col];
					break;
				case 'r':
				case 'R':
					delete (Rook*)this->board[row][col];
					break;
				case 'b':
				case 'B':
					delete (Bishop*)this->board[row][col];
					break;
				case 'n':
				case 'N':
					delete (Knight*)this->board[row][col];
					break;
				case 'q':
				case 'Q':
					delete (Queen*)this->board[row][col];
					break;
				case 'k':
				case 'K':
					delete (King*)this->board[row][col];
					break;
				case 'p':
				case 'P':
					delete (Pawn*)this->board[row][col];
					break;
				default:
					throw "detected Unknown piece in board while clearing board.";
				}
			}
		}
	}
}

// constructor
Game::Game()
{
	this->currentPlayer = WHITE;

	this->_players[WHITE] = new Player(WHITE);
	this->_players[BLACK] = new Player(BLACK);

	// initializing board as the standard chess board
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{
			this->board[row][col] = nullptr;
		}
	}
	copyBoardFromString(Game::INITIAL_BOARD);
}

// destructor
Game::~Game()
{
	delete this->_players[WHITE];
	delete this->_players[BLACK];

	// deleting every piece on the board
	clearBoard();
}

// prints the board to std::cout
void Game::printBoard()
{
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{
			cout << this->board[row][col]->getPieceType() << " ";
		}
		cout << endl;
	}
}
