#ifndef _BOARD_H_
#define _BOARD_H_
#include "level.h"
#include "cell.h"
#include <vector>
#include <string>
using namespace std;

class Board {
	public:	
		bool blind = false;
		bool heavy = false; 
		bool force = false;
		int level;
		char forced;
		int reserve = 3;
		int width = 11 ;
		int height = 15;
		vector<vector<Cell>> theBoard;
		char nextBlock = 'X';


		void init();
		int checkRows();
		void printBoard();
		void bomb();
};

#endif

