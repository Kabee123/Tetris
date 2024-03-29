
#ifndef _BOARD_H_
#define _BOARD_H_
#include "level.h"
#include "cell.h"
#include <vector>
#include <string>
#include <memory>
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
		//Level *levelGen;
		std::unique_ptr<Level> levelGen;
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

		void init(int lvl, string s);
		void reset(string s);
		int checkRows();
		void bomb();
			
		void printBoard();
		friend std::ostream &operator<<(std::ostream &out, vector<Board*> boards);
};




#endif

