#ifndef _BOARD_H_
#define _BOARD_H_
#include "level.h"
#include "cell.h"
#include <vector>
#include <string>
using namespace std;

class Board {
		int level;
		int reserve = 3;
		int width = 11 ;
		int height = 15;
		char nextBlock = 'X';
		int score = 0;

		bool blind = false;
		bool heavy = false; 
		bool force = false;
		char forced;

	public:
		vector<vector<Cell>> theBoard;

		int boardLevel();
		void setBoardLevel(int l);

		int boardW();
		int boardH();

		char getNextB();
		void setNextB(char blk);

		int getScore();
		void setScore(int s);

		bool getBlind();
		void setBlind(bool b);
		bool getHeavy();
		void setHeavy(bool b);
		bool getForce();
		void setForce(bool b);
		char getForcedB();
		void setForcedB(char blk);

		void init();
		void reset();
		int checkRows();
		void bomb();
			
		void printBoard();
		friend std::ostream &operator<<(std::ostream &out, vector<Board*> boards);
};




#endif

