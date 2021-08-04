#ifndef _BOARD_H_
#define _BOARD_H_
#include "level.h"
#include "cell.h"
#include "blocks.h"
#include <vector>
using namespace std;

class Board {
	public:
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

