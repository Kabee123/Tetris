#ifndef _BOARD_H_
#define _BOARD_H_
#include "level.h"
#include "blocks.h"
#include <vector>
using namespace std;

class Board {
	protected:
		int width, height;
		vector<vector<Cell>> theBoard;
	public:
		void init(int width, int height);

		void printBoard();
}

#endif

