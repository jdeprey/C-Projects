/*********************************************************************
 * ** Author: Joseph DePrey
 * ** Date: 3/8/2016
 * ** Description: Project 10.a - TicTacToe Class Implementation File
 * **   Allows two people to play a simple game of tic tac toe. It has
 * **   fields for a board object and one to track whose turn it is.
 * **   Has a constructor which takes a char parameter that specifies 
 * **   whether 'x' or 'o' has first move and a play method to start 
 * **   the game.  The play method keeps looping for each move until
 * **   someone wins or or the game is declared a draw.
4 of 4 
 * *********************************************************************/
// TicTacToe Class Implementation Code
#include "TicTacToe.hpp"


int main()
{
	char player;
	while (true) 
	{
		std::string input = "";
		std::cout << "Which player would like to go first? x or o?" << std::endl;
   		getline(std::cin, input);
   		if (input.length() == 1) 
   		{
   			player = input[0];
     		break;
     	}
	}

	TicTacToe letsPlayAGame(player);

	letsPlayAGame.play();

	return 0;
}


/************************************
 *        Default Constructor    
 * Sets 'x' as the first player                
 *************************************/

TicTacToe::TicTacToe()
{
	currentPlayer = 'x';
}

/************************************
*       1-Parameter Constructor     
* Sets first player as 'x' or 'o'   
*************************************/

TicTacToe::TicTacToe(char player)
{
	if(player == 'x' || player == 'X')
	{
		currentPlayer = 'x';
	}
	else if(player == 'o' || player == 'O')
	{
		currentPlayer = 'o';
	}
	else
	{
		std::cout << "Invalid input, 'x' will be the first player." << std::endl;
		currentPlayer = 'x';
	}	 
}

/************************************
*                 play     
* Begins the game of tic tac toe   
*************************************/
void TicTacToe::play()
{
	// Print current game board
	ourBoard.print();
	
	do
	{
		// User-inputted coordinates
		int x, y;
		std::cout << "Player " << currentPlayer << 
		" please enter your move (row followed by column): " << std::endl;
		std::cin >> x >> y;
		// Bounds-checking
		while(std::cin.fail() || 
			   x > 2 || x < 0 ||
			   y > 2 || y < 0) 
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid coordinates, please enter values between 0 and 2" << std::endl;
			std::cin >> x >> y;
		}

		// Input validation
		if(ourBoard.makeMove(x, y, currentPlayer))
		{
			// If input is valid print the board, check gameState
			ourBoard.print();
			
			if(ourBoard.gameState() == x_wins)
			{
				std::cout << "Player x has won!" << std::endl;
			}
			else if(ourBoard.gameState() == o_wins)
			{
				std::cout << "Player o has won!" << std::endl;
			} 
			else if(ourBoard.gameState() == draw)
			{
				std::cout << "Game is a draw. There is no winner today." << std::endl;	
			}
			
			// Switch players if game still in progress
			if(currentPlayer == 'x')
			{
				currentPlayer = 'o';
			}
			else
			{
				currentPlayer = 'x';
			}
		}
		else
		{
			std::cout << "Location is occupied.  Try another." << std::endl;
		}
	}
	while(ourBoard.gameState() == in_progress);
}
