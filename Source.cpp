/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Game.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

#if 0
int main()
{
	Game game;
	string myBoard = "####k########################kR###r######r##################k###";
	string movementInput = "";
	game.copyBoardFromString(myBoard);

	while (true) // TODO: detect checkmate
	{
		game.printBoard();
		cin >> movementInput;
		game.move(movementInput);
	}
	return 0;
}
#else
int main()
{
	srand(time_t(NULL));

	
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

	strcpy_s(msgToGraphics, Game::INITIAL_BOARD.c_str()); // just example...
	
	pipe.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = pipe.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		// TODO: use game::move
		strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation

		/******* JUST FOR EREZ DEBUGGING ******/
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(1 + '0');
		msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		pipe.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = pipe.getMessageFromGraphics();
	}

	pipe.close();
	return 0;
}
#endif 