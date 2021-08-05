#ifndef _BOARD_H_
#define _BOARD_H_
#include "level.h"
#include "cell.h"
#include <vector>
#include <string>
using namespace std;

class Board {
<<<<<<< HEAD
	public:	
		bool heavy, blind, force;
		std::string forced;
=======
	public:
		bool heavy, blind, force;
        std::string forced;

>>>>>>> b59b1a08286e64185f213e6f76f168fdd171aed1
		int reserve = 3;
		int width = 11 ;
		int height = 15;
		vector<vector<Cell>> theBoard;

		char curBlock;
		char nextBlock;


		void init();
		int checkRows();
		void printBoard();
};

#endif

