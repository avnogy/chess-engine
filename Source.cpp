#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Game.h"

int main()
{
	srand(time_t(NULL));

	Game game;
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
		
		game.move(msgFromGraphics, msgToGraphics);
		//strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation

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