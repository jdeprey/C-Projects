/*********************************************************************
 * ** Author: Joseph DePrey
 * ** Date: 3/8/2016
 * ** Description: Project 10.a - Board Class Header File
 * **   Representing a tic-tac-toe board, Board have a 3x3 array as a 
 * **   data member to store the locations of players' moves, a method
 * **   to record the move and return true/false, a method to indicate
 * **   the state of the game, and a print method to print the current
 * **   board to the screen 
1 of 4
 * *********************************************************************/
// Include guards to prevent header from being included more than once. 
#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>

enum State {x_wins, o_wins, draw, in_progress}; // Represents state of game

class Board
{
private:
    char gameBoard[3][3];       	// 3x3 array for game board

public:
    Board();                    	 // Default constructor, initializes empty array
    bool makeMove(int, int, char);   // Takes x and y coordinates of move and char for player
    State gameState();				 // Returns enum for state of game
    void print();					 // Prints current board to screen
};

#endif
