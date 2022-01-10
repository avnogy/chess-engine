#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Game.h"

using std::cout;
using std::endl;

int main()
{
	srand(time_t(NULL));

	Game game;
	//complete board: "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0"
	//no pawns: "rnbqkbnr################################################RNBQKBNR0"
	string board = "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0";
	game.copyBoardFromString(board);
	Pipe pipe;
	bool isConnected = pipe.connect();
	
	string ans;
	while (!isConnected)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnected = pipe.connect();
		}
		else 
		{
			pipe.close();
			return -1;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string according to the protocol
	// YOUR CODE

	//strcpy_s(msgToGraphics, Game::INITIAL_BOARD.c_str()); // just example...
	strcpy_s(msgToGraphics, board.c_str());

	pipe.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = pipe.getMessageFromGraphics();

	cout << "###                      CHESS (TM)                      ###" << endl;
	cout << "Original game by:             Garry Chess" << endl;
	cout << "En Passant (TM) by:           George En Passant" << endl;
	cout << "Final Boss:                   Anatolichess Karpov" << endl;
	cout << "Frontend programming:         Erez Debugging" << endl;
	cout << "Backend programming:          Nir Amir and Avner Mindelis" << endl;
	cout << "Testing: Deep Blue, LCZ(TM), Stockfish" << endl;
	cout << endl;
	cout << "###                    SPECIAL THANKS                    ###" << endl;
	cout << "Magnum Carlos" << endl;
	cout << "Gotham Chess" << endl;
	cout << "Agadmator Chess" << endl;
	cout << "Ruy Lopez" << endl;
	cout << "Hikaru Nakamura" << endl;
	cout << "Tigran Petrosian" << endl;
	cout << endl;
	cout << "###                  NOT SPECIAL THANKS                  ###" << endl;
	cout << "\"w\"esley \"s\"o" << endl;
	cout << "Bobby Fischer" << endl;
	cout << "Jeremy Checkers" << endl;
	cout << endl;
	cout << "###                     LAST CHANGES                     ###" << endl;
	cout << "git commit -m \"bug fixes and performance enhancements\"" << endl;
	cout << "git commit -m \"repairing the space-time continuum\"" << endl;
	cout << "git commit -m \"repairing the space-time continuum\"" << endl;
	cout << "git commit -m \"repaired the space-time continuum\"" << endl;
	cout << "git commit -m \"whoops.\"" << endl;

	while (msgFromGraphics != "quit")
	{
		// should handle the string sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		strcpy_s(msgToGraphics, game.move(msgFromGraphics)); // msgToGraphics should contain the result of the operation


		/******* JUST FOR EREZ DEBUGGING *****
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(1 + '0');
		msgToGraphics[1] = 0;
		****** JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		pipe.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = pipe.getMessageFromGraphics();
	}

	pipe.close();
	return 0;
}