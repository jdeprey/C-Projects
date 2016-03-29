/*********************************************************************
 * ** Author: Joseph DePrey
 * ** Date: 3/8/2016
 * ** Description: Project 10.a - Board Class Implementation File
 * **   Representing a tic-tac-toe board, Board have a 3x3 array as a 
 * **   data member to store the locations of players' moves, a method
 * **   to record the move and return true/false, a method to indicate
 * **   the state of the game, and a print method to print the current
 * **   board to the screen 
2 of 4
 * *********************************************************************/
// Board Class Implementation Code
#include "Board.hpp"


/************************************
 *        Default Constructor    
 * Initializes the all elements of 
 * array to '.'
 *************************************/

Board::Board()
{
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gameBoard[i][j] = '.';
        }
    }
}

/************************************
 *           makeMove    
 * Takes 3 parameters, the x and y 
 * coordinates as ints and char for 
 * players turn then checks the 
 * location and returns true if 
 * unoccupied, and false is taken. 
 *************************************/

bool Board::makeMove(int xCoord, int yCoord, char player)
{
	// check if location is unoccupied and game is not a draw
	if(gameBoard[xCoord][yCoord] == '.' && gameState() == in_progress)
	{
		// check whose turn it is
		if(player == 'x' || player == 'X')
		{
			gameBoard[xCoord][yCoord] = 'x';
		}
		else if(player == 'o' || player == 'O')
		{
			gameBoard[xCoord][yCoord] = 'o';
		}
		return true;
	}
	// location is occupied
	return false;

}

/************************************
 *            gameState    
 * Takes no parameters and returns an
 * enum indicating one of four 
 * possibilities: 'x' has won, 'o' 
 * has won, the game is a draw, or 
 * the game is still in progress.
 *************************************/

State Board::gameState()
{
	int xCount;
	int oCount;
	// Check horizontal winning combinations for x and o
	for(int x = 0; x < 3; x++)
	{
		// Reset counter
		xCount = 0;
		oCount = 0;
		// Iterate through horizontally
		for (int y = 0; y < 3; y++)
		{
			if(gameBoard[x][y] == 'x')
			{
				xCount++;
			}
			else if(gameBoard[x][y] == 'o')
			{
				oCount++;
			}
			if(xCount == 3)
			{
				return x_wins;
			}
			else if(oCount == 3)
			{
				return o_wins;
			}
		}
	}
	// Check vertical winning combinations for x and o
	for(int y = 0; y < 3; y++)
	{
		// Reset counter
		xCount = 0;
		oCount = 0;
		// Iterate through vertically
		for (int x = 0; x < 3; x++)
		{
			if(gameBoard[x][y] == 'x')
			{
				xCount++;
			}
			else if(gameBoard[x][y] == 'o')
			{
				oCount++;
			}
			if(xCount == 3)
			{
				return x_wins;
			}
			else if(oCount == 3)
			{
				return o_wins;
			}
		}
	}
	// Check diagonal winning combinations for x and o
	if (gameBoard[0][0] == 'x' && 
	    gameBoard[1][1] == 'x' &&
       	gameBoard[2][2] == 'x')
	{
		return x_wins;
	}
	else if(gameBoard[0][2] == 'x' && 
	   		gameBoard[1][1] == 'x' &&
	   		gameBoard[2][0] == 'x')
	{
		return x_wins;
	}
	else if (gameBoard[0][0] == 'o' && 
	   	gameBoard[1][1] == 'o' &&
	   	gameBoard[2][2] == 'o')
	{
		return o_wins;
	}
	else if(gameBoard[0][2] == 'o' && 
	   		gameBoard[1][1] == 'o' &&
	   		gameBoard[2][0] == 'o')
	{
		return o_wins;
	}

	// If no winner check if board is full
	for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // If board not full, still in progress
            if(gameBoard[i][j] == '.')
            	return in_progress;
        }
    }

    // If full and there was no winner, game is draw
    return draw;
}

/************************************
 *            print    
 * Takes no parameters and prints
 * current game board to screen
 *************************************/

void Board::print()
{
	std::cout << std::endl << "  0 1 2 " << std::endl;
	// Loop through and print positions
	for(int i = 0; i < 3; i++)
	{
		std::cout << i << " ";
		for (int j = 0; j < 3; j++)
		{
			std::cout << gameBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

















