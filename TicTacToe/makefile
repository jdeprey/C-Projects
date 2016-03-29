all: tttgame

tttgame: TicTacToe.o Board.o 
	g++ -g Board.o TicTacToe.o -o tttgame

TicTacToe.o: TicTacToe.cpp TicTacToe.hpp
	g++ -c TicTacToe.cpp

Board.o: Board.cpp Board.hpp
	g++ -c Board.cpp



clean:
	rm -f *.o