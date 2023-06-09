#include "Game.h"

string Game::INITIAL_BOARD = "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0";

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
			char piece = boardString[index];
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

//returns string from current board state
string Game::getStringFromBoard()
{
	string result = "";
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{
			result += this->board[row][col]->getPieceType();
		}
	}
	//cout << result << endl;
	return result;
}

// frees all memory allocated on the board
void Game::clearBoard()
{
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{
			removePiece(row, col);
		}
	}
}

//removes a piece according to its type
void Game::removePiece(int row, int col)
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

		this->board[row][col] = nullptr; // discarding invalid pointers
	}
}

// constructor
Game::Game()
{
	this->currentPlayer = WHITE;

	this->_players[WHITE] = new Player(WHITE);
	this->_players[BLACK] = new Player(BLACK);

	this->_outputCode[0] = 0;
	this->_outputCode[1] = 0;

	this->board = new Piece**[BOARD_SIDE_LENGTH];
	if (this->board == nullptr)
	{
		throw "memory allocation failure"; // pipi in our pampers
	}
	// initializing board as the standard chess board
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		this->board[row] = new Piece*[BOARD_SIDE_LENGTH];
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
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		delete[] this->board[row];
	}
	delete[] this->board;
}

//copy constructor
Game::Game(Game& other)
{
	this->currentPlayer = other.currentPlayer;
	
	//copying right colors
	this->_players[WHITE] = new Player(WHITE);
	this->_players[BLACK] = new Player(BLACK);

	this->_players[WHITE]->_kingPosition = other._players[WHITE]->_kingPosition;
	this->_players[BLACK]->_kingPosition = other._players[BLACK]->_kingPosition;

	this->_outputCode[0] = 0;
	this->_outputCode[1] = 0;

	this->board = new Piece * *[BOARD_SIDE_LENGTH];
	if (this->board == nullptr)
	{
		throw "memory allocation failure"; // pipi in our pampers
	}
	// initializing board as the other board
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		board[row] = new Piece * [BOARD_SIDE_LENGTH];
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{
			board[row][col] = nullptr;
		}
	}
	copyBoardFromString(other.getStringFromBoard());
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

//executes everything in a move
char* Game::move(string moveData)
{
	//seperating src and dst
	string src = "", dst = "";
	utility::separateMove(moveData, src, dst);

	//getting indexes
	int srcRow = 0, srcCol = 0, dstRow = 0, dstCol = 0;
	utility::stringToIndexes(src, srcRow, srcCol);
	utility::stringToIndexes(dst, dstRow, dstCol);

	//check piece validity
	int moveType = this->getPieceFromString(src)->pieceLegality(moveData, (this->board));
	if (moveType)
	{
		//check board validity
		this->_outputCode[0] = Engine::boardLegality(*this, moveData) + '0';
		if (_outputCode[0] == '0' || _outputCode[0] == '1' || _outputCode[0] == '8')
		{
			// executing move
			execute(moveData);
			if (moveType == CASTLING)
			{
				string newMove = "";
				if (src[0] - dst[0] > 0) //if went left
				{
					newMove += "a";
					newMove += src[1];
					newMove += (char)(src[0] - 1);
					newMove += src[1];;
					execute(newMove);
					this->switchPlayer();
				}
				else //went right
				{
					newMove += "h";
					newMove += src[1];
					newMove += (char)(src[0] + 1);
					newMove += src[1];
					execute(newMove);
					this->switchPlayer();
				}
			}
			else if (moveType == EN_PASSANT)
			{
				// holy hell procedure
				delete (Pawn*)board[srcRow][dstCol];
				board[srcRow][dstCol] = new Empty();
			}
		}
	}
	else
	{
		this->_outputCode[0] = '6';
	}

	//special moves yay
	if (this->_outputCode[0] == '0' && moveType != NORMAL_MOVE)
	{
		if (moveType == EN_PASSANT)
		{
			//do something??
		}
		else if (moveType == CASTLING)
		{
			//do some other thing??
		}
	}

	return this->_outputCode;
}

//helper method for actually doing the move
void Game::execute(string moveData)
{
	//seperating src and dst
	string src = "", dst = "";
	utility::separateMove(moveData, src, dst);

	//getting indexes
	int srcRow = 0, srcCol = 0, dstRow = 0, dstCol = 0;
	utility::stringToIndexes(src, srcRow, srcCol);
	utility::stringToIndexes(dst, dstRow, dstCol);

	// updating king position
	if (toupper(this->board[srcRow][srcCol]->getPieceType()) == 'K')
	{
		((King*)this->getPieceFromString(src))->setCastleFlag(false);
		this->_players[currentPlayer]->_kingPosition = dst;
	}

	//destroying dest piece
	removePiece(dstRow, dstCol);
	//moving src piece
	this->board[dstRow][dstCol] = this->board[srcRow][srcCol];
	//putting nothing in src location
	this->board[srcRow][srcCol] = new Empty();

	// clearing en passant flags
	int rowToClearEnPassantFlags = BLACK_INITIAL_ROW - '0' - 2;
	if (currentPlayer == WHITE)
	{
		rowToClearEnPassantFlags = WHITE_INITIAL_ROW - '0' + 2;
	}
	for (int i = 0; i < BOARD_SIDE_LENGTH; i++)
	{
		if (tolower(board[rowToClearEnPassantFlags][i]->getPieceType()) == 'p')
		{
			((Pawn*)board[rowToClearEnPassantFlags][i])->setEnPassantFlag(false);
		}
	}

	//end of turn
	this->switchPlayer();
}

//gets a piece from location in string
Piece* Game::getPieceFromString(string location)
{
	int row = 0, col = 0;
	utility::stringToIndexes(location, row, col);
	return this->board[row][col];
}