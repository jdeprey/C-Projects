/*********************************************************************
 * ** Author: Joseph DePrey
 * ** Date: 3/8/2016
 * ** Description: Project 10.a - TicTacToe Class Header File
 * **   Allows two people to play a game.  Has a field for a Board 
 * **   object and a field to keep track of which player's turn it is.
 * **   Has a constructor which takes a char parameter that specifies 
 * **   whether 'x' or 'o' has first move and a play method to start 
 * **   the game.  The play method keeps looping for each move until
 * **   someone wins or or the game is declared a draw.
3 of 4
 * *********************************************************************/
// Include guards to prevent header from being included more than once. 
#include "Board.hpp"
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include <iostream>
#include <string>
#include <cctype>

class TicTacToe
{
private:
	Board ourBoard;				// Board object
	char currentPlayer;			// Keep track of which player's turn it is

public:
	TicTacToe();				// Default constructor sets 'x' as first player
	TicTacToe(char);			// Constructor to specify whether 'x' or 'o' begins
	void play(); 				// Begins the game
};

#endif
